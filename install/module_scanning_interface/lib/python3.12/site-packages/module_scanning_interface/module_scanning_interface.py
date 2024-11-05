from custom_interfaces.srv import InitSys
from custom_interfaces.msg import TerminateSys
import tkinter as tk
from tkinter import StringVar
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
        #-- Tạo Node và các thuộc tính cần thiết   --
        #Tạo Node
        self.node = myNode('module_scanning_interface')
        #Tạo 1 Terminating Subcriber
        self.subcriber_terminate = self.node.create_subscription(TerminateSys,"terminate",self.on_closing,10)
        #Tạo 1 Thread chịu trách nhiệm cho việc luôn spin
        self.thread_spin = threading.Thread(target=rclpy.spin,args=(self.node,))
        
        #-- Thiết kế giao diện  --
        self.title = title
        #Giao diện có kích thước là 800x480
        self.window_width = 800
        self.window_height = 480
        self.geometry(f'{self.window_width}x{self.window_height}')
        
        #-- Chia frame
        #Frame chứa text intro
        self.frame_text_intro = tk.Frame(self,borderwidth=2,width=self.window_width,height=int(self.window_height/5),relief='solid') 
        self.frame_text_intro.pack_propagate(False)
        self.frame_text_intro.pack()  
        
        #Frame chứa số lượng sản phẩm phân loại
        self.frame_product_distiguish = tk.Frame(self,borderwidth=2,width=self.window_width,height=int(self.window_height/5),relief='solid')
        self.frame_product_distiguish.pack_propagate(False)
        self.frame_product_distiguish.pack()
        
        #Frame chứa phần camera và bảng thống kê phân loại
        self.frame_camera_table = tk.Frame(self,borderwidth=2,width=self.window_width,height=int((self.window_height/5)*3),relief='solid')
        self.frame_camera_table.pack_propagate(False)
        self.frame_camera_table.pack()
        
        #--Phần nội dung
        #Nội dung của phần frame_text_intro
        self.intro_text_label = tk.Label(self.frame_text_intro,text="Thống kê và giám sát sản phẩm")
        self.intro_text_label.place(relx=0.5,rely=0.5,anchor=tk.CENTER)
        
        #Nội dung cho phần frame_product_distiguish
        #1. Chia bố cục
        self.frame_product_distiguish.columnconfigure(index=0,weight=1)
        self.frame_product_distiguish.columnconfigure(index=1,weight=1)
        self.frame_product_distiguish.columnconfigure(index=2,weight=1)
        self.frame_product_distiguish.columnconfigure(index=3,weight=1)
        self.frame_product_distiguish.rowconfigure(index=1,weight=1)
        self.frame_product_distiguish.grid_propagate(False)
        
        #2.Phần frame con
        #Phần chứa tổng số lượng sản phẩm phân loại
        self.frame_product_all = tk.Frame(self.frame_product_distiguish,borderwidth=2,relief='solid',width=int(self.window_width/4),height=int(self.window_height/5))
        self.frame_product_all.grid(row=1,column=0,padx=5,pady=5,sticky='nw')
        self.frame_product_all.pack_propagate(False)
        
        #Phần chứa sản phẩm thuộc loại TBDT
        self.frame_product_electric = tk.Frame(self.frame_product_distiguish,borderwidth=2,relief='solid',width=int(self.window_width/4),height=int(self.window_height/5))
        self.frame_product_electric.grid(row=1,column=1,padx=5,pady=5,sticky='ns')
        self.frame_product_electric.pack_propagate(False)
        
        #Phần chứa sản phẩm thuộc loại QA
        self.frame_product_clothes = tk.Frame(self.frame_product_distiguish,borderwidth=2,relief='solid',width=int(self.window_width/4),height=int(self.window_height/5))
        self.frame_product_clothes.grid(row=1,column=2,sticky='ns',padx=5,pady=5)
        self.frame_product_clothes.pack_propagate(False)
        
        #Phần chứa sản phẩm thuộc loại khác
        self.frame_product_diff = tk.Frame(self.frame_product_distiguish,borderwidth=2,relief='solid',width=int(self.window_width/4),height=int(self.window_height/5))
        self.frame_product_diff.grid(row=1,column=3,sticky='ne',padx=5,pady=5)
        self.frame_product_diff.pack_propagate(False)
        
        #3. Phần nội dung
        #Nội dung phần tông tất cả sản phẩm
        self.num_product_all = 0
        self.str_display_product_all = StringVar(value=f"Tổng số lượng phân loại: \n{self.num_product_all}")
        self.label_product_all = tk.Label(self.frame_product_all,textvariable=self.str_display_product_all)
        self.label_product_all.place(relx=0.5,rely=0.5,anchor=tk.CENTER)
        # self.label_product_all.pack()
        
        #Nội dung phần sản phẩn điện tử
        self.num_product_electric = 0
        self.str_display_product_electric = StringVar(value=f"Số lượng sản phẩn loại TBDT: \n{self.num_product_electric}")
        self.label_product_electric = tk.Label(self.frame_product_electric,textvariable=self.str_display_product_electric)
        self.label_product_electric.place(relx=0.5,rely=0.5,anchor=tk.CENTER)
        # self.label_product_electric.pack()
        
        #Nội dung phần sản phẩm quần áo
        self.num_product_clothes = 0
        self.str_display_product_clothes = StringVar(value=f"Số lượng sản phẩm loại QA: \n{self.num_product_clothes}")
        self.label_product_clothes = tk.Label(self.frame_product_clothes,textvariable=self.str_display_product_clothes)
        self.label_product_clothes.place(relx=0.5,rely=0.5,anchor=tk.CENTER)
        # self.label_product_clothes.pack()
        
        #Nội dung phần sản phẩm khác
        self.num_product_diff = 0
        self.str_display_product_diff = StringVar(value=f"Số lượng sản phẩm khác: \n{self.num_product_diff}")
        self.label_product_diff = tk.Label(self.frame_product_diff,textvariable=self.str_display_product_diff)
        self.label_product_diff.place(relx=0.5,rely=0.5,anchor=tk.CENTER)
        # self.label_product_diff.pack()
        
        #Nội dung cho phần frame_camera_table
        #1. Chia bố cục
        self.frame_camera_table.columnconfigure(index=0,weight=1)
        self.frame_camera_table.columnconfigure(index=1,weight=1)
        self.frame_camera_table.rowconfigure(index=1,weight=1)
        self.frame_camera_table.grid_propagate(False)
        
        #2. Phần frame con
        #Phần chứa camera
        self.frame_camera = tk.Frame(self.frame_camera_table,width=int(self.window_width/2),height=int((self.window_height/5)*3),relief='solid',borderwidth=2)
        self.frame_camera.grid(row=1,column=0,sticky='nw',padx=5,pady=5)
        self.frame_camera.pack_propagate(False)
        #Phần chứa bảng
        self.frame_table = tk.Frame(self.frame_camera_table,width=int(self.window_width/2),height=int((self.window_height/5)*3),relief='solid',borderwidth=2)
        self.frame_table.grid(row=1,column=1,sticky='ne',padx=5,pady=5)
        self.frame_table.pack_propagate(False)
        
        #3. Phần nội dung
        #-Phần chứa bảng
        
        #a) Phần intro
        self.frame_table_intro = tk.Frame(self.frame_table,width=int(self.window_width/2),height=int(((self.window_height/5)*3)/6),relief='solid',borderwidth=2)
        self.frame_table_intro.pack()
        self.frame_table_intro.pack_propagate(False)
        self.label_table_intro = tk.Label(self.frame_table_intro,text="Bảng thống kê phân loại")
        self.label_table_intro.place(relx=0.5,rely=0.5,anchor=tk.CENTER)
        #b) Phần chứa bảng
        self.frame_table_display_tb = tk.Frame(self.frame_table,width=int(self.window_width/2),height=int((((self.window_height/5)*3)/6)*5),relief='solid',borderwidth=2)
        self.frame_table_display_tb.pack()
        self.frame_table_display_tb.pack_propagate(False)
        #-Phần chứa camera 
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
