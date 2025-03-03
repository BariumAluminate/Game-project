# Game project

1. 2 người dùng các lá bài để chiến đấu với nhau
2. Mỗi lá bài sẽ chứa các đòn tấn công (mỗi đòn tấn công tương ứng với một dice)
3. Dice: số ngẫu nhiên trong khoảng [minn,maxx]
4. Một clash xảy ra khi cả 2 người cùng chĩa hướng tấn công vào nhau
5. Khi clash xảy ra, các dice tương ứng trong lá bài được chọn sẽ nhảy một số ngẫu nhiên, bên nào dice cao hơn sẽ gây được một đòn tấn công lên kẻ địch với sát thương bằng dice đó
6. Người chơi thua khi hp về 0, thắng khi hp địch về 0

# Vesion 0.1:
- Tạo ra 2 người chơi
- Thêm vào 4 loại lá bài
- Khi bị stagger sẽ x2 sát thương và không thể tấn công
- Thêm energy để tránh người chơi spam bài mạnh
- One side clash: xảy ra khi chỉ có một bên tấn công
- Số hiệu lá bài để thay thế cho mảng đồ hoạ
- Địch có vô hạn energy
Dự kiến cho 0.2:
- Thêm defensive dice: giảm damage nhận được khi thua clash và chỉ gây sát thương stagger khi thắng clash
- Thêm bài
- Sử dụng triệt để 3 loại offensive dice: thêm hệ số sát thương vào cho các nhân vật

# Version 0.1.1:
- Fix bug vector out of range (em xin lỗi vì em code ngu ạ)
- Nếu ai hỏi hết energy làm gì thì em để lá 0 không có gì là có mục đích ạ
