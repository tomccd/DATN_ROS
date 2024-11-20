# DATN_ROS - Đồ án tốt nghiệp đề tài phân loại sản phẩm theo mã QR và cân nặng sử dụng ROS2 Communication

## Nhiệm vụ
### 1. Module Supervisor
-    [x] Hoàn thành
### 2. Module Scanning&Interface
-    [x] Tạo khung giao diện
-    [x] Bổ sung thêm phần Camera phân loại QR
-    [x] Bổ sung phần kết nối CSDL
-    [x] Kiểm tra CSDL
-    [x] Hiển thị bảng với thông tin sản phẩm
-    [ ] Phần bổ sung khác
### 3. Module Motor
-    [x] Bật Motor_DC và tắt Motor_DC khi hệ thống làm việc với trạng thái tương ứng
-    [x] Motor Servor phân loại đồng bộ với Module_Input và Module_Scanning&Interface 
### 4. Module Input
-    [x] Đặt trạng thái Enable, Disable cân thông qua 2 cảm biến
-    [x] Lấy dữ liệu cảm biến IO_Cân
-    [x] Lấy dữ liệu cảm biến IO_Phanloai
-    [ ] Bổ sung node_io_start_stop_pending
### 5. Module Weigh
-    [x] Kích hoạt cân khi có trạng thái Enable
-    [x] Gửi dữ liệu cân
### 6. Module Log File
-    [x] Log file khi chạy xong chương trình hoặc khi chương trình bị hủy
### 7. Module Send Email
-    [x] Gửi file log qua email khi hệ thống bị ngắt đột ngột