from HX711 import *
import rclpy
from rclpy.node import Node
from custom_interfaces.msg import SetWeighIO, TerminateSys, WeighValue
from custom_interfaces.srv import InitSys
import threading
import time
import sys
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
        self.hx = SimpleHX711(2,3,-413, 579886,Rate.HZ_80)
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
        self.get_logger().info(f"---- Server Module Weigh Receive Message: {self.message.status} ----")
        if self.message.status is True:
            self.weigh_Event.set()
            weigh_thread = threading.Thread(target=self.implement_Weigh)
            # self.get_logger().info(f"---- Server Module Weigh: {threading.active_count()} ----")
            if threading.active_count() < 2:
                weigh_thread.daemon = True
                weigh_thread.start()
        else:
            self.weigh_Event.clear()
    def implement_Weigh(self):
        while self.weigh_Event.is_set() == True:
            self.list_of_value.append(round(float(self.hx.weight()),2))
            time.sleep(0.25)
        #Finding the max
        if len(self.list_of_value) > 0 and self.message is not None:
            msg = WeighValue()
            # Lấy giá trị trung bình cân và làm tròn
            msg.value = round(sum(self.list_of_value)/len(self.list_of_value),2)
            self.get_logger().info(f"--- Server Module_Weigh Max: {max(self.list_of_value)}")
            self.publisher_weigh.publish(msg=msg)
            self.list_of_value.clear()
    def terminateMsg(self,msg):
        self.get_logger().info(f"---- Server Module_Weigh: Receive Message: {msg.a}. Bye Bye.... ----")
        self.weigh_Event.clear()
        rclpy.shutdown()
        sys.exit(-1)
def main(args=None):
    rclpy.init(args=args)
    node = myNode("module_weigh")
    rclpy.spin(node)

if __name__ == "__main__":
    main()