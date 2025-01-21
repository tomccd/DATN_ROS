# DATN_ROS - Đồ án tốt nghiệp đề tài phân loại sản phẩm theo mã QR sử dụng ROS2 Communication

## I. Overview
- Sử dụng ROS2 Framework cho đề tài phân loại sản phẩm theo mã QR
- Design Document: https://github.com/tomccd/Design-Document-For-DATN_ROS
## II. Requirement
- Ubuntu 24.04
- Raspberry PI 4B
- ROS2 Jazzy
## III. How to build
- Cài đặt những các packages cần thiết trong pip:
  ```
      pip3 install -r requirement.txt --break-system-packages 
  ```
- Cài đặt thư việc HX711:
  ```
      sudo apt-get install -y liblgpio-dev
  ```
- Truy cập vào thư mục install và chạy câu lệnh để khởi tạo các module được cài đặt:
  ```
      cd install & source setup.bash
  ```
- Trở về thư mục root của project và tiến hành chạy câu lệnh để build
  ```
      colcon build
  ```
## IV. How to run
- Chạy câu lệnh sau để chạy toàn bộ module đã được cài đặt
  ```
      ros2 launch launch_system launch_system.launch
  ```