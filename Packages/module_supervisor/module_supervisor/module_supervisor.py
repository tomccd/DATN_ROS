'''
********************************************
# Chương trình này được viết bởi tomccd (Nguyễn Huy Hoàng)
# Tên file: module_supervisor.py
# Ngày sửa đổi gần nhất: 29/12/2024
********************************************

'''
from custom_interfaces.srv import InitSys
from custom_interfaces.msg import TerminateSys, SetStartStopPending
import rclpy
from rclpy.node import Node

class myNode(Node):
    def __init__(self,name:str):
        super().__init__(name)
        #start,Pending Status
        self.start_status = False
        self.pending_status = False
        #Initialize Client
        self.client_mci = self.create_client(InitSys,"module_scanning_interface")
        self.client_io_weigh = self.create_client(InitSys,"node_io_weigh")
        self.client_mw = self.create_client(InitSys,"module_weigh")
        self.client_dc_motor = self.create_client(InitSys,"node_dc_motor")
        self.client_log_file = self.create_client(InitSys,"module_log_file")
        self.client_io_servo = self.create_client(InitSys,"node_io_servo")
        self.client_dc_servo = self.create_client(InitSys,"node_dc_servo")
        self.client_memail = self.create_client(InitSys,"module_send_email")
        self.client_io_start_stop_pending = self.create_client(InitSys,"node_io_start_stop_pending")
        #Init Publisher
        self.publisher_terminate = self.create_publisher(TerminateSys,"terminate",10)
        #Init Subcriber of node_start_stop_pending
        self.subcriber_setStartStopPending = self.create_subscription(SetStartStopPending,"set_start_stop_pending",self.receiveIO_StartStopPending,10)
        #Init status
        init_status = self.initSystem()
        if init_status == -1:
            self.get_logger().error("---- Supervisor: Initilize System Error ----")
            self.sendTerminate()
            rclpy.shutdown()
        else:
            self.timer_ = self.create_timer(2,self.checkStatus)
    def receiveIO_StartStopPending(self,msg):
        if msg.command == "Init":
            #Chỉ khởi động đúng 1 lần => Phòng trường hợp spam nút nhấn Start
            if self.start_status == False:
                self.start_status = True
                self.send_ReqSys("Ready")
            return 0
        elif msg.command == "Pending":
            #Nếu trước đó chưa pending
            if self.pending_status == False:
                self.pending_status = True
                self.send_ReqSys("Pending")
                return 0
            #Nếu trước đó đã pending (cần resume)
            elif self.pending_status == True:
                self.pending_status = False
                self.send_ReqSys("Resume")
                return 0
        elif msg.command == "Stop":
            self.sendTerminate()
            rclpy.shutdown()
            exit(-1)
        
    def initSystem(self):
        time_counter = 0
        #Connect to server module_log_file
        while not self.client_log_file.wait_for_service(1):
            self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Log_File ----")
            if time_counter > 4:
                break
            time_counter +=1
        if time_counter > 4:
            self.get_logger().error("---- Supevisor: Can't connect to server Module_Log_File ----")
            return -1
        else:
            self.get_logger().info("---- Supervisor: Connect to Server Module_Log_File Successfully ----")
            time_counter = 0
            #Connect to server_module_scanning_interface (Try to connect for 2 seconds)
            while not self.client_mci.wait_for_service(1):
                self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Scanning&Interface ----")
                if time_counter > 75:
                    break
                time_counter+=1
            if time_counter > 75:
                self.get_logger().error("---- Supervisor: Can't connect to server Module_Scanning&Interface ----")
                return -1
            else:
                self.get_logger().info("---- Supervisor: Connect to Server Module_Scanning&Interface Successfully ----")
                time_counter = 0 #rest time_counter
                #Connect to server_node_io_weigh (Try to connect for 2 seconds)
                while not self.client_io_weigh.wait_for_service(1):
                    self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Input.node_io_weigh ----")
                    if time_counter > 4:
                        break
                    time_counter+=1
                if time_counter > 4:
                    self.get_logger().error("---- Supervisor: Can't connect to server Module_Input.node_io_weigh ----")
                    return -1
                else:
                    self.get_logger().info("---- Supervisor: Connect to Server Module_Input.node_io_weigh Successfully ----")
                    time_counter = 0 #rest time_counter
                    while not self.client_mw.wait_for_service(1):
                        self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Weigh ----")
                        if time_counter > 4:
                            break
                        time_counter+=1
                    if time_counter > 4:
                        self.get_logger().error("---- Supervisor: Can't connect to server Module_Weigh ----")
                        return -1
                    self.get_logger().info("---- Supervisor: Connect to Server Module_Weigh Successfully ----")
                    time_counter = 0
                    while not self.client_dc_motor.wait_for_service(1):
                        self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Motor.node_dc_motor ----")
                        if time_counter > 4:
                            break
                        time_counter+=1
                    if time_counter > 4:
                        self.get_logger().error("---- Supervisor: Can't connect to server Module_Motor.node_dc_motor ----")
                        return -1
                    else:
                        self.get_logger().info("---- Supervisor: Connect to Server Module_Motor.node_dc_motor Successfully ----")
                        time_counter = 0
                        while not self.client_io_servo.wait_for_service(1):
                            self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Input.node_io_motor ----")
                            if time_counter > 4:
                                break
                            time_counter +=1
                        if time_counter > 4:
                            self.get_logger().error("---- Supervisor: Can't connect to server Module_Input.node_io_servo ----")
                            return -1
                        else:
                            self.get_logger().info("---- Supervisor: Connect to Server Module_Input.node_io_servo Successfully ----")
                            time_counter = 0
                            while not self.client_dc_servo.wait_for_service(1):
                                self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Motor.node_dc_servo ----")
                                if time_counter > 4:
                                    break
                                time_counter +=1
                            if time_counter > 4:
                                self.get_logger().error("---- Supervisor: Can't connect to server Module_Motor.node_dc_servo ----")
                                return -1
                            else:    
                                self.get_logger().info("---- Supervisor: Connect to Server Module_Motor.node_dc_servo Successfully ----")
                                time_counter = 0
                                while not self.client_memail.wait_for_service(1):
                                    self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Send_Email ----")
                                    if time_counter > 50:
                                        break
                                    time_counter +=1
                                if time_counter > 50:
                                    self.get_logger().error("---- Supervisor: Can't connect to server Module_Send_Email ----")
                                    return -1
                                else:
                                    self.get_logger().info("---- Supervisor: Connect to Server Module_Send_Email Successfully ----")
                                    time_counter = 0
                                    while not self.client_io_start_stop_pending.wait_for_service(1):
                                        self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Input.node_io_start_stop_pending ----")
                                        if time_counter > 4:
                                            break
                                        time_counter+=1
                                    if time_counter > 4:
                                        self.get_logger().error("---- Supervisor: Can't connect to server Module_Input.node_io_start_stop_pending ----")
                                        return -1
                                    self.get_logger().info("---- Supervisor: Connect to Server Module_Input.node_io_start_stop_pending Successfully ----")
                                    #To be continue (May be we will have some modules)
                                    return 0
                                    # #Send Request
                                    # req = InitSys.Request()
                                    # req.a = "Ready"
                                    # future = self.client_dc_motor.call_async(req)
                                    # rclpy.spin_until_future_complete(self,future,timeout_sec=2)
                                    # try:
                                    #     rs = future.result()
                                    #     self.get_logger().info(f"---- Supervisor: Receive Init Respond from Server Module_Motor.node_dc_motor: {rs.b}")
                                    #     return 0
                                    # except Exception as e:
                                    #     self.get_logger().error(f"---- Supervisor: Can't send request to Module_Motor.node_dc_motor with error: {e} ----")
                                    #     return -1
    def send_ReqSys(self,reqContent:str):
        #Send Request
        req = InitSys.Request()
        req.a = reqContent
        #Send to Server Module_Scanning&Interface
        self.get_logger().info(f"---- Supervisor: Sending {reqContent} Request to Server_Module_Scanning&Interface ----")
        future = self.client_mci.call_async(req)
        rclpy.spin_until_future_complete(self,future,timeout_sec=1)
        try:
            rs = future.result()
            self.get_logger().info(f"---- Supervisor: Receive {reqContent} Respond from Server Module_Scanning&Interface ----")
                #Send to Server Module_Motor.node_dc_motor
            self.get_logger().info(f"---- Supervisor: Sending {reqContent} Request to Server Module_Motor.node_dc_motor ----")
            future = self.client_dc_motor.call_async(req)
            rclpy.spin_until_future_complete(self,future,timeout_sec=1)
            try:
                rs = future.result()
                self.get_logger().info(f"---- Supervisor: Receive {reqContent} Respond from Server Module_Motor.node_dc_motor ----")
                #Send to Server Module_Motor.node_dc_servo
                self.get_logger().info(f"---- Supervisor: Sending {reqContent} Request to Server Module_Motor.node_dc_servo ----")
                future = self.client_dc_servo.call_async(req)
                rclpy.spin_until_future_complete(self,future,timeout_sec=1)
                try:
                    rs = future.result()
                    self.get_logger().info(f"---- Supervisor: Receive {reqContent} Respond from Server Module_Motor.node_dc_servo ----")
                    #Send to Server Module_Input.node_io_servo
                    self.get_logger().info(f"---- Supervisor: Sending {reqContent} Request to Server Module_Input.node_io_servo ----")
                    future = self.client_io_servo.call_async(req)
                    rclpy.spin_until_future_complete(self,future,timeout_sec=1)
                    try:
                        rs = future.result()
                        self.get_logger().info(f"---- Supervisor: Receive {reqContent} Respond from Server Module_Input.node_io_servo ----")
                        #Send to Server Module_Input.node_io_weigh
                        self.get_logger().info(f"---- Supervisor: Sending {reqContent} Request to Server Module_Input.node_io_weigh ----")
                        future = self.client_io_weigh.call_async(req)
                        rclpy.spin_until_future_complete(self,future,timeout_sec=1)
                        try:
                            rs = future.result()
                            self.get_logger().info(f"---- Supervisor: Receive {reqContent} Respond from Server Module_Input.node_io_weigh ----")
                        except Exception as e:
                            self.get_logger().error(f"---- Supervisor: Can't send Request {reqContent} to Module_Input.node_io_weigh with error: {e} ----")
                            self.sendTerminate()
                            rclpy.shutdown()
                            exit(-1)
                    except Exception as e:
                        self.get_logger().error(f"---- Supervisor: Can't send Request {reqContent} to Module_Input.node_io_servo with error: {e} ----")
                        self.sendTerminate()
                        rclpy.shutdown()
                        exit(-1)
                except Exception as e:
                    self.get_logger().error(f"---- Supervisor: Can't send Request {reqContent} to Module_Motor.node_dc_servo with error: {e}")
                    self.sendTerminate()
                    rclpy.shutdown()
                    exit(-1)
            except Exception as e:
                self.get_logger().error(f"---- Supervisor: Can't send Request {reqContent} to Module_Motor.node_dc_motor with error: {e}")
                self.sendTerminate()
                rclpy.shutdown()
                exit(-1)
        except Exception as e:
            self.get_logger().error(f"---- Supervisor: Can't send Request {reqContent} to Module_Scanning&Interface with error: {e} ----")
            self.sendTerminate()
            rclpy.shutdown()
            exit(-1)
        
    def sendTerminate(self):        
        msg = TerminateSys()
        msg.a = "Terminate"
        self.publisher_terminate.publish(msg)
        
    def checkStatus(self):
        time_counter = 0
        #Connect to server_module_scanning_interface (Try to connect for 2 seconds)
        while not self.client_mci.wait_for_service(1):
            self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Scanning&Interface ----")
            if time_counter > 3:
                break
            time_counter+=1
        if time_counter > 3:
            self.get_logger().error("---- Supervisor: Can't connect to Module Scanning&Interface ----")
            self.sendTerminate()
            rclpy.shutdown()
            exit(-1)
        else:
            self.get_logger().info("---- Supervisor: Connect to Module_Scanning&Interface Successfully----")
            time_counter = 0
            while not self.client_io_weigh.wait_for_service(1):
                self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Input.node_io_weigh ----")
                if time_counter > 3:
                    break
                time_counter +=1
            if time_counter > 3:
                self.get_logger().error("---- Supervisor: Can't connect to server Module_Input.node_io_weigh ----")
                self.sendTerminate()
                rclpy.shutdown()
                exit(-1)
            else:
                self.get_logger().info("---- Supervisor: Connect to Module_Input.node Successfully----")
                time_counter = 0 #rest time_counter
                while not self.client_mw.wait_for_service(1):
                    self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Weigh ----")
                    if time_counter > 3:
                        break
                    time_counter +=1
                if time_counter > 3:
                    self.get_logger().error("---- Supervisor: Can't connect to server Module_Weigh ----")
                    self.sendTerminate()
                    rclpy.shutdown()
                    exit(-1)
                self.get_logger().info("---- Supervisor: Connect to Module_Weigh Successfully----")
                time_counter = 0
                while not self.client_dc_motor.wait_for_service(1):
                    self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Motor.node_dc_motor ----")
                    if time_counter > 3:
                        break
                    time_counter+=1
                if time_counter > 3:
                    self.get_logger().error("---- Supervisor: Can't connect to server Module_Motor.node_dc_motor ----")
                    self.sendTerminate()
                    rclpy.shutdown()
                    exit(-1)
                self.get_logger().info("---- Supervisor: Connect to Module_Motor.node_dc_motor Successfully----")
                time_counter = 0
                while not self.client_io_servo.wait_for_service(1):
                    self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Input.node_io_servo ----")
                    if time_counter > 3:
                        break
                    time_counter +=1
                if time_counter > 3:
                    self.get_logger().error("---- Supervisor: Can't connect to server Module_Input.node_io_servo ----")
                    self.sendTerminate()
                    rclpy.shutdown()
                    exit(-1)
                self.get_logger().info("---- Supervisor: Connect to Module_Input.node_io_servo Successfully----")
                time_counter = 0
                while not self.client_memail.wait_for_service(1):
                    self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Send_Email ----")
                    if time_counter > 3:
                        break
                    time_counter +=1
                if time_counter > 3:
                    self.get_logger().error("---- Supervisor: Can't connect to server Module_Send_Email ----")
                    self.sendTerminate()
                    rclpy.shutdown()
                    exit(-1)
                self.get_logger().info("---- Supervisor: Connect to Module_Send_Email Successfully----")
                time_counter = 0
                while not self.client_io_start_stop_pending.wait_for_service(1):
                    self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Input.node_io_start_stop_pending ----")
                    if time_counter > 3:
                        break
                    time_counter +=1
                if time_counter > 3:
                    self.get_logger().info("---- Supervisor: Can't connect to server Module_Input.node_io_start_stop_pending ----")
                    self.sendTerminate()
                    rclpy.shutdown()
                    exit(-1)
                self.get_logger().info("---- Supervisor: Connect to Module_Input.node_io_start_stop_pending Successfully ----")
def main(args=None):
    #Initlize ROS2 Communication
    rclpy.init(args=args)
    #Declare a Node
    node = myNode("Module_Supervisor")
    #Catching KeyboardInterrupt Event
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.sendTerminate()
        node.get_logger().info("---- Supervisor: Terminate Session ----")
        rclpy.shutdown()
        exit(-1)

if __name__ == "__main__":
    main()