# Sơn nhà

Một ngôi nhà có $n$ tầng đánh số thứ tự từ $1$ đến $n$. Chủ ngôi nhà cần sơn bên ngoài tòa nhà này. Có một vị khách giàu có đến đặt mua các tầng nhà. Họ muốn mua $m$ tầng liên tiếp có cùng màu sơn. Họ không nói rõ sẽ mua các tầng nào. Nên chủ tòa nhà tự hỏi có bao nhiêu cách chọn ra $m$ tầng lầu theo yêu cầu của khách hàng.

***Yêu cầu:*** Tính và đưa ra số cách chọn $m$ tầng lầu theo yêu cầu của khách hàng.

## Input

- Dòng đầu tiên là số nguyên $q$ - số truy vấn cần trả lời. Mỗi truy vấn có dạng:
    - Dòng đầu tiên gồm hai số nguyên $n, m$ chỉ số tầng của tòa nhà và số tầng khách hàng muốn mua.
    - Dòng thứ hai gồm $n$ số nguyên $a_1, a_2, ..., a_n$ chỉ màu ban đầu của các tầng lầu.
    - Dòng thứ ba chứa một số nguyên $k$ biểu thị số lần chủ nhà sơn lại một tầng lầu bất kì.
    - $k$ dòng tiếp theo mỗi dòng chứa hai số nguyên $u$ và $c$ nghĩa là tầng tại thứ $u$ đã được sơn lại bằng màu $c$.

## Constraints

- $1 \le q \le 10$.
- $1 \le m, u \le n$.
- $1 \le a_i, c \le 10^9$.

## Subtasks

- Subtask 1 ($30\%$ số điểm): 
    - $1 \le k \le 10^3$.
    - $1 \le n \le 10^4$.
- Subtask 2 ($70\%$ số điểm): 
    - $1 \le k \le 10^4$.
    - $1 \le n \le 10^5$.

## Output

- Ứng với mỗi truy vấn, sau mỗi lần chủ nhà thực hiện sơn lại một tầng bất kì, đưa ra số cách chọn $m$ tầng thỏa yêu cầu của khách hàng.

## Sample Input

```
1
4 2
1 1 1 1
3
1 1
1 2
2 2
```

## Sample Output

```
3
2
2
```

## Explanation

- Sau lần sơn lại thứ nhất, các tầng có màu $1, 1, 1, 1$, nghĩa là có $3$ cách chọn $2$ tầng liền nhau cùng màu.
- Sau lần sơn lại thứ hai, các tầng có màu $2, 1, 1, 1$, nghĩa là có $2$ cách chọn $2$ tầng liền nhau cùng màu.
- Sau khi sơn lại thứ ba, các tầng có màu $2, 2, 1, 1$, nghĩa là có $2$ cách chọn $2$ tầng liền nhau cùng màu.
