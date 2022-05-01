# Tổng dương âm

Một dãy số $A$ gồm các số nguyên $a_1, a_2, a_3, \dots, a_n$.

***Yêu cầu:*** Tính tổng $s_1$ của các số nguyên dương phân biệt và tổng $s_2$ các số nguyên âm phân biệt.

## Input

- Dòng đầu tiên là số nguyên dương $n$.
- Dòng thứ hai là $n$ số nguyên $a_1, a_2, a_3, \dots, a_n$.

## Constraints

- $1 \le n \le 10^5$.
- $-10^4 \le a_i \le 10^4$.

## Subtasks

- Subtask $1$ ($25\%$ số điểm): có
    - $1 \le n \le 30$.
    - $-50 \le a_i \le 50$.
- Subtask $2$ ($75\%$ số điểm): không có ràng buộc gì thêm.

## Output

- Dòng đầu tiên là tổng $s_1$.
- Dòng thứ hai là tổng $s_2$.

## Sample Input

```
5
-1 -32 4 21 2
```

## Sample Output

```
27
-33
```

## Explanation

$s_1 = 4 + 21 + 2 = 27$.
$s_2 = -1 + (-32) = -33$.