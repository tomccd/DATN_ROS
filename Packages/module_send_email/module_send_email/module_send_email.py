import smtplib
from email import encoders
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import rclpy
from rclpy.node import Node
from custom_interfaces.msg import SendFileName
from custom_interfaces.srv import InitSys
import datetime
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
        #Server SMTP
        self.server_smtp = smtplib.SMTP_SSL('smtp.gmail.com',465)
        try:
            self.server_smtp.login(self.sender_email,self.sender_password)
        except Exception as e:
            self.get_logger().error(f"---- Module_Send_Email: Can't sign in to this account. Error: {e}")
            rclpy.shutdown()
            exit(-1)
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
        message['To'] = self.recipient_email
        html_part = MIMEText(f"Hệ thống bị ngắt không xác định vào lúc {datetime.datetime.now()}. Sau đây là file log hệ thống.")
        message.attach(html_part)
        message.attach(part)
        #Send email
        self.server_smtp.sendmail(self.sender_email,self.recipient_email,message.as_string())
        rclpy.shutdown()
        exit(-1)
    def callBack(self,rq,rs):
        self.get_logger().info(f"---- Server Module_Send_Email: Receive Intialized Request: {rq.a} ----")
        self.init_status = True
        rs.b = "OK"
        return rs
def main(args=None):
    rclpy.init(args=args)
    node = myNode("module_send_email")
    rclpy.spin(node)

if __name__ == "__main__":
    main()