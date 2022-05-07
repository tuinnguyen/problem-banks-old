# Sơn nhà - Editorial

Ta tạo ra một `set` chứa vị trí bắt đầu của những tầng có cùng màu sơn. Bây giờ, trên mỗi truy vấn có ba khả năng:
-  Màu sơn trùng với màu hiện tại của tầng, vì vậy không có thay đổi nào đối với mảng $a$.
-  Màu sơn làm phá vỡ một đoạn màu liên tục có cùng màu.
-  Màu sơn nối hai đoạn màu liên tục có cùng màu.

Mỗi lần cập nhật truy vấn theo các khả năng trên có thể thực hiện trong $O(\log n)$. Ta sẽ liên tục cập nhật đáp án cho mỗi truy vấn và vị trí bắt đầu của những tầng có cùng màu sơn trong `set`.

## Subtask 1

Hãy bắt đầu với những trường hợp đơn giản. Giả sử bạn có vài tầng có độ dài $l$, thì số cách để chọn các tầng liền kề $m$ từ đoạn này sẽ là $max(0, (l - m + 1))$. Bây giờ, nếu bạn có các đoạn $s_1s_2s_3s_4$, thì số cách chọn hộp $m$ sẽ là tổng số cách cho mỗi đoạn, tức là $\sum^{}{max(0, l_i - m + 1)}$. 

Độ phức tạp: $O(n \times k)$.

## Subtask 2

Ta sẽ tối ưu cách tiếp cận ở trên bằng cách lưu kết của các truy vấn trong $ans$ và duy trì việc lưu các vị trí bắt đầu của các đoạn màu. Sau mỗi truy vấn cập nhật màu, ta cần phải chèn hoặc xóa các vị trí không phù hợp khỏi `set`.

Nếu bạn phân tích kỹ, bạn sẽ thấy rằng khi cập nhật sẽ có hai khả năng như sau:

- Nếu việc tác cập nhật không thay đổi trạng thái của các tầng hiện tại thì sẽ không có thay đổi trong đáp án của truy vấn này.
- Ta có thể mô tả việc thay đổi trạng thái là $...s_ac_1s_b...$ thành $.. s_ac_2s_b...$, trong đó $s_a$ là đoạn ở bên trái và $s_b$ là đoạn ở bên phải của tầng ở vị trí $u_i$, với màu tầng đã thay đổi từ $c_1$ thành $c_2$.

Các trường hợp sau có thể xảy ra (giả sử vị trí các phần tử tính từ $0$):

1. $u_i = 0$ và $c_1$ nằm trong $s_b$ tức là có cùng màu với $s_b$, sau khi thao tác tách diễn ra, $ans = ans - ways(len (s_b) +1) + ways(len (1)) + ways(len (s_b))$, ở đây $ways(l)$ có nghĩa là số cách lấy $m$ hộp liền kề từ đoạn có chiều dài $l$.
2. $u_i = 0$ và $c_1$ không nằm trong $s_b$, sau khi cập nhật $c_2$ nằm trong $s_b$, $ans = ans − ways(1) − ways(len(s_b)) + ways(len(s_b) + 1)$.
3. $u_i = 0$ và $c_1$ và $c_2$ không nằm trong $s_b$, khi đó đáp án không có sự thay đổi.
4. $u_i = n - 1$ và $c_1$ nằm trong $s_a$, sau khi việc tách diễn ra, $ans = ans - ways(len(s_a) + 1) + ways(len(1)) + way (len( s_a))$.
5. $u_i = n - 1$ và $c_1$ không nằm trong $s_a$, sau khi cập nhật $c_2$ nằm trong $s_a$, $ans = ans - ways(1) - ways(len (s_a)) + ways(len(s_a) + 1)$.
6. $u_i = n - 1$ và $c_1$ và $c_2$ không nằm trong $s_a$, khi đó đáp án không có sự thay đổi.
7. Đối với những trường hợp còn lại, $u_i$ nằm trong $(0, n - 1)$, $s_a = s_b$, tức là cùng màu và $c_1$ nằm trong $s_a$, khi đó thao tác tách diễn ra, $ans = ans - ways(len (s_a) + 1 + len (s_b)) + ways(len (s_a)) + ways(1) + ways(len (s_b))$.
8. $s_a = s_b$, $c_1$ không nằm trong $s_a$, $c_2$ nằm trong $s_a$, $ans = ans - ways(len(s_a)) - ways(1) - ways(len(s_b) + ways(len(s_a) + 1 + len(s_b))$.
9. $s_a = s_b$, $c_1$ và $c_2$ không nằm trong $s_a$, khi đó đáp án không có sự thay đổi.
10. $S_a \ne S_b$, $c_1$ nằm trong $s_a$ và $c_2$ nằm trong $s_b$, $ans = ans - ways(len(s_a) + 1) + ways(len (s_a)) - ways(len(s_b)) + ways(len (s_b) + 1)$.
11. $s_a \ne s_b$, $c_1$ nằm trong $s_a$ và $c_2$ không nằm trong cả $s_a$ và $s_b$, $ans = ans - ways(len(s_a) + 1) + ways(1) + ways(len(s_a))$.
12. $s_a \ne s_b$, $c_1$ nằm trong $s_b$ và $c_2$ nằm trong $s_a$, $ans = ans - ways(len(s_b) + 1) + ways(len(s_b)) - ways(len(s_a)) + ways(len(s_a) + 1)$.
13. $s_a \ne s_b$, $c_1$ nằm trong $s_b$ và $c_2$ không nằm trong cả $s_a$ và $s_b$, $ans = ans - ways(len(s_b) + 1) + ways(1) + ways((len(s_b)))$.
14. $s_a \ne s_b$, $c_1$ không nằm trong cả $s_a$ và $s_b$, $c_2$ nằm trong $s_a$, $ans = ans - ways(1) - ways(len(s_a)) + ways(len(s_a) + 1)$.
15. $s_a \ne s_b$, $c_1$ không nằm trong cả $s_a$ và $s_b$, $c_2$ nằm trong $s_b$, $ans = ans - ways(1) - ways(len(s_b)) + ways(len(s_b) + 1)$.
16. $s_a \ne s_b$, $c_1$ và $c_2$ không nằm trong cả $s_a$ và $s_b$, khi đó đáp án không có sự thay đổi.

Độ phức tạp: $O(q \log n)$.
