import rclpy
from rclpy.node import Node
import pigpio
from custom_interfaces.msg import TerminateSys, SetServoIO
from custom_interfaces.srv import InitSys
import sys
import time
class myNode(Node):
    def __init__(self,name:str):
        super().__init__(name)
        #Create a Server
        self.server_io_servo = self.create_service(InitSys,"node_io_servo",self.callBack)
        #Create a Terminate Subcriber
        self.subcriber_terminate =  self.create_subscription(TerminateSys,"terminate",self.terminate_Msg,10)
        #Create a Publisher
        self.publisher_servo = self.create_publisher(SetServoIO,"servo_io",10)
        #Initalize pigio 
        self.pi = pigpio.pi()
        if not self.pi.connected:
            self.get_logger().error("---- Server Server Module_Input.node_io_servo: Can't Initalize pigpio ----")
            rclpy.shutdown()
            exit(-1)
        #Define GPIO_CB_TBDT
        self.GPIO_CB_TBDT = 23
        #Define GPIO_CB_QA
        self.GPIO_CB_QA = 24
        #Define GPIO_CB_Diff
        self.GPIO_CB_Diff = 16
        #Create a timer
        self.timer_ = self.create_timer(0.25,self.checkIOStatus)
    def callBack(self,req,res):
        self.get_logger().info(f"---- Server Module_Input.node_io_servo: Receive Intialized Request: {req.a} ----")
        self.init_status = True
        res.b = "OK"
        return res
    def checkIOStatus(self):
        msg = SetServoIO()
        try:
            #Trạng thái cảm biến TBDT
            detect_TBDT = self.pi.read(self.GPIO_CB_TBDT)
            #Trạng thái cảm biến QA
            detect_QA  = self.pi.read(self.GPIO_CB_QA)
            #Trạng thái cảm biến khác
            detect_diff = self.pi.read(self.GPIO_CB_Diff)
            self.get_logger().info(f"---- Server Server Module_Input.node_io_servo: TBDT PIN: {detect_TBDT}. QA PIN: {detect_QA}.  Diff PIN: {detect_diff}----")
            if detect_TBDT == 0 and detect_QA == 1 and detect_diff == 1:
                msg.iomsg = "Thiet bi dien tu"
                self.publisher_servo.publish(msg)
            elif detect_TBDT == 1 and detect_QA == 0 and detect_diff == 1:
                msg.iomsg = "Quan ao"
                self.publisher_servo.publish(msg)
            elif detect_TBDT == 1 and detect_QA == 1 and detect_diff == 0:
                msg.iomsg = "Khac"
                self.publisher_servo.publish(msg)
        except Exception as e:
            self.get_logger().error(f"---- Server Server Module_Input.node_io_error: Can't read IO. Error {e} ----")
            self.pi.stop()
            rclpy.shutdown()
            exit(-1)    
    def terminate_Msg(self,msg):
        self.get_logger().info(f"---- Server Module_Input.node_io_servo: Receive Message: {msg.a}. Bye Bye.... ----")
        rclpy.shutdown()
        self.pi.stop()
        sys.exit(-1)
def main(args=None):
    rclpy.init(args=args)
    #Create a Node
    node = myNode("node_io_servo")
    #Spin
    rclpy.spin(node)
if  __name__ == "__main__":
    main()