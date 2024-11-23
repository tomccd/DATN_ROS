import rclpy
from rclpy.node import Node
from custom_interfaces.msg import TerminateSys, SetServoRotate
from custom_interfaces.srv import InitSys
import sys
import pigpio
import time
import threading
class myNode(Node):
    def __init__(self,name:str):
        super().__init__(name)
        #Status Rotate
        self.rotate_status = False
        #Create a Server
        self.server_servo_motor = self.create_service(InitSys,"node_dc_servo",self.callBack)
        self.get_logger().info("---- Server Module_Motor.node_dc_motor: Init Server ----")
        #Create a Terminate Subcriber
        self.subcriber_terminate = self.create_subscription(TerminateSys,"terminate",self.terminateMsg,10)
        #Create a Subcriber Rotate
        self.subcriber_rotate_servo = self.create_subscription(SetServoRotate,"rotate_servo",self.setActuator,10)
        #Initalize pigio 
        self.pi = pigpio.pi()
        if not self.pi.connected:
            self.get_logger().error("---- Server Server Module_Input.node_io_servo: Can't Initalize pigpio ----")
            rclpy.shutdown()
            exit(-1)
        #Define PULSE_PIN_TBDT
        self.PULSE_PIN_TBDT = 10
        #Define PULSE_PIN_QA
        self.PULSE_PIN_QA = 9
        #Define PULSE_PIN_DIFF
        self.PULSE_PIN_Diff = 11
        try:
            #-Init Servo
            self.pi.set_servo_pulsewidth(self.PULSE_PIN_TBDT,self.degrees_to_pwm(9)) #5 -> 8 -> 9
            time.sleep(0.5)
            self.pi.set_servo_pulsewidth(self.PULSE_PIN_QA,self.degrees_to_pwm(39)) #30 -> 40 -> 39
            time.sleep(0.5)
            self.pi.set_servo_pulsewidth(self.PULSE_PIN_Diff,self.degrees_to_pwm(141)) #145 -> 140 -> 142
            time.sleep(0.5)
        except Exception as e:
            self.get_logger().error(f"---- Servo Module_Motor.node_servo_motor: Can't Rotate Servo. Error: {e}")
            rclpy.shutdown()
            self.pi.stop()
            time.sleep(0.5)
            sys.exit(-1)
        else:
            #Create a timer
            pass
    #Quay Servo khi phân loại theo pin
    def rotateServo_Distinguish(self,pin):
        if pin == self.PULSE_PIN_TBDT:
            #Thiết lập servo quay về vị trí ban đầu
            try:
                self.pi.set_servo_pulsewidth(pin,self.degrees_to_pwm(10))
                self.rotate_status = True
                time.sleep(2) #6.5
            except Exception as e:
                self.get_logger().error(f"---- Server Module_Motor.node_servo_motor can't rotate at Servo 1st. Error: {e} ----")
                self.rotate_status = False
        elif pin  == self.PULSE_PIN_QA:
            #Thiết lập servo quay về vị trí ban đầu
            try:
                self.pi.set_servo_pulsewidth(pin,self.degrees_to_pwm(40))
                self.rotate_status = True
                time.sleep(2)
            except Exception as e:
                self.get_logger().error(f"---- Server Module_Motor.node_servo_motor can't rotate at Servo 2nd. Error: {e} ----")
                self.rotate_status = False
    #Quay Servo khi tránh vật theo pin
    def rotateServo_Avoid(self,pin):
        if pin == self.PULSE_PIN_TBDT:
            try:
                #Tránh vật
                self.pi.set_servo_pulsewidth(pin,self.degrees_to_pwm(60))
                time.sleep(1.75)
                try:
                    #Thiết lập servo quay về vị trí ban đầu
                    self.pi.set_servo_pulsewidth(pin,self.degrees_to_pwm(8))
                    self.rotate_status = True
                    
                    time.sleep(1.75)
                except Exception as e:
                    self.get_logger().error(f"---- Server Module_Motor.node_servo_motor can't rotate at Servo 1st. Error: {e} ----")
                    self.rotate_status = False
            except Exception as e:
                self.get_logger().error(f"---- Server Module_Motor.node_servo_motor can't rotate at Servo 1st. Error: {e} ----")
                self.rotate_status = False
        elif pin == self.PULSE_PIN_QA:
            try:
                #Tránh vật
                self.pi.set_servo_pulsewidth(pin,self.degrees_to_pwm(95))
                time.sleep(1.75)
                try:
                    #Thiết lập servo quay về vị trí ban đầu
                    self.pi.set_servo_pulsewidth(pin,self.degrees_to_pwm(40))
                    self.rotate_status = True
                    time.sleep(1.75)
                except Exception as e:
                    self.get_logger().error(f"---- Server Module_Motor.node_servo_motor can't rotate at Servo 2nd. Error: {e} ----")
                    self.rotate_status = False
            except Exception as e:
                self.get_logger().error(f"---- Server Module_Motor.node_servo_motor can't rotate at Servo 2nd. Error: {e} ----")
                self.rotate_status = False
            
    def setActuator(self,msg):
        #Tìm chuỗi nhỏ
        if msg.rotatemsg.find("YES") != -1:
            if msg.rotatemsg.find("1") != -1:
                self.get_logger().info("---- Node_DC_Servo: Rotate Servo TBDT DSG ----")
                thread_rotate = threading.Thread(target=self.rotateServo_Distinguish,args=(self.PULSE_PIN_TBDT,))
                thread_rotate.daemon = True
                thread_rotate.start()
            elif msg.rotatemsg.find("2") != -1:
                self.get_logger().info("---- Node_DC_Servo: Rotate Servo QA DSG ----")
                thread_rotate = threading.Thread(target=self.rotateServo_Distinguish,args=(self.PULSE_PIN_QA,))
                thread_rotate.daemon = True
                thread_rotate.start()
        elif msg.rotatemsg.find("NO") != -1:
            if msg.rotatemsg.find("1") != -1:
                self.get_logger().info("---- Node_DC_Servo: Rotate Servo TBDT AVD ----")
                thread_rotate = threading.Thread(target=self.rotateServo_Avoid,args=(self.PULSE_PIN_TBDT,))
                thread_rotate.daemon = True
                thread_rotate.start()
            elif msg.rotatemsg.find("2") != -1:
                self.get_logger().info("---- Node_DC_Servo: Rotate Servo QA AVD ----")
                thread_rotate = threading.Thread(target=self.rotateServo_Avoid,args=(self.PULSE_PIN_QA,))
                thread_rotate.daemon = True
                thread_rotate.start()
    # Function to convert degrees to PWM pulse width
    def degrees_to_pwm(self,degrees):
        pulse_width = 500 + (degrees / 180.0) * 2000  # Adjust for your servo's range
        return int(pulse_width)
    def callBack(self,req,res):
        self.get_logger().info(f"---- Server Module_Motor.node_servo_motor: Receive Intialized Request: {req.a} ----")
        self.init_status = True
        res.b = "OK"
        return res
    def terminateMsg(self,msg):
        self.get_logger().info(f"---- Server Module_Motor.node_servo_motor: Receive Message: {msg.a}. Bye Bye.... ----")
        rclpy.shutdown()
        #Reset pin
        self.pi.set_servo_pulsewidth(self.PULSE_PIN_TBDT,0)
        self.pi.set_servo_pulsewidth(self.PULSE_PIN_QA,0)
        self.pi.set_servo_pulsewidth(self.PULSE_PIN_Diff,0)
        self.pi.stop()
        time.sleep(0.5)
        sys.exit(-1)
def main(args=None):
    rclpy.init(args=args)
    #Create a Node
    node =  myNode("node_servo_motor")
    #Spin
    rclpy.spin(node)

if  __name__ == "__main__":
    main()