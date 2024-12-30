'''
********************************************
# Chương trình này được viết bởi tomccd (Nguyễn Huy Hoàng)
# Tên file: node_io_start_stop_pending.py
# Ngày sửa đổi gần nhất: 29/12/2024
********************************************

'''
import rclpy
import pigpio
from rclpy.node import Node
from custom_interfaces.msg import SetStartStopPending, TerminateSys
from custom_interfaces.srv import InitSys
import sys
class myNode(Node):
    def __init__(self,name:str):
        super().__init__(name)
        #Create a Server
        self.server_io_start_stop_pending = self.create_service(InitSys,"node_io_start_stop_pending",self.callBack)
        #Create a Terminate Subcriber
        self.subcriber_terminate = self.create_subscription(TerminateSys,"terminate",self.terminate_Msg,10)
        #Create a SetStartStopPending Publisher
        self.publisher_setStartStopPending = self.create_publisher(SetStartStopPending,"set_start_stop_pending",10)
        #Initalize pigio 
        self.pi = pigpio.pi()
        #Previous Status
        self.previous_status = []
        if not self.pi.connected:
            self.get_logger().error("---- Server Server Module_Input.node_io_start_stop_pending: Can't Initalize pigpio ----")
            rclpy.shutdown()
            exit(-1)
        #Define GPIO_Start
        self.GPIO_Start = 19
        self.GPIO_Pending = 4
        self.GPIO_Stop = 25
        #Define The List of Start,Stop,Pending
        self.list_gpio_status = []
        #Create a timer
        self.timer_ = self.create_timer(0.25,self.checkIOStatus)
    def checkIOStatus(self):
        #Reset the list of Start,Stop,Pending
        self.list_gpio_status.clear()
        #Trạng thái của GPIO_Start
        detect_Start = self.pi.read(self.GPIO_Start)
        detect_Pending = self.pi.read(self.GPIO_Pending)
        detect_Stop = self.pi.read(self.GPIO_Stop)
        self.list_gpio_status = [detect_Start,detect_Pending,detect_Stop]
        self.get_logger().info(f"---- Server Server Module_Input.node_io_start_stop_pending: Start PIN: {self.list_gpio_status[0]}. Pending PIN: {self.list_gpio_status[1]}.  Stop PIN: {self.list_gpio_status[2]}----")
        self.get_logger().info(f"---- Server Module_Input.node_io_start_stop_pending: Previous Input Status: {self.previous_status}")
        compare_status = (set(self.list_gpio_status) == set(self.previous_status))
        self.get_logger().info(f"---- Server Module_Input.node_io_start_stop_pending: Constraint Status: {compare_status}")
        #Nếu tổng trạng thái = 1 -> send Message
        if sum(self.list_gpio_status) == 1 and compare_status == False:
            msg = SetStartStopPending()
            if detect_Start == 1:
                msg.command = "Init"
            elif detect_Stop == 1:
                msg.command = "Stop"
            elif detect_Pending == 1:
                msg.command = "Pending"
                self.get_logger().info(f"---- Server Module_Input.node_io_start_stop_pending: Sending Pending Message")
            self.publisher_setStartStopPending.publish(msg)
        self.previous_status = self.list_gpio_status.copy()
        
    def callBack(self,req,res):
        self.get_logger().info(f"---- Server Module_Input.node_io_start_stop_pending: Receive Intialized Request: {req.a} ----")
        self.init_status = True
        res.b = "OK"
        return res
    def terminate_Msg(self,msg):
        self.get_logger().info(f"---- Server Module_Input.node_io_start_stop_pending: Receive Message: {msg.a}. Bye Bye.... ----")
        rclpy.shutdown()
        self.pi.stop()
        sys.exit(-1)
def main(args=None):
    #Initialize ROS2 Communcation
    rclpy.init(args=args)
    #Declare a Node
    node = myNode("node_io_start_stop_pending")
    #Spin
    rclpy.spin(node)

if __name__ == "__main__":
    main()