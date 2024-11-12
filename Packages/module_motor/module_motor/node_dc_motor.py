import rclpy
from rclpy.node import Node
import pigpio
from custom_interfaces.srv import InitSys
from custom_interfaces.msg import TerminateSys
import time
class myNode(Node):
    def __init__(self,name:str):
        super().__init__(name)
        #Declare a Server
        self.server_dc_motor = self.create_service(InitSys,"node_dc_motor",self.callBack)
        #Declare a terminate Client
        self.subcriber_terminate = self.create_subscription(TerminateSys,"terminate",self.terminateMsg,10)
        #Initalize pigio 
        self.pi = pigpio.pi()
        if not self.pi.connected:
            self.get_logger().error("---- Server Server Module_Motor.node_dc_motor: Can't Initalize pigpio ----")
            rclpy.shutdown()
            exit(-1)
        #Define IN_3 (Motor 1)
        self.PIN_IN_3 = 5
        #Define IN_4 (Motor 1)
        self.PIN_IN_4 = 6
        #Define IN_1
        self.PIN_IN_1 = 20
        self.PIN_IN_2 = 21
        #Define Motor PIN (Motor 1)
        self.PIN_MOTOR_1 = 12
        self.PIN_MOTOR_2 = 13
        
    def callBack(self,req,res):
        self.get_logger().info(f"---- Server Module_Motor.node_dc_motor: Receive Intialized Request: {req.a} ----")
        # if self.init_status == False:
            #Init PIN as OUTPUT PIN
        self.pi.set_mode(self.PIN_IN_3,pigpio.OUTPUT)
        self.pi.set_mode(self.PIN_IN_4,pigpio.OUTPUT)
        # time.sleep(0.5)
            #Set FORWARD Mode Motor_1
        self.pi.write(self.PIN_IN_3,1)
        self.pi.write(self.PIN_IN_4,0)
            #Set FORWARD Mode Motor_2
        self.pi.write(self.PIN_IN_1,0)
        self.pi.write(self.PIN_IN_2,1)
            #Set PWM
        self.pi.set_PWM_dutycycle(self.PIN_MOTOR_1,int(0.6*255))
        self.pi.set_PWM_dutycycle(self.PIN_MOTOR_2,int(0.6*255))
            # self.init_status = True
        res.b = "OK"
        return res
    
    def terminateMsg(self,msg):
        self.get_logger().info(f"---- Server Module_Motor.node_dc_motor: Receive Message: {msg.a}. Bye Bye.... ----")
        #Reset PWM
        self.pi.set_PWM_dutycycle(self.PIN_MOTOR_1,0)
        self.pi.set_PWM_dutycycle(self.PIN_MOTOR_2,0)
        time.sleep(0.5)
        #Stop Pigpio instance
        self.pi.stop()
        rclpy.shutdown()
        exit(-1)
def main(args=None):
    rclpy.init(args=args)
    #Create a Node
    node = myNode("node_dc_motor")
    #Spin
    rclpy.spin(node)
if __name__ == "__main__":
    main()