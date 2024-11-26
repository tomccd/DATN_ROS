from custom_interfaces.srv import InitSys
from custom_interfaces.msg import TerminateSys, WeighValue, SetServoIO, SetServoRotate
import tkinter as tk
from tkinter import StringVar
from tkinter import messagebox
import rclpy
from rclpy.node import Node
import threading
import cv2 as cv
import numpy as np
from PIL import ImageTk,Image
from pyzbar.pyzbar import decode
import pypyodbc as odbc
import pandas as pd
from tkinter import ttk
import time
import sys
#Class Node
class myNode(Node):
    def __init__(self,name:str):
        super().__init__(name)
        #Start,Pending Status
        self.start_status = False
        self.pending_status = False
        #Create a Server
        self.server_mci = self.create_service(InitSys,"module_scanning_interface",self.callBack)
    def callBack(self,req,res):
        #Nếu nhấn nút Start
        if req.a == "Ready":          
            self.get_logger().info(f"---- Server Module_Scanning_Interfaces: Receive Intialized Request: {req.a} ----")
            self.start_status = True
            res.b = "OK"
            return res
        #Nếu nhấn nút Pending (trước đó chưa nhấn nút Pending)
        elif req.a == "Pending":
            #Nếu đã khởi tạo hệ thống
            if self.start_status == True:
                self.get_logger().info(f"---- Server Module_Scanning_Interfaces: Receive Pending Request: {req.a} ----")
                self.pending_status = True
                res.b = "OK"
                return res
            else:
                res.b = "Nope"
                return res
        #Nếu nhấn nút Pending (trước đó đã nhấn nút Pending)
        elif req.a == "Resume":
            #Nếu đã khởi tạo hệ thống
            if self.start_status == True:
                self.get_logger().info(f"---- Server Module_Scanning_Interfaces: Receive Resume Request: {req.a} ----")
                self.pending_status = False
                res.b = "OK"
                return res
            else:
                res.b = "Nope"
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
        #Tạo 1 Subcriber cho việc lấy dữ liệu cân
        self.subcriber_weigh = self.node.create_subscription(WeighValue,"get_weigh",self.addWeightToList,10)
        #Tạo 1 Subcriber cho việc lấy dữ liệu IO Servo
        self.subcriber_io_servo = self.node.create_subscription(SetServoIO,"servo_io",self.receiveIO_Servo,10)
        #Tạo 1 Publisher cho việc ra tín hiệu cho Servo quay
        self.publisher_rotate_servo = self.node.create_publisher(SetServoRotate,"rotate_servo",10)
        #Tạo 1 Thread chịu trách nhiệm cho việc luôn spin
        self.thread_spin = threading.Thread(target=rclpy.spin,args=(self.node,))
        #-- Thiết kế giao diện  --
        self.title = title
        #Giao diện có kích thước là 800x480
        self.window_width = 800
        self.window_height = 480
        self.geometry(f'{self.window_width}x{self.window_height}')
        self.wm_attributes("-zoomed", True)
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
        #Hình vuông có màu sắc thể hiện trạng thái của hệ thống: Đỏ: Chưa khởi tạo, Xanh: Đang chạy, Vàng: Đang chờ   
        self.square_canvas = tk.Canvas(self.frame_text_intro, width=20, height=20, bg="red")  # Thay đổi kích thước và màu sắc theo ý muốn
        self.square_canvas.place(relx=1.0, rely=0.0, anchor=tk.NE)  # Đặt ở góc trên bên phải
        
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
        self.frame_table_display_tb.columnconfigure(index=0,weight=1)
        self.frame_table_display_tb.columnconfigure(index=1,weight=1)
        self.frame_table_display_tb.rowconfigure(index=0,weight=1)
        self.frame_table_display_tb.grid_propagate(False)
        #- Phần bảng
        self.columns = ('_ID','_typeproduct','_weight')
        self.data_treeview = ttk.Treeview(self.frame_table_display_tb,columns=self.columns,show='headings')
        #Hiển thị phần Heading
        self.data_treeview.heading(self.columns[0],text='ID Product')
        self.data_treeview.heading(self.columns[1],text='Product Type')
        self.data_treeview.heading(self.columns[2],text='Weight (g)')
        self.data_treeview.grid(row=0,column=0,sticky='nw')
        #Thêm phần scrollbar bảng
        self.tree_view_scrollbar = ttk.Scrollbar(self.frame_table_display_tb,orient='vertical',command=self.data_treeview.yview)
        self.data_treeview.configure(yscroll=self.tree_view_scrollbar.set)
        self.tree_view_scrollbar.grid(row=0,columns=1,sticky='ne')
        #Điều chỉnh lại kích thước table
        self.data_treeview.column("_ID",width=int((self.window_width/2)/4))
        self.data_treeview.column("_typeproduct",width=int((self.window_width/2)/3))
        self.data_treeview.column("_weight",width=int((self.window_width/2)/4))
        #c) Kết nối CSDL (Điều kiện tiên quyết)
        DRIVER_NAME = 'ODBC Driver 18 for SQL Server'
        SERVER_NAME = '100.118.255.2'
        PORT = '1433'
        DATABASE_NAME = 'DATN'
        UID = 'nv_1'
        password = '18012002'
        connection_string = f"""
            DRIVER={DRIVER_NAME};
            SERVER={SERVER_NAME};
            PORT={PORT}
            DATABASE={DATABASE_NAME};
            UID={UID};
            PWD={password};
            TrustServerCertificate=YES;
        """
        try:
            self.conn = odbc.connect(connection_string)
        except Exception as e:
            self.node.get_logger().error(f"---- Server Module_Scanning&Interface: Can't connect to DB with error: {e}")
            messagebox.showerror("Error",f"Can't connect to DataBase: {e}")
            self.on_closing()
        else:
            self.node.get_logger().info("----  Server Module_Scanning&Interface: Connect to DB Successfully ----")
        #Dictionary chứa các key có giá trị là các Queue chứa dữ liệu dạng ["ID_san_pham","Kieu_san_pham","Can_Nang"]
        self.dict_contain_data_queue = {
            "S1": [],
            "S2": [],
            "S3": []
        }
        #Cursor
        self.cursor = self.conn.cursor()
        #-Phần chứa camera
        #Camera
        self.previous_data = None
        self.camera = cv.VideoCapture(0)
        #Trạng thái thông báo
        self.notify_not_init_status = False
        self.notify_pending_status = False
        self.notify_init_showtime = 0
        self.notify_pending_showtime = 0
        #Label chứa hình ảnh
        self.label_camera = tk.Label(self.frame_camera,image='')
        self.label_camera.pack()
        self.openCameraAndIdentifyCode()
    def receiveIO_Servo(self,msg):
        msg_rotate = SetServoRotate()
        #Sử dụng Queue thuộc S1
        if msg.iomsg == "Thiet bi dien tu":
            if len(self.dict_contain_data_queue["S1"]) > 0:
                self.node.get_logger().info(f"---- Module_Scanning_Interface: Type Product: {(self.dict_contain_data_queue["S1"][0])[1]}")
                #Chia thành 2 trường hợp
                #TH1: Phần tử đứng đầu Queue thuộc S1 có đủ 3 thuộc tính 
                if len(self.dict_contain_data_queue["S1"][0]) > 2:
                    #Nếu đúng loại
                    if msg.iomsg == (self.dict_contain_data_queue["S1"][0])[1]:
                        msg_rotate.rotatemsg = "1_YES"
                        self.node.get_logger().info(f"---- Module_Scanning_Interface: Total Data in S1 Before Popping: {self.dict_contain_data_queue["S1"]}")
                        #Loại bỏ phần tử ban đầu của S1 Queue
                        self.dict_contain_data_queue["S1"].pop(0)
                        self.node.get_logger().info(f"---- Module_Scanning_Interface: Remain Data in S1 if TBDT was detected: {self.dict_contain_data_queue["S1"]}")
                        self.publisher_rotate_servo.publish(msg_rotate)
                        #Cộng dồn giá trị
                        self.num_product_electric += 1
                        self.num_product_all += 1
                        #Hiển thị
                        self.str_display_product_electric.set(f"Số lượng sản phẩn loại TBDT: \n{self.num_product_electric}")
                        self.str_display_product_all.set(f"Tổng số lượng phân loại: \n{self.num_product_all}")
                        return 0
                    #Nếu không đúng loại
                    else:
                        msg_rotate.rotatemsg = "1_NO"
                        self.node.get_logger().info(f"---- Module_Scanning_Interface: Total Data in S1 Before Popping and Transfer to S2: {self.dict_contain_data_queue["S1"]}")
                        #Truyền phần tử ban đầu của S1 Queue sang S2 Queue
                        self.dict_contain_data_queue["S2"].append(self.dict_contain_data_queue["S1"].pop(0))
                        self.node.get_logger().info(f"---- Module_Scanning_Interface: Remain Data in S1 Queue: {self.dict_contain_data_queue["S1"]}")
                        self.publisher_rotate_servo.publish(msg_rotate)
                        return 0
                #TH2: Phần tử đứng đầu Queue thuộc S1 không đủ 3 thuộc tính -> avoid và truyền sang Queue kế tiếp
                else:
                    self.node.get_logger().warn("---- Module_Scanning_Interface: Avoid in S1 Sensor! May be your product didn't weigh----")
                    msg_rotate.rotatemsg = "1_NO"
                    self.node.get_logger().info(f"---- Module_Scanning_Interface: Total Data in S1 Queue Before Popping and Transfer to S2: {self.dict_contain_data_queue["S1"]}")
                    self.dict_contain_data_queue["S2"].append(self.dict_contain_data_queue["S1"].pop(0))
                    self.node.get_logger().info(f"---- Module_Scanning_Interface: Remain Data in S1 Queue: {self.dict_contain_data_queue["S1"]}")
                    self.publisher_rotate_servo.publish(msg_rotate)
                    return 0
        #Sử dụng Queue thuộc S2
        elif msg.iomsg == "Quan ao":
            if len(self.dict_contain_data_queue["S2"]) > 0:
                self.node.get_logger().info(f"---- Module_Scanning_Interface: Type Product: {(self.dict_contain_data_queue["S2"][0])[1]}")
                #Chia thành 2 trường hợp
                #TH1: Phần tử đứng đầu Queue thuộc S2 có đủ 3 thuộc tính 
                if len(self.dict_contain_data_queue["S2"][0]) > 2:
                    #Nếu đúng loại
                    if msg.iomsg == (self.dict_contain_data_queue["S2"][0])[1]:
                        msg_rotate.rotatemsg = "2_YES"
                        self.node.get_logger().info(f"---- Module_Scanning_Interface: Total Data in S2 Before Popping: {self.dict_contain_data_queue["S2"]}")
                        #Loại bỏ phần tử ban đầu của S2 Queue
                        self.dict_contain_data_queue["S2"].pop(0)
                        self.node.get_logger().info(f"---- Module_Scanning_Interface: Remain Data in S2 if QA was detected: {self.dict_contain_data_queue["S2"]}")
                        self.publisher_rotate_servo.publish(msg_rotate)
                        #Cộng dồn giá trị
                        self.num_product_clothes += 1
                        self.num_product_all += 1
                        #Hiển thị
                        self.str_display_product_clothes.set(f"Số lượng sản phẩm loại QA: \n{self.num_product_clothes}")
                        self.str_display_product_all.set(f"Tổng số lượng phân loại: \n{self.num_product_all}")
                        return 0
                    #Nếu không đúng loại
                    else:
                        msg_rotate.rotatemsg = "2_NO"
                        self.node.get_logger().info(f"---- Module_Scanning_Interface: Total Data in S2 Before Popping and Transfer to S3: {self.dict_contain_data_queue["S2"]}")
                        #Truyền phần tử ban đầu của S1 Queue sang S2 Queue
                        self.dict_contain_data_queue["S3"].append(self.dict_contain_data_queue["S2"].pop(0))
                        self.node.get_logger().info(f"---- Module_Scanning_Interface: Remain Data in S2 Queue: {self.dict_contain_data_queue["S2"]}")
                        self.publisher_rotate_servo.publish(msg_rotate)
                        return 0
                #TH2: Phần tử đứng đầu Queue thuộc S2 không đủ 3 thuộc tính -> avoid và truyền sang Queue kế tiếp
                else:
                    self.node.get_logger().warn("---- Module_Scanning_Interface: Avoid in S2 Sensor! May be your product didn't weigh----")
                    msg_rotate.rotatemsg = "2_NO"
                    self.node.get_logger().info(f"---- Module_Scanning_Interface: Total Data in S2 Queue Before Popping and Transfer to S3: {self.dict_contain_data_queue["S2"]}")
                    self.dict_contain_data_queue["S3"].append(self.dict_contain_data_queue["S2"].pop(0))
                    self.node.get_logger().info(f"---- Module_Scanning_Interface: Remain Data in S2 Queue: {self.dict_contain_data_queue["S2"]}")
                    self.publisher_rotate_servo.publish(msg_rotate)
                    return 0
        #Sử dụng Queue thuộc S3
        else:
            if len(self.dict_contain_data_queue["S3"]) > 0:
                self.node.get_logger().info(f"---- Module_Scanning_Interface: Total Data in S3 Queue Before Popping: {self.dict_contain_data_queue["S3"]}")
                self.dict_contain_data_queue["S3"].pop(0)
                self.node.get_logger().info(f"---- Module_Scanning_Interface: Remain Data in S3 Queue if Diff was detected: {self.dict_contain_data_queue["S3"]}")
                #Cộng dồn giá trị
                self.num_product_diff += 1
                self.num_product_all += 1
                #Hiển thị
                self.str_display_product_diff.set(f"Số lượng sản phẩm khác: \n{self.num_product_diff}")
                self.str_display_product_all.set(f"Tổng số lượng phân loại: \n{self.num_product_all}")
                return 0
    def sendDataToDB(self,block_data):
        if block_data[1] == "Khac":
            sql_query = "INSERT INTO [DATN].[dbo].Weigh_Non_Certificate (ID_Product, Weighs) VALUES(?,?);"
            value = [block_data[0],block_data[2]]
            try:
                self.cursor.execute(sql_query,value)
                self.cursor.commit()
            except Exception as e:
                self.node.get_logger().error(f"---- Server Module_Scanning&Interface: Can't send weighs to DB. Error: {e} ----")
                exit(-1)
            else:
                self.cursor.commit()
        else:
            sql_query = "INSERT INTO [DATN].[dbo].Weigh_Certificate (ID_Product, Weighs) VALUES(?,?);"
            value = [block_data[0],block_data[2]]
            try:
                self.cursor.execute(sql_query,value)
            except Exception as e:
                self.node.get_logger().error(f"---- Server Module_Scanning&Interface: Can't send weighs to DB. Error: {e} ----")
                exit(-1)
            else:
                self.cursor.commit()
    def addWeightToList(self,msg):
        if len(self.dict_contain_data_queue["S1"]) > 0:
            for block_data in self.dict_contain_data_queue["S1"]:
                if len(block_data) == 2:
                    block_data.append(msg.value)
                    #Thêm vào bảng hiển thị
                    self.data_treeview.insert('',tk.END,values=block_data)
                    #Thêm vào CSDL
                    thread_send_data = threading.Thread(target=self.sendDataToDB,args=(block_data,))
                    thread_send_data.daemon = True
                    thread_send_data.start()
                    break
            self.node.get_logger().info(f"Data Collect: {self.dict_contain_data_queue["S1"]}")
        ToastNotification(self,"weigh",msg.value,3000)
    def openCameraAndIdentifyCode(self):
        status, frame = self.camera.read()
        if status == True:
            #Nếu đã nhấn Start
            if self.node.start_status == True:
                self.notify_not_init_status = False
                self.notify_init_showtime = 0
                arr = np.copy(frame)
                height,width,_ = frame.shape
                #Nếu không pending hệ thống
                if self.node.pending_status == False:
                    self.notify_pending_status = False
                    self.notify_pending_showtime = 0
                    self.square_canvas.config(bg="green")
                    #Tạo Instance của Class detect_QRCode
                    instance_detect_QrCode = detect_QRCode(arr,frame,width,height)
                    #Kết quả
                    status_detect,result_detect,data_detect = instance_detect_QrCode.detect_qrcode()
                    result = cv.cvtColor(result_detect,cv.COLOR_BGR2RGB)
                    image = Image.fromarray(result).resize((int(self.window_width/2),int((self.window_height/5)*3)))
                    imageTk = ImageTk.PhotoImage(image=image)
                    self.label_camera.configure(
                        image=imageTk
                    )
                    self.label_camera.image = imageTk
                    self.label_camera.pack()
                    valid = False
                    if status_detect:
                        valid = self.is_Valid_Data_DB(data_detect)
                        if valid and self.previous_data != data_detect:
                            ToastNotification(self,"valid data",data_detect,3000)
                            #Cho vào Queue
                            # self.data_queue.append([data_detect,valid])
                            self.dict_contain_data_queue["S1"].append([data_detect,valid])
                            self.previous_data = data_detect
                        elif valid is False and self.previous_data != data_detect:
                            ToastNotification(self,"non valid data",data_detect,3000)
                            #Cho vào Queue
                            # self.data_queue.append([data_detect,"Khac"])
                            self.dict_contain_data_queue["S1"].append([data_detect,"Khac"])
                            self.previous_data = data_detect
                        self.node.get_logger().info(f"Data Collect: {self.dict_contain_data_queue["S1"]}")
                else:
                    if self.notify_pending_status == False and self.notify_pending_showtime == 0:
                        self.square_canvas.config(bg="yellow")
                        message = messagebox.showwarning("Warning","Your System is pending! Please try to press OK to reload status")
                        self.notify_pending_status = True
                        self.notify_pending_showtime +=1
                        
                    image = Image.fromarray(arr).resize((int(self.window_width/2),int((self.window_height/5)*3)))
                    imageTk = ImageTk.PhotoImage(image=image)
                    self.label_camera.configure(
                        image=imageTk
                    )
                    self.label_camera.image = imageTk
                    self.label_camera.pack()
            else:
                if self.notify_not_init_status == False and self.notify_init_showtime == 0:
                    messagebox.showwarning("Warning","Your System didn't Initialize! Please try to press OK to reload status")
                    self.notify_init_showtime +=1
            self.label_camera.after(10,self.openCameraAndIdentifyCode)
        else:
            messagebox.showerror("Error","Cannot detect your camera")
            self.on_closing()
    def is_Valid_Data_DB(self,data):
        sql_query = f"SELECT * FROM [DATN].[dbo].Products WHERE ID_Product = '{data}'"
        try:
            df = pd.read_sql(sql_query,self.conn)
            #Lấy tất cả dữ liệu từ cột id_products
            list_id_products = df['id_product'].values.tolist()
            id_type_product = df['id_type_product'].values.tolist()
            if len(list_id_products)>0:
                #Collect Name_Type_Product
                sql_query = f"SELECT * FROM [DATN].[dbo].Type_Product WHERE ID_Type_Product = '{id_type_product[0]}'"
                try:
                    df = pd.read_sql(sql_query,self.conn)
                    #Lấy danh sách tên loại sản phẩm
                    list_name_products = df['name_type_product'].values.tolist()
                    return list_name_products[0]
                except Exception as e:
                    self.node.get_logger().error(f"Can't send data to DataBase with error: {e}")
                    messagebox.showerror("Error",f"---- Server Module_Scanning&Interface: Can't send data to DataBase {e} ----")
                    self.on_closing()
            else:
                return False
        except Exception as e:
            self.node.get_logger().error(f"Can't send data to DataBase with error: {e}")
            messagebox.showerror("Error",f"---- Server Module_Scanning&Interface: Can't send data to DataBase {e} ----")
            self.on_closing()
    def on_closing(self,msg=None):
        if msg is None:
            self.node.get_logger().info("---- Server Module_Scanning_Interfaces: Shutdown ----")
            messagebox.showwarning("Warning","Shutdown the System")
        else:
            self.square_canvas.config(bg="red")
            self.node.get_logger().info(f"---- Server Module_Scanning_Interfaces: Receive Message: {msg.a}. Bye Bye.... ----")
            self.node.get_logger().error("---- Server Module_Scanning_Interfaces: Your System has been corrupt. Please check the log file at '/home/tomccd/Documents/Code/Python/DATN/Packages/Log' Directory to check the Issue or waiting the Mail send to the Administartor ----")
        rclpy.shutdown()
        self.destroy()
        time.sleep(2)
        sys.exit(-1)
#Thông báo nổi
class ToastNotification:
    def __init__(self,master,type,data,duration):
        if type == "valid data":
            #Take the image from the path, resize it and convert it into tkinter version
            self.img = Image.open('/home/tomccd/Documents/Code/Python/DATN/Packages/icon/icon_1.png').resize((30,20))
            self.imgTk = ImageTk.PhotoImage(self.img)
            message = f"Sản phẩm với ID : {data} hợp lệ"
            #Create a lable
            self.label = tk.Label(master,image=self.imgTk,text=message,bg="lightyellow",padx=10,pady=6,compound="left")
            
            #Để nhãn dán ở phía bên góc phải        
            self.label.place(relx=1.0,rely=0,anchor="ne")
            
            #Tham chiếu lại tham số image phòng nó tự động garbage collect
            self.label.image = self.imgTk
            
            #Đặt thời gian tự động đóng thông báo
            master.after(duration,self.label.destroy)
        elif type == "non valid data":
            #Take the image from the path, resize it and convert it into tkinter version
            self.img = Image.open('/home/tomccd/Documents/Code/Python/DATN/Packages/icon/icon_2.png').resize((30,20))
            self.imgTk = ImageTk.PhotoImage(self.img)
            message = f"Sản phẩm với ID : {data} không hợp lệ"
            #Create a lable
            self.label = tk.Label(master,image=self.imgTk,text=message,bg="lightyellow",padx=10,pady=6,compound="left")
            
            #Để nhãn dán ở phía bên góc phải        
            self.label.place(relx=1.0,rely=0,anchor="ne")
            
            #Tham chiếu lại tham số image phòng nó tự động garbage collect
            self.label.image = self.imgTk
            
            #Đặt thời gian tự động đóng thông báo
            master.after(duration,self.label.destroy)
        elif type=="weigh":
            #Take the image from the path, resize it and convert it into tkinter version
            self.img = Image.open('/home/tomccd/Documents/Code/Python/DATN/Packages/icon/icon_1.png').resize((30,20))
            self.imgTk = ImageTk.PhotoImage(self.img)
            message = f"Khối lượng nhận được {data} g"
            #Create a lable
            self.label = tk.Label(master,image=self.imgTk,text=message,bg="lightyellow",padx=10,pady=6,compound="left")
            
            #Để nhãn dán ở phía bên góc phải        
            self.label.place(relx=1.0,rely=0,anchor="ne")
            
            #Tham chiếu lại tham số image phòng nó tự động garbage collect
            self.label.image = self.imgTk
            
            #Đặt thời gian tự động đóng thông báo
            master.after(duration,self.label.destroy)
        elif type=="warn":
            #Take the image from the path, resize it and convert it into tkinter version
            self.img = Image.open('/home/tomccd/Documents/Code/Python/DATN/Packages/icon/icon_3.png').resize((30,20))
            self.imgTk = ImageTk.PhotoImage(self.img)
            message = f"Warning: {data}"
            #Create a lable
            self.label = tk.Label(master,image=self.imgTk,text=message,bg="lightyellow",padx=10,pady=6,compound="left")
            
            #Để nhãn dán ở phía bên góc phải        
            self.label.place(relx=1.0,rely=0,anchor="ne")
            
            #Tham chiếu lại tham số image phòng nó tự động garbage collect
            self.label.image = self.imgTk
            
            #Đặt thời gian tự động đóng thông báo
            master.after(duration,self.label.destroy)
#Class dùng để nhận biết được QRCode
class detect_QRCode:
    def __init__(self,analyzed_arr,dest_arr,width_analyzed_arr,height_analyzed_arr):
        #-Bắt lỗi
        if isinstance(analyzed_arr,np.ndarray) == False or isinstance(dest_arr,np.ndarray) == False:
            raise ValueError("Sai ma trận đầu vào")
        elif width_analyzed_arr <=0 or height_analyzed_arr <=0:
            raise ValueError("Sai giá trị đầu vào")
        else:
            #-Khai báo các thuộc tính cần thiết
            self.analyzed_arr = analyzed_arr
            self.dest_arr = dest_arr
            self.height_analyzed_arr = height_analyzed_arr
            self.width_analyzed_arr = width_analyzed_arr
    def detect_qrcode(self):
        analyzed_arr = self.analyzed_arr
        recognize_status = False
        data = ''
        #Lấy dữ liệu
        info = decode(analyzed_arr)
        if len(info)>0:
            recognize_status = True
            DecodedObject = info[0]
            print(DecodedObject)
            GeometryOfQrCode = DecodedObject.polygon
            #--Hướng của mã QR Code dựa trên 3 đỉnh
            # có 4 trường hợp:
            # 1 .LEFT, 2. RIGHT, 3. UP, 4. DOWN
            directionOfQrCode = DecodedObject.orientation
            dimensionofQrCode = DecodedObject.rect
            # print(directionOfQrCode)
            # print(DirectionOfQrCode)
            #Vẽ đa giác ABCD bằng tọa độ các đỉnh
            point_A = [GeometryOfQrCode[0].x,GeometryOfQrCode[0].y]
            point_B = [GeometryOfQrCode[1].x,GeometryOfQrCode[1].y]
            point_C = [GeometryOfQrCode[2].x,GeometryOfQrCode[2].y]
            point_D = [GeometryOfQrCode[3].x,GeometryOfQrCode[3].y]
            
            pts = np.array([point_A,point_B,point_C,point_D],dtype=np.int32)
            #Mỗi không gian chứa 2 điểm, do đó cần reshape
            pts = pts.reshape((-1,1,2))
            #Vẽ đa giác trên frame
            cv.polylines(self.dest_arr,[pts],True,color=(0,255,0),thickness=2)
            #Lấy dữ liệu, chuyển dữ liệu gốc về dạng UTF-8
            data = DecodedObject.data.decode('utf-8')
        return recognize_status,self.dest_arr,data

def main(args=None):
    #Initialize ROS2 Communication
    rclpy.init(args=args)
    app = myApp("Test App")
    app.thread_spin.daemon = True
    app.thread_spin.start()
    app.protocol('WM_DELETE_WINDOW',app.on_closing)
    app.mainloop()
if __name__ == "__main__":
    main()
