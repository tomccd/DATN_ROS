from custom_interfaces.srv import InitSys
from custom_interfaces.msg import TerminateSys
import tkinter as tk
import rclpy
from rclpy.node import Node
import threading
#Class Node
class myNode(Node):
    def __init__(self,name:str):
        super().__init__(name)
        #Initialize Status
        self.init_status = False
        #Create a Server
        self.server_mci = self.create_service(InitSys,"module_scanning_interface",self.callBack)
    def callBack(self,req,res):
        self.get_logger().info(f"---- Server Module_Scanning_Interfaces: Receive Intialized Request: {req.a} ----")
        self.init_status = True
        res.b = "OK"
        return res
#Class Tkinter
class myApp(tk.Tk):
    def __init__(self,title:str):
        super().__init__()
        #Tạo Node
        self.node = myNode('module_scanning_interface')
        self.title = title
        #Tạo 1 Terminating Subcriber
        self.subcriber_terminate = self.node.create_subscription(TerminateSys,"terminate",self.on_closing,10)
        #Tạo 1 Thread chịu trách nhiệm cho việc luôn spin
        self.thread_spin = threading.Thread(target=rclpy.spin,args=(self.node,))
        #Giao diện có kích thước là 800x480
        self.geometry('800x480')
    def on_closing(self,msg=None):
        if msg is None:
            self.node.get_logger().info("---- Server Module_Scanning_Interfaces: Shutdown ----")
        else:
            self.node.get_logger().info(f"---- Server Module_Scanning_Interfaces: Receive Message: {msg.a}. Bye Bye....")
        rclpy.shutdown()
        self.destroy()
        exit(-1)
def main(args=None):
    #Initialize ROS2 Communication
    rclpy.init(args=args)
    app = myApp("Test App")
    app.thread_spin.start()
    app.protocol('WM_DELETE_WINDOW',app.on_closing)
    app.mainloop()
if __name__ == "__main__":
    main()
