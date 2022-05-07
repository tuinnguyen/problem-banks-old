# Giao nhau

Cho hai tập giá trị $A$ và $B$ lần lượt có $n$ và $m$ phần tử là các số nguyên. Biết các phần tử trong hai tập $A$ đều đôi một khác nhau và tập $B$ cũng vậy.

***Yêu cầu:*** Gọi $p$ là số lượng phần tử thuộc tập $A$ xuất hiện trong tập $B$. Hãy tìm giá trị $p$.

## Input

- Dòng đầu tiên là số nguyên dương $n$ - số lượng phần tử trong tập $A$.
- Dòng thứ hai là $n$ số nguyên $a_1, a_2, a_3, \dots, a_n$.
- Dòng thứ ba là số nguyên dương $m$ - số lượng phần tử trong tập $B$.
- Dòng cuối cùng là $m$ số nguyên $b_1, b_2, b_3, \dots, b_m$.

## Constraints

- $1 \le n, m \le 10^5$.
- $-10^3 \le a_i, b_j \le 10^3$.

## Subtasks

- Subtask $1$ ($25\%$ số điểm): có
    - $1 \le n, m \le 100$.
    - $-50 \le a_i, b_j \le 50$.
- Subtask $2$ ($75\%$ số điểm): không có ràng buộc gì thêm.

## Output

- Một số nguyên duy nhất là giá trị $p$ cần tìm.

## Sample Input

```
7
1 2 3 4 5 6 7
5
3 4 6 2 9
```

## Sample Output

```
4
```

## Explanation

Dãy $A$ có các phần tử: $1, 2, 3, 4, 5, 6, 7$.
Dãy $B$ có các phần tử: $3, 4, 6, 2, 9$.
Vậy trong dãy $A$ đã có các phần tử $3, 4, 6, 2$ xuất hiện trong dãy $B$.
Do đó đáp án bài toán là $4$.
