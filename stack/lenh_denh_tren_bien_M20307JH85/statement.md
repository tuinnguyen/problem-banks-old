# Lênh đênh trên biển

Tuân đang kẹt tại một hòn đảo hẻo lánh xa xôi. Trên đảo chỉ có cây cối, động vật và không có dấu hiệu người sinh sống. Một ngày nọ, từ đằng xa Tuân thấy được có một chiếc du thuyền đang đậu cách Tuân không xa, song đã quá nhiều ngày không được ăn uống đầy đủ nên sức khỏe không cho phép cậu bơi ra chiếc du thuyền đấy. May thay cậu có $n$ miếng gỗ loại $1 \times h$, cậu sẽ xếp các miếng gỗ liên tiếp nhau, các cạnh có chiều dài $h$ được xếp cạnh nhau và song song trên một cạnh thẳng (xem hình ví dụ để hiểu). Sau đó cậu sẽ dùng dây thừng buộc các miếng gỗ này lại thành một chiếc bè và dung nó để bơi ra chiếc thuyền. Để có thể nhanh chóng đến chỗ chiếc thuyền thì chiếc bè của cậu phải có diện tích lớn nhất. Song, cậu sẽ chỉ nằm gọn bên trong phần hình chữ nhật lớn nhất của chiếc bè nên cậu muốn tối ưu diện tích phần hình chữ nhật đấy. Hãy giúp Tuân xác định được phần diện tích hình chữ nhật lớn nhất có thể.

***Yêu cầu:*** Biết thông tin của các miếng gỗ, hãy giúp Tuân xác định phần diện tích hình chữ nhật lớn nhất có thể.

## Input

- Dòng đầu tiên là số nguyên dương $n$.
- Dòng thứ hai là $n$ số nguyên dương $h_1, h_2, h_3, \dots, h_n$ - có ý nghĩa miếng gỗ thứ $i$ có kích thước $1 \times h$.

## Constraints

- $1 \le n \le 10^5$.
- $1 \le h_i \le 10^9$.

## Subtasks

- Subtask $1$ ($25\%$ số điểm): có
    - $1 \le n \le 20$.
    - $1 \le h_i \le 50$.
- Subtask $2$ ($75\%$ số điểm): không có ràng buộc gì thêm.

## Output

- Một số nguyên duy nhất là diện tích lớn nhất của phần hình chữ nhật Tuân sẽ dùng.

## Sample Input

```
5
2 4 4 3 2
```

## Sample Output

```
10
```