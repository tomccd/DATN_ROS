import rclpy
from rclpy.node import Node
import pigpio
from custom_interfaces.msg import SetWeighIO, TerminateSys
from custom_interfaces.srv import InitSys
import sys
class myNode(Node):
    def __init__(self,name:str):
        super().__init__(name)
        #Create a server
        self.server_io_weigh = self.create_service(InitSys,"node_io_weigh",self.callBack)
        #Create a Subcriber
        self.subcriber_terminate = self.create_subscription(TerminateSys,"terminate",self.terminateMsg,10)
        #Create a Weigh Publisher
        self.publisher_weigh = self.create_publisher(SetWeighIO,"weigh_io",10)
        #Create Weigh Status
        self.weigh_status = False
        #Initalize pigio 
        self.pi = pigpio.pi()
        if not self.pi.connected:
            self.get_logger().error("---- Server Server Module_Input.node_io_weigh: Can't Initalize pigpio ----")
            rclpy.shutdown()
            exit(-1)
        # Define the GPIO_EN (PIN 17)
        self.GPIO_EN = 17
        # Define the GPIO_DISABLE (PIN 27)
        self.GPIO_DISABLE = 27
        #Create a timer
        self.timer_ = self.create_timer(0.35,self.checkIOStatus)
    def checkIOStatus(self):
        msg = SetWeighIO()
        try:
            #Trạng thái cảm biến kích hoạt cân
            enable_status = self.pi.read(self.GPIO_EN)
            #Trạng thái cảm biến ngừng kích hoạt cân
            disable_status = self.pi.read(self.GPIO_DISABLE)
            # time.sleep(0.5)
            self.get_logger().info(f"---- Server Server Module_Input.node_io_weigh: Enable PIN: {enable_status}. Disable PIN: {disable_status} ----")
            if enable_status == 0 and disable_status == 1:
                msg.status = True
                self.publisher_weigh.publish(msg)
                self.weigh_status = True
            elif self.weigh_status == True and enable_status == 1 and disable_status == 0:
                msg.status = False
                self.publisher_weigh.publish(msg)
                self.weigh_status = False #Reset
        except Exception as e:
            self.get_logger().error("---- Server Server Module_Input.node_io_weigh: Can't read IO ----")
            exit(-1)
    def callBack(self,req,res):
        self.get_logger().info(f"---- Server Module_Input.node_io_weigh: Receive Intialized Request: {req.a} ----")
        self.init_status = True
        res.b = "OK"
        return res
    def terminateMsg(self,msg):
        self.get_logger().info(f"---- Server Module_Input.node_io_weigh: Receive Message: {msg.a}. Bye Bye.... ----")
        rclpy.shutdown()
        self.pi.stop()
        sys.exit(-1)
def main(args=None):
    rclpy.init(args=args)
    node = myNode("node_io_weigh")
    rclpy.spin(node)

if __name__ == "__main__":
    main()