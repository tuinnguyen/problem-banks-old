# Giao và phần bù của giao

Một không gian nghiệm có $n$ nghiệm phân biệt $x_1, x_2, x_3, \dots, x_n$. Tập hợp $A$ có $p$ phần tử $a_1, a_2, a_3, \dots, a_p$ thuộc không gian nghiệm trên. Tương tự có tập hợp $B$ có $q$ phần tử $b_1, b_2, b_3, \dots, b_q$ thuộc không gian nghiệm trên. Biết các phần tử trong không gian nghiệm, tập hợp $A$ và tập hợp $B$.

***Yêu cầu:*** Đưa ra danh sách các phần tử thuộc cả hai tập $A$ và $B$ và các phần tử không thuộc trong cả hai tập $A$ và $B$.

## Input

- Dòng đầu tiên là số nguyên dương $n$.
- Dòng tiếp theo là $n$ số nguyên $x_1, x_2, x_3, \dots, x_n$.
- Dòng tiếp theo là số nguyên dương $p$.
- Dòng tiếp theo là $p$ số nguyên $a_1, a_2, a_3, \dots, a_p$.
- Dòng tiếp theo là số nguyên dương $q$.
- Dòng tiếp theo là $q$ số nguyên $b_1, b_2, b_3, \dots, b_q$.

## Constraints

- $1 \le p \le q \le n \le 10^4$.
- $1 \le x_i, a_j, b_k \le 10^5$.

## Subtasks

- Subtask $1$ ($25\%$ số điểm): có
    - $1 \le p \le q \le n \le 100$.
    - $1 \le x_i, a_j, b_k \le 500$.
- Subtask $2$ ($75\%$ số điểm): không có ràng buộc gì thêm.

## Output

- Dòng đầu tiên là số nguyên dương $h$ - số phần tử thuộc cả hai tập $A$ và $B$. Nếu không có phần tử nào thì in $-1$.
- Dòng tiếp theo là $h$ số nguyên thỏa mãn. Nếu không có phần tử nào thỏa mãn không in gì cả.
- Dòng tiếp theo là số nguyên dương $k$ - số phần tử không thuộc cả hai tập $A$ và $B$. Nếu không có phần tử nào thì in $-1$.
- Dòng cuối cùng là $k$ số nguyên thỏa mãn. Nếu không có phần tử nào thỏa mãn không in gì cả.

## Sample Input

```
5
1 2 3 4 5
3
1 2 4
3
2 4 5
```

## Sample Output

```
2
2 4
1
3
```
