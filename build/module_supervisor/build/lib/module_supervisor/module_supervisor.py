from custom_interfaces.srv import InitSys
from custom_interfaces.msg import TerminateSys
import rclpy
from rclpy.node import Node

class myNode(Node):
    def __init__(self,name:str):
        super().__init__(name)
        #Initialize Client
        self.client_mci = self.create_client(InitSys,"module_scanning_interface")
        self.client_io_weigh = self.create_client(InitSys,"node_io_weigh")
        self.client_mw = self.create_client(InitSys,"module_weigh")
        self.client_dc_motor = self.create_client(InitSys,"node_dc_motor")
        #Init Publisher
        self.publisher_terminate = self.create_publisher(TerminateSys,"terminate",10)
        #Init status
        init_status = self.initSystem()
        if init_status == -1:
            self.get_logger().error("---- Supervisor: Initilize System Error ----")
            self.sendTerminate()
            rclpy.shutdown()
        else:
            self.timer_ = self.create_timer(2,self.checkStatus)
    def initSystem(self):
        time_counter = 0
        #Connect to server_module_scanning_interface (Try to connect for 2 seconds)
        while not self.client_mci.wait_for_service(1):
            self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Scanning&Interface ----")
            if time_counter > 2:
                break
            time_counter+=1
        if time_counter > 2:
            self.get_logger().error("---- Supervisor: Can't connect to server Module_Scanning&Interface ----")
            return -1
        else:
            self.get_logger().info("---- Supervisor: Connect to Server Module_Scanning&Interface Successfully ----")
            time_counter = 0 #rest time_counter
            #Connect to server_node_io_weigh (Try to connect for 2 seconds)
            while not self.client_io_weigh.wait_for_service(1):
                self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Input.node_io_weigh ----")
                if time_counter > 2:
                    break
                time_counter+=1
            if time_counter > 2:
                self.get_logger().error("---- Supervisor: Can't connect to server Module_Input.node_io_weigh ----")
                return -1
            else:
                self.get_logger().info("---- Supervisor: Connect to Server Module_Input.node_io_weigh Successfully ----")
                time_counter = 0 #rest time_counter
                while not self.client_mw.wait_for_service(1):
                    self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Weigh ----")
                    if time_counter > 2:
                        break
                    time_counter+=1
                if time_counter > 2:
                    self.get_logger().error("---- Supervisor: Can't connect to server Module_Weigh ----")
                    return -1
                self.get_logger().info("---- Supervisor: Connect to Server Module_Weigh Successfully ----")
                time_counter = 0
                while not self.client_dc_motor.wait_for_service(1):
                    self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Motor.node_dc_motor ----")
                    if time_counter > 2:
                        break
                    time_counter+=1
                if time_counter > 2:
                    self.get_logger().error("---- Supervisor: Can't connect to server Module_Motor.node_dc_motor ----")
                    return -1
                #To be continue (May be we will have some modules)
                #---
                self.get_logger().info("---- Supervisor: Connect to Server Module_Motor.node_dc_motor Successfully ----")
                rq = InitSys.Request()
                rq.a = "Ready"
                self.get_logger().warn("----Supervisor: Sending Request to Server Module_Scanning&Interface...----")
                future = self.client_mci.call_async(rq)
                rclpy.spin_until_future_complete(self,future,timeout_sec=2)
                try:
                    rs = future.result()
                    self.get_logger().info(f"---- Supervisor: Receive Init Respond from Server Module_Scanning&Interface: {rs.b}")
                    self.get_logger().warn("---- Supervisor: Sending Request to Server Module_Input.node_io_weigh ---- ")
                    future = self.client_io_weigh.call_async(rq)
                    rclpy.spin_until_future_complete(self,future,timeout_sec=2)
                    try:
                        rs = future.result()
                        self.get_logger().info(f"---- Supervisor: Receive Init Respond from Server Module_Input.node_io_weigh: {rs.b}")
                        self.get_logger().warn("---- Supervisor: Sending Request to Server Module_Weigh ---- ")
                        future = self.client_mw.call_async(rq)
                        rclpy.spin_until_future_complete(self,future,timeout_sec=2)
                        try:
                            rs = future.result()
                            self.get_logger().info(f"---- Supervisor: Receive Init Respond from Server Module_Weigh: {rs.b}")
                            self.get_logger().warn("---- Supervisor: Sending Request to Server Module_Motor.node_dc_motor ---- ")
                            future = self.client_dc_motor.call_async(rq)
                            rclpy.spin_until_future_complete(self,future,timeout_sec=2)
                            try:
                                rs = future.result()
                                self.get_logger().info(f"---- Supervisor: Receive Init Respond from Server Module_Motor.node_dc_motor: {rs.b}")
                                #To be continue (May be we will have some modules)
                                return 0
                            except Exception:
                                self.get_logger().warn("---- Supervisor: Can't send request to Server Module_Motor.node_dc_motor ----")
                                return -1
                        except Exception:
                            self.get_logger().warn("---- Supervisor: Can't send request to Server Module_Weigh ----")
                            return -1
                    except Exception:
                        self.get_logger().warn("---- Supervisor: Can't send request to Server Module_Input.node_io_weigh ----")
                        return -1
                except Exception:
                    self.get_logger().warn("---- Supervisor: Can't send request to Server Module_Scanning&Interface ----")
                    return -1
    def sendTerminate(self):
        msg = TerminateSys()
        msg.a = "Terminate"
        self.publisher_terminate.publish(msg)
    def checkStatus(self):
        time_counter = 0
        #Connect to server_module_scanning_interface (Try to connect for 2 seconds)
        while not self.client_mci.wait_for_service(1):
            self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Scanning&Interface ----")
            if time_counter > 2:
                break
            time_counter+=1
        if time_counter > 2:
            self.get_logger().error("---- Supervisor: Can't connect to Module Scanning&Interface ----")
            self.sendTerminate()
            rclpy.shutdown()
            exit(-1)
        else:
            self.get_logger().info("---- Supervisor: Connect to Module_Scanning&Interface Successfully----")
            time_counter = 0
            while not self.client_io_weigh.wait_for_service(1):
                self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Input.node_io_weigh ----")
                if time_counter > 2:
                    break
                time_counter +=1
            if time_counter > 2:
                self.get_logger().error("---- Supervisor: Can't connect to server Module_Input.node_io_weigh ----")
                self.sendTerminate()
                rclpy.shutdown()
                exit(-1)
            else:
                self.get_logger().info("---- Supervisor: Connect to Module_Input.node Successfully----")
                time_counter = 0 #rest time_counter
                while not self.client_mw.wait_for_service(1):
                    self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Weigh ----")
                    if time_counter > 2:
                        break
                    time_counter +=1
                if time_counter > 2:
                    self.get_logger().error("---- Supervisor: Can't connect to server Module_Weigh ----")
                    self.sendTerminate()
                    rclpy.shutdown()
                    exit(-1)
                self.get_logger().info("---- Supervisor: Connect to Module_Weigh Successfully----")
                time_counter = 0
                while not self.client_dc_motor.wait_for_service(1):
                    self.get_logger().warn("---- Supervisor: Waiting to connect to server Module_Motor.node_dc_motor ----")
                    if time_counter > 2:
                        break
                    time_counter+=1
                if time_counter > 2:
                    self.get_logger().error("---- Supervisor: Can't connect to server Module_Motor.node_dc_motor ----")
                    self.sendTerminate()
                    rclpy.shutdown()
                    exit(-1)
                #To be continue (May be we will have some modules)
                self.get_logger().info("---- Supervisor: Connect to Module_Motor.node_dc_motor Successfully----")
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