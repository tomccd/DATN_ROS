'''
********************************************
# Chương trình này được viết bởi tomccd (Nguyễn Huy Hoàng)
# Tên file: module_send_email.py
# Ngày sửa đổi gần nhất: 29/12/2024
********************************************
'''
import smtplib
import subprocess
from email import encoders
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import rclpy
from rclpy.node import Node
from custom_interfaces.msg import SendFileName
from custom_interfaces.srv import InitSys
import datetime
import pypyodbc as odbc
import pandas as pd
class myNode(Node):
    def __init__(self,name:str):
        super().__init__(name)
        #Create a Server
        self.server_send_email = self.create_service(InitSys,"module_send_email",self.callBack)
        #Create a Subcriber
        self.subcriber_send_fname = self.create_subscription(SendFileName,"sendfilename",self.sendEmail,10)
        #Sender Email
        self.sender_email = "botdatn2k2@gmail.com"
        #Sender Password
        self.sender_password = "oksibxyidrthszbf"
        #Recipient Email: DB ?
        self.recipient_email = "hoangnguyenhuy18012002@gmail.com"
        #Kết nối với CSDL
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
            self.get_logger().error(f"---- Server Module_Send_Email: Can't connect to DB with error: {e}")
            self.on_closing()
        else:
            self.get_logger().info("----  Server Module_Send_Email: Connect to DB Successfully ----")
        self.list_admin_email = []
        self.collect_Admin_Email()
        #Server SMTP
        self.server_smtp = smtplib.SMTP_SSL('smtp.gmail.com',465)
        try:
            self.server_smtp.login(self.sender_email,self.sender_password)
        except Exception as e:
            self.get_logger().error(f"---- Module_Send_Email: Can't sign in to this account. Error: {e} ----")
            self.on_closing()
        #Tạo 1 Timer để update danh sách email của các admin khác nhau
        self.timer_ = self.create_timer(5,self.collect_Admin_Email)
    def collect_Admin_Email(self):
        sql_query = f"SELECT * FROM [DATN].[dbo].Admin"
        try:
            df = pd.read_sql(sql_query,self.conn)
            #Lấy tất cả dữ liệu từ cột email
            list_email = df['admin_email'].values.tolist()
            if len(list_email) > 0:
                set_a = set(self.list_admin_email)
                set_b = set(list_email)
                if set_a != set_b:
                    #Cập nhật nếu 2 list khác nhau
                    self.list_admin_email = list_email
            else:
                self.get_logger().warn("---- Module_Send_Email: The list of Admin Email Account is empty -----")
            if len(self.list_admin_email) == 0:
                self.get_logger().error("---- Module_Send_Email: Can't send email without non-empty list of Admin Email Account ----")
        except Exception as e:
            self.get_logger().error(f"---- Module_Send_Email: Can't collect Admin Email Account. Error: {e} ----")
            self.on_closing()
    def sendEmail(self,msg):
        self.get_logger().info(f"---- Server_Module_Send_email: Receive File Name: {msg.fname} ----")
        fname = str(msg.fname).replace('\n','')
        fopen = open(msg.fname, "rb")
        # Add the attachment to the message
        part = MIMEBase("application", "o")
        part = MIMEBase("application", "octet-stream")
        part.set_payload(fopen.read())
        encoders.encode_base64(part)
        part.add_header(
            "Content-Disposition",
            f"attachment; filename= {fname}",
        )
        #Content
        message = MIMEMultipart()
        message['Subject'] = f"Hệ thống bị ngắt không xác định!"
        message['From'] = "Bot Gmail"
        message['To'] =", ".join(self.list_admin_email) #Gửi nhiều Admin
        html_part = MIMEText(f"Hệ thống bị ngắt không xác định vào lúc {datetime.datetime.now()}. Sau đây là file log hệ thống.")
        message.attach(html_part)
        message.attach(part)
        #Send email
        for email in self.list_admin_email:
            self.server_smtp.sendmail(self.sender_email,email,message.as_string())
        self.on_closing()
    def callBack(self,rq,rs):
        self.get_logger().info(f"---- Server Module_Send_Email: Receive Intialized Request: {rq.a} ----")
        self.init_status = True
        rs.b = "OK"
        return rs
    def on_closing(self):
        rclpy.shutdown()
        # subprocess.call('echo $MY_SUDO_PASS | sudo -S shutdown now',shell=True) #Shutdown -> mở comment khi và chỉ khi hoàn thành ứng dụng
        exit(-1)
def main(args=None):
    rclpy.init(args=args)
    node = myNode("module_send_email")
    rclpy.spin(node)

if __name__ == "__main__":
    main()