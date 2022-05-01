# Khôi phục dữ liệu

Một danh sách dữ liệu gồm $m$ số nguyên được ghi trên một file đuôi `.txt` trên máy tính của Tuân. Không may, máy tính của cậu bị hack và các file trong máy đều bị chỉnh sửa. Vì công ty của cậu đang cần tập tin trên nên trong thời gian ngắn nhất cậu cần phải khôi phục lại file ban đầu. File ban đầu chỉ gồm các số nguyên không lặp và được sắp xếp theo thứ tự tăng dần. Sau khi bị hack thì các số bị lặp lại nhiều lần và được sắp xếp một cách ngẫu nhiên.

***Yêu cầu:*** Biết file sau khi bị chỉnh sửa, hãy đưa ra file ban đầu.

## Input

- Dòng đầu tiên là số nguyên dương $n$ - số lượng số nguyên trong file ban đầu.
- Dòng tiếp theo gồm $n$ số nguyên dương $a_1, a_2, a_3, \dots, a_n$ là các số trong file bị chỉnh sửa.

## Constraints

- $1 \le n \le 10^5$.
- $-10^4 \le a_i \le 10^4$.

## Subtasks

- Subtask $1$ ($25\%$ số điểm): có 
    - $1 \le n \le 100$.
    - $-50 \le a_i \le 50$.
- Subtask $2$ ($75\%$ số điểm): không có ràng buộc gì thêm.

## Output

- Dòng đầu tiên là số nguyên dương $m$ - số lượng giá trị phân biệt sau khi khôi phục file.
- Dòng thứ hai có $m$ số nguyên phân biệt được sắp xếp theo chiều tăng dần của giá trị.

## Sample Input

```
5
21 4 2 -2 2
```

## Sample Output

```
4
-2 2 4 21
```
