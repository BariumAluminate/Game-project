# Game project

1. 2 người dùng các lá bài để chiến đấu với nhau
2. Mỗi lá bài sẽ chứa các đòn tấn công (mỗi đòn tấn công tương ứng với một dice)
3. Dice: số ngẫu nhiên trong khoảng [minn,maxx]
4. Một clash xảy ra khi cả 2 người cùng chĩa hướng tấn công vào nhau
5. Khi clash xảy ra, các dice tương ứng trong lá bài được chọn sẽ nhảy một số ngẫu nhiên, bên nào dice cao hơn sẽ gây được một đòn tấn công lên kẻ địch với sát thương bằng dice đó
6. Người chơi thua khi hp về 0, thắng khi hp địch về 0

# Vesion 0.1:
- Tạo ra 2 người chơi
- Mỗi người chơi sẽ có 1 lá bài
- Mỗi lá bài sẽ chứa 3 dice
- Dice sẽ có giá trị ngẫu nhiên trong khoảng [1,6]
- Mỗi người chơi sẽ có 30 hp
- Dice luôn là offensive
- Chỉ có 1 turn duy nhất