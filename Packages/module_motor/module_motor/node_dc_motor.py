'''
********************************************
# Chương trình này được viết bởi tomccd (Nguyễn Huy Hoàng)
# Tên file: node_dc_motor.py
# Ngày sửa đổi gần nhất: 29/12/2024
********************************************

'''
import rclpy
from rclpy.node import Node
import pigpio
from custom_interfaces.srv import InitSys
from custom_interfaces.msg import TerminateSys
import time
class myNode(Node):
    def __init__(self,name:str):
        super().__init__(name)
        #Start,Pending Status
        self.start_status = False
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
            #Init PIN as OUTPUT PIN
        self.pi.set_mode(self.PIN_IN_3,pigpio.OUTPUT)
        self.pi.set_mode(self.PIN_IN_4,pigpio.OUTPUT)
        
    def callBack(self,req,res):
        #Nếu nhấn nút Start
        if req.a == "Ready":
            self.get_logger().info(f"---- Server Module_Motor.node_dc_motor: Receive Intialized Request: {req.a} ----")
            # if self.init_status == False:
            # time.sleep(0.5)
                #Set FORWARD Mode Motor_1
            self.pi.write(self.PIN_IN_3,1)
            self.pi.write(self.PIN_IN_4,0)
                #Set FORWARD Mode Motor_2
            self.pi.write(self.PIN_IN_1,0)
            self.pi.write(self.PIN_IN_2,1)
                #Set PWM
            self.pi.set_PWM_dutycycle(self.PIN_MOTOR_1,int(0.35*255))
            self.pi.set_PWM_dutycycle(self.PIN_MOTOR_2,int(0.575*255))
                # self.init_status = True
            res.b = "OK"
            self.start_status = True
            return res
        #Nếu nhấn nút Pending (trạng thái chưa ấn Pending trước đó)
        elif req.a == "Pending":
            #Nếu trước đó đã khởi tạo hệ thống
            if self.start_status == True:
                self.get_logger().info(f"---- Server Module_Motor.node_dc_motor: Receive Pending Request: {req.a} ----")
                # if self.init_status == False:
                    #Init PIN as OUTPUT PIN
                # time.sleep(0.5)
                    #Set FORWARD Mode Motor_1
                self.pi.write(self.PIN_IN_3,1)
                self.pi.write(self.PIN_IN_4,0)
                    #Set FORWARD Mode Motor_2
                self.pi.write(self.PIN_IN_1,0)
                self.pi.write(self.PIN_IN_2,1)
                    #Set PWM
                self.pi.set_PWM_dutycycle(self.PIN_MOTOR_1,int(0*255))
                self.pi.set_PWM_dutycycle(self.PIN_MOTOR_2,int(0*255))
                    # self.init_status = True
                res.b = "OK"
                return res
            else:
                res.b = "Nope"
                return res
        #Nếu nhấn nút Pending (trạng thái đã nhấn Pending trước đó)
        elif req.a == "Resume":
            #Nếu trước đó đã khởi tạo hệ thống
            if self.start_status == True:
                self.get_logger().info(f"---- Server Module_Motor.node_dc_motor: Receive Resume Request: {req.a} ----")
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
                self.pi.set_PWM_dutycycle(self.PIN_MOTOR_1,int(0.35*255))
                self.pi.set_PWM_dutycycle(self.PIN_MOTOR_2,int(0.575*255))
                    # self.init_status = True
                res.b = "OK"
                return res
            else:
                res.b = "Nope"
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