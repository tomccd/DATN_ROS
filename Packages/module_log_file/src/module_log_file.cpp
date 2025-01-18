/*
********************************************
# Chương trình này được viết bởi tomccd (Nguyễn Huy Hoàng)
# Tên file: module_log_file.cpp
# Ngày sửa đổi gần nhất: 29/12/2024
********************************************
*/
#include "rclcpp/rclcpp.hpp"
#include <iostream>
#include "custom_interfaces/srv/init_sys.hpp"
#include "custom_interfaces/msg/terminate_sys.hpp"
#include "custom_interfaces/msg/send_file_name.hpp"
#include <experimental/filesystem>
#include <string>
#include <unistd.h>
#include <ctime>
#include <iomanip>
namespace fs=std::experimental::filesystem;
typedef std::experimental::filesystem::__cxx11::directory_entry directory_entry;
class myNode:public rclcpp::Node{
    public:
        myNode(const char *name):Node(name){
            /*Init a Server*/
            server_module_log_file = this->create_service<custom_interfaces::srv::InitSys>(
                "module_log_file",
                std::bind(
                    &myNode::callBack,
                    this,
                    std::placeholders::_1,
                    std::placeholders::_2
                ));
            /*Init a Terminate Subcriber*/
            terminate_subcriber = this->create_subscription<custom_interfaces::msg::TerminateSys>(
                "terminate",
                10,
                std::bind(
                    &myNode::terminateMsg,
                    this,
                    std::placeholders::_1
                )
            );
            /*Init a Send File Nmae Publisher*/
            publisher_send_fname = this->create_publisher<custom_interfaces::msg::SendFileName>(
                "sendfilename",
                10
            );
        }
        
        void callBack(const custom_interfaces::srv::InitSys::Request::SharedPtr req, const custom_interfaces::srv::InitSys::Response::SharedPtr res){
            RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Receive Intialized Request: %s ----",req->a.c_str());
            res->b = "OK";
        }
        void terminateMsg(const custom_interfaces::msg::TerminateSys msg){
            //Delete old file
            RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Delete Old Log files and compressed file ----");
            removeFilesWithExtension();
            RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Creating Log File... ----");
            sleep(3);
            //Create Log Directory if not existed
            if (!fs::exists(log_dir_current)){
                fs::create_directories(log_dir_current);
            }
            // Create name file based on time
            std::string log_file_name = log_dir_current + "/" + getCurrentTimeFormatted() + ".log";
            // Get log file in ros log directory
            std::string cpy_log_file = getFile(log_dir_ros);
            if(cpy_log_file != ""){
                try{
                    fs::copy_file(cpy_log_file,log_file_name);
                    RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Creating Log File Successfully ! ----");
                    RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Compressing Log File with name..... ----");
                    std::string cpressFileName = "";
                    int status = compressFile(log_file_name,cpressFileName);
                    switch(status){
                        case FileNotFound:
                            RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Can't create Log File ----");
                            break;
                        case CompressedFailed:
                            RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Compressing Log File Error. Instead of that, sending the log file ----");
                            RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Sending Email.... ! ----");
                            this->sendFileName(log_file_name);
                            sleep(5);
                            RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Receive Message: %s. Bye Bye... ----",msg.a.c_str());
                            break;
                        case CompressedSuccessfully:
                            RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Compressing Log File Successfully ----");
                            RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Sending Email.... ! ----");
                            this->sendFileName(cpressFileName);
                            sleep(5);
                            RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Receive Message: %s. Bye Bye... ----",msg.a.c_str());
                            break;
                    }
                    rclcpp::shutdown();
                    exit(0);
                }
                catch(std::exception &e){
                    RCLCPP_ERROR(this->get_logger(),"---- Server Module_Log_File: Can't Create Log File with error: %s",e.what());
                    rclcpp::shutdown();
                    exit(0);
                }
            }
        }
        void sendFileName(std::string fname){
            custom_interfaces::msg::SendFileName msg = custom_interfaces::msg::SendFileName();
            msg.fname = fname;
            this->publisher_send_fname->publish(msg);
        }
    private:
        typedef enum _compressStatus{
            FileNotFound = -1,
            CompressedFailed = 0,
            CompressedSuccessfully = 1
        }CompressStatus;
        /*Default Log Directory*/
        std::string log_dir_ros = (std::string)"/home/tomccd/.ros/log/latest";
        /*Current Log Directory*/
        std::string log_dir_current = (std::string)"/home/tomccd/Documents/Code/Python/DATN/Packages/Log";
        //Current date/time based  on current system
        time_t now = time(0);
        /*Create a Server*/
        rclcpp::Service<custom_interfaces::srv::InitSys>::SharedPtr server_module_log_file;
        /*Create a Terminate Subcriber*/
        rclcpp::Subscription<custom_interfaces::msg::TerminateSys>::SharedPtr terminate_subcriber;
        /*Create a Send_Email Publisher*/
        rclcpp::Publisher<custom_interfaces::msg::SendFileName>::SharedPtr publisher_send_fname;
        /*Get log file from ros folder in $HOME directory*/
        std::string getFile(std::string &path){
            if(fs::is_directory(path)){
                std::vector<directory_entry>path_vct;
                for(auto &entry: fs::directory_iterator(path)){
                    std::cout << entry.path().string();
                    path_vct.push_back(entry);
                }
                return path_vct[0].path().string();
            }
            return "";
        }
        void replaceSpaceWithChar(std::string &str, char c){
            for(unsigned int i=0;i<str.size();i++){
                if(str[i] == ' '){
                    str[i] = c;
                }
            }
        }
        /*Kiểm tra file*/
        void removeFilesWithExtension(){
            const int arrayLength = 2;
            std::string fileExt[arrayLength] = {".log",".gz"};
            for(int i=0;i<arrayLength;i++){
                if(fs::is_directory(log_dir_current)){
                    for(auto &entry: fs::directory_iterator(log_dir_current)){
                        if(entry.path().extension().string() == fileExt[i]){
                            std::string str_cmd = "rm " + log_dir_current + "/" + "*" + fileExt[i];
                            system(str_cmd.c_str()); //may be cause vulnerbility
                            break;
                        }
                    }
                }
            }
        }
        /*Nén file sử dụng tar*/
        CompressStatus compressFile(std::string file_name, std::string &compressed_file_name){
            if(fs::exists(file_name)){
                std::string compressedFileNamePath = log_dir_current + "/" + "logFile.tar.gz";
                std::string file_dir = fs::path(file_name).parent_path().string();
                std::string file_name_only = fs::path(file_name).filename().string();
                // Sử dụng -C để chỉ định thư mục chứa tệp cần nén
                std::string str_cmd = "tar -czvf " + compressedFileNamePath + " -C " + file_dir + " " + file_name_only;
                if(system(str_cmd.c_str()) == -1){ // may be caused vulnerbility
                    return CompressedFailed;
                }
                else{
                    compressed_file_name = compressedFileNamePath;
                    return CompressedSuccessfully;
                }
            }
            return FileNotFound;
        }
        /*Lấy thời gian hiện tại*/
        std::string getCurrentTimeFormatted() {
            // Get current time
            std::time_t now = std::time(0);
            std::tm* local_time = std::localtime(&now);
            
            // Create a string stream to hold the formatted time
            std::ostringstream oss;
            // Format: YYYY-MM-DD_HH.log
            oss << std::put_time(local_time, "%Y-%m-%d_%H-%M-%S");
            
            return oss.str();
        }
};

int main(int argc, char*argv[]){
    //Init ROS2 Communication
    rclcpp::init(argc,argv);
    //Declare a Node
    auto node = std::make_shared<myNode>("module_log_file");
    //Spin
    rclcpp::spin(node);
}