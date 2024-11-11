#include "rclcpp/rclcpp.hpp"
#include <iostream>
#include "custom_interfaces/srv/init_sys.hpp"
#include "custom_interfaces/msg/terminate_sys.hpp"
#include <experimental/filesystem>
#include <string>
#include <unistd.h>
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
        }
        
        void callBack(const custom_interfaces::srv::InitSys::Request::SharedPtr req, const custom_interfaces::srv::InitSys::Response::SharedPtr res){
            RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Receive Intialized Request: %s ----",req->a.c_str());
            res->b = "OK";
        }
        void terminateMsg(const custom_interfaces::msg::TerminateSys msg){
            RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Creating Log File... ----");
            sleep(5);
            //Create Log Directory if not existed
            if (!fs::exists(log_dir_current)){
                fs::create_directories(log_dir_current);
            }
            // Create name file based on time
            std::string log_file_name = log_dir_current + "/" + (std::string)ctime(&now) + ".log";
            // Get log file in ros log directory
            std::string cpy_log_file = getFile(log_dir_ros);
            if(cpy_log_file != ""){
                try{
                    fs::copy_file(cpy_log_file,log_file_name);
                    RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Creating Log File Successfully ! ----");
                    RCLCPP_INFO(this->get_logger(),"---- Server Module_Log_File: Receive Message: %s. Bye Bye... ----",msg.a.c_str());
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
    private:
        /*Default Log Directory*/
        std::string log_dir_ros = "/home/" + std::string(getlogin()) + "/.ros/log/latest";
        /*Current Log Directory*/
        std::string log_dir_current = "/home/tomccd/Documents/Code/Python/DATN/Packages/Log";
        //Current date/time based  on current system
        time_t now = time(0);
        /*Create a Server*/
        rclcpp::Service<custom_interfaces::srv::InitSys>::SharedPtr server_module_log_file;
        /*Create a Terminate Subcriber*/
        rclcpp::Subscription<custom_interfaces::msg::TerminateSys>::SharedPtr terminate_subcriber;
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
};

int main(int argc, char*argv[]){
    //Init ROS2 Communication
    rclcpp::init(argc,argv);
    //Declare a Node
    auto node = std::make_shared<myNode>("module_log_file");
    //Spin
    rclcpp::spin(node);
}