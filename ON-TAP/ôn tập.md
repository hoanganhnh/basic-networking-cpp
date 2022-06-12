1. **_Trình bày cấu trúc mạng điểm điểm:_**

\- Là kiểu đường chuyền nối từng cặp node lại với nhau theo một hình học xác định. Một kênh truyền vật lý sẽ được thiết lập giữa 2 node có nhu cầu trao đổi thông tin. Chức năng các node trung gian: tiếp nhận, lưu trữ tạm, gửi thông tin sang node tiếp theo. Cấu trúc điểm điểm gọi là mạng lưu và gửi tiếp.

1. **_Trình bày cấu trúc mạng đa điểm (quảng bá)_**

\- Tất cả các node cùng truy cập trung trên một đường chuyền vật lý. Một thông điệp được truyền đi từ một node nào đó sẽ được tất cả các node còn lại tiếp nhận và kiểm tra địa chỉ đích trong thông điệp có phải của nó hay không.

\- Phân chia làm hai loại: quảng bá tĩnh và quảng bá động phụ thuộc vào việc cấp phát đường truyền cho các node

1. **_Hãy trình bày cách hoạt động của mạng hình sao khi cần truyền thông tin giữa các node_**

\- Mạng dạng hình sao bao gồm một trung tâm và các node thông tin. Các node thông tin là các trạm đầu cuối, các máy tính và các thiết bị khác của mạng. Trung tâm của mạng điều phối mọi hoạt động trong mạng với các chức năng cơ bản là:

\+ Xác định cặp địa chỉ gửi và nhận được phép chiếm tuyến thông tin và liên lạc với nhau.

\+ Cho phép theo dõi và xử lý sai trong quá trình trao đổi thông tin.

\+ Thông báo các trạng thái của mạng

1. **_Hãy trình bày cách hoạt động của mạng hình vòng (token ring) khi cần truyền thông tin giữa các node_**

\- Bố trí theo dạng xoay vòng, đường dây cáp được thiết kế làm thành một vòng khép kín, tín hiệu chạy quanh theo một chiều nào đó. Các nút truyền tín hiệu cho nhau mỗi thời điểm chỉ được một nút. Dữ liệu truyền đi phải có kèm theo địa chỉ cụ thể của mỗi trạm tiếp nhận.

1. **_Hãy trình bày cách hoạt động của mạng bus khi cần truyền thông tin giữa các node_**

\- Máy chủ (host) cũng như tất cả các máy tính khác (workstation) hoặc các nút (node) đều được nối về với nhau trên một trục đường dây cáp chính để chuyển ti n tín hiệu. Tất cả các nút đều sử dụng chung đường dây cáp chính này. Phía hai đầu dây cáp được bịt bởi một thiết bị gọi là terminator. Các tín hiệu và gói dữ liệu (packet) khi di chuyển lên hoặc xuống trong dây cáp đều mang theo điạ chỉ của nơi đến

1. **_Hãy trình bày mục đích của mạng máy tính ?_**

\- **mạng máy tính** là một hệ thống **mạng** lưới các **máy tính** được kết nối với nhau theo một đường truyền vật lý. Chúng được kết nối theo kiến trúc nào đó (Network Architecture) nào đó. **Mục đích** tạo nhằm thu thập, trao đổi dữ liệu và chia sẻ tài nguyên cho nhiều người cùng sử dụng

1. **_Hãy trình bày về mô hình kiến trúc đa tầng_**

\- Dữ liệu được chuyền giữa hai tầng liên tiếp (trừ tầng cuối cùng)

\- Node phát dữ liệu được chuyền từ tầng trên xuống tầng dưới

\- Node thu: Dữ liệu truyền từ tầng thấp lên tầng cao

\- Tại tầng cuối cùng dữ liệu được truyền trực tiếp giữa node thu vả node phát

Trong kiến trúc phân tầng, mỗi hệ thống thành phần của mạng được xem như một cấu trúc đa tầng, trong đó mỗi tầng được xây dựng trên tầng dưới nó.

Số lượng các tầng cũng như tên và chức năng của mỗi tầng tuỳ thuộc vào ý tưởng của người thiết kế.

Mục đích của việc phân tầng là để chuyên môn hóa các chức năng dịch vụ. Mỗi

tầng khi sử dụng dịch vụ không cần quan tâm đến cách thực hiện của các tầng

dưới.

\+ Liên kết giữa hai tầng thấp nhất gọi là liên kết vật lý, liên kết của tất cả các tầng cao hơn gọi là liên kết logic.

\+ Giao tiếp giữa hai tầng liền kề gọi là giao diện, chúng trao đổi dữ liệu với nhau qua các điểm truy nhập dịch vụ.

\+ Các tầng tương ứng giao tiếp với nhau dựa trên các qui tắc nhất định gọi là giao thức, mỗi tầng có thể gồm nhiều giao thức.

\+ Giao thức (Protocol) là tập các tiêu chuẩn để trao đổi thông tin giữa hai hệ thống máy tính hoặc hai thiết bị máy tính với nhau.

\+ Dữ liệu của tầng trên khi chuyển qua tầng dưới có thể sẽ được tách thành những đơn vị dữ liệu nhỏ hơn và đồng thời được thêm các thông tin điều khiển để phù hợp với giao thức truyền tin của tầng dưới. Tầng dưới tương ứng sẽ bóc tách thông tin điều khiển và tập hợp các đơn vị dữ liệu để chuyển lên tầng cao hơn.

Kiến trúc phân tầng bao gồm hai loại mô hình cơ bản: Mô hình giao thức và mô hình tham chiếu.

1. **_Hãy trình bày chức năng của các tầng trong kiến trúc OSI_**

\- ![TableDescription automatically generated with low confidence](Aspose.Words.d6ea7c07-a6dd-4ef2-96c8-419d584388a7.001.png)

1. **_Hãy trình bày chức năng của các tầng trong mô hình TCP/IP_**

\- Tầng ứng dụng: hỗ trợ các ứng dụng cho các giao thức tầng Host to Host, cung cấp giao diện cho người dùng sử dụng trong mô hình TCP/IP, các giao thức ứng dụng gồm FTP, SMTP…

\- Tầng vận chuyển Host to Host: thực hiện những kết nối giữa 2 máy chủ trên mạng bằng 2 giao thức: điều khiển trao đổi dữ liệu TCP và giao thức dữ liệu người sử dụng UDP. TCP đảm bảo tính chính xác và độ tin cậy cao trong việc trao đổi dữ liệu. UDP dùng cho những ứng dụng không đòi hỏi độ tin cậy cao.

\- Tầng mạng: cung cấp địa chỉ logic cho giao diện vật lý mạng. Giao thức hiện hiện là IP kết nối không liên kết, cho phép kết nối một cách mềm dẻo, linh hoạt.

\- Tầng tầng truy cập mạng: cung cấp các phương tiện kết nối vật lý cáp, bộ chuyển đổi, card mạng, giao thức kết nối, giao thức truy cập đường truyền

1. ` `**_Hãy trình bày kỹ thuật lập trình truyền thông với Socket sử dụng giao thức TCP_**

-   **_Giai đoạn 1: Server (node thu) tạo socket, gán số hiệu cổng và lắng nghe yêu cầu kết nối._**

\- **socket()**: Server yêu cầu tạo một socket để có thể sử dụng các dịch vụ của tầng giao vận.

\- **bind()**: Server yêu cầu gán số hiệu cổng (port) cho socket.

\- **listen()**: Server lắng nghe các yêu cầu kết nối từ các client trên cổng đã được gán

=> Server chờ đợi kết nối từ client.

-   **_Giai đoạn 2: Client tạo socket, yêu cầu thiết lập kết nối tới Server_**

\- **socket()**: Client tạo một socket để có thể sử dụng các dịch vụ của tầng giao vận, thông thường hệ thống tự động gán một số hiệu cổng cho socket của Client.

\- **connect()**: client gửi yêu cầu kết nối tới server có địa chỉ IP và Port xác định.

\- **accept()**: Server chấp nhận kết nối của client, khi đó một kênh giao tiếp ảo được hình thành, client và server có thể trao đổi thông tin với nhau qua kênh ảo này.

-   **_Giai đoạn 3: Trao đổi thông tin giữa Client và Server:_**

**-** Sau khi chấp nhận yêu cầu kết nối, thông thường server thực hiện lệnh **read()\*** và nghẽn\*\*\* cho tới khi thông điệp yêu cầu (Request Message) từ client gửi đến.

**-** Server phân tích thực hiện yêu cầu. Kết quả sẽ được gửi về client bằng lệnh **write()**

**-** Sau khi gửi yêu cầu băng lệnh write(), client chờ nhận thông tin kết quả (ReplyMessage) từ server bằng lệnh **read()**

1. **_Hãy trình bày kỹ thuật lập trình truyền thông với Socket sử dụng giao thức UDP_**

-   **_Giai đoạn 1: Bên nhận tạo Socket – gán số hiệu cổng._**

\- **socket()**: Bên nhận yêu cầu tạo một socket để có thể sử dụng các dịch vụ của tầng vận chuyển

\- **bind()**: bên nhận yêu cầu gán số hiệu cổng cho socket.

-   **_Giai đoạn 2:_**

\- bên gửi tạo một socket và kết nối với bên nhận

-   **_Giai đoạn 3: Trao đổi thông tin giữa hai node_**

\- Sau khi tạo Socket xong, bên gửi và bên nhận có thể trao đổi thông tin qua lại với nhau thông qua hàm **sendto()** và **recvfrom()**.
