from HX711 import *
import rclpy
from rclpy.node import Node
from custom_interfaces.msg import SetWeighIO, TerminateSys, WeighValue
from custom_interfaces.srv import InitSys
import threading
from datetime import timedelta
class myNode(Node):
    def __init__(self,name:str):
        super().__init__(name)
        #Create a server
        self.server_weigh = self.create_service(InitSys,"module_weigh",self.callBack)
        #Create a terminate subcriber
        self.subcriber_terminate =  self.create_subscription(TerminateSys,"terminate",self.terminateMsg,10)
        #Create a weigh publisher
        self.publisher_weigh = self.create_publisher(WeighValue,"get_weigh",10)
        #Create a io subcriber
        self.subcriber_io = self.create_subscription(SetWeighIO,"weigh_io",self.receiveIOStatus,10)
        #Init HX711
        self.hx = SimpleHX711(2,3,582527)
        #Set Unit
        self.hx.setUnit(Mass.Unit.G)
        #Create a weigh Event
        self.weigh_Event = threading.Event()
        #Create a List of Value
        self.list_of_value = []
        #Message
        self.message = None
    def callBack(self,req,res):
        self.get_logger().info(f"---- Server Module_Weigh: Receive Intialized Request: {req.a} ----")
        self.init_status = True
        res.b = "OK"
        return res
    def receiveIOStatus(self,msg):
        self.message = msg
        if self.weigh_Event.is_set() == False:
            self.weigh_Event.set()
            thread = threading.Thread(self.implement_Weigh)
            thread.start()
    def implement_Weigh(self):
        while self.message.status == True:
            self.list_of_value.append(self.hx.weight(timedelta(seconds=1)))
        #Finding the max
        if len(self.list_of_value) > 0:
            self.get_logger().info(f"--- Server Module_Weigh: {self.list_of_value}")
            self.weigh_Event.clear()
            self.list_of_value.clear()
    def terminateMsg(self,msg):
        self.get_logger().info(f"---- Server Module_Weigh: Receive Message: {msg.a}. Bye Bye.... ----")
        rclpy.shutdown()
        exit(-1)
def main(args=None):
    rclpy.init(args=args)
    node = myNode("module_weigh")
    rclpy.spin(node)

if __name__ == "__main__":
    main()