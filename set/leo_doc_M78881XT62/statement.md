# Leo dốc

Một con dốc nhân tạo có chiều dài $n$ và có các chiều cao: $a_1, a_2, a_3, \dots, a_n$ với $a_i$ là chiều cao của cột thứ $i$. Nghĩa là mỗi cột có diện tích $1 \times 1$ và chiều cao $a_i$. Có $m$ cột với các chiều cao $a_1, a_2, a_3, \dots, a_m$. Cần phải sắp xếp thành một con dốc thỏa mãn tính chất sau: $a_1 < a_2 < a_3 < \dots < a_{i - 1} < a_i < a_{i + 1} < \dots < a_{n - 2} < a_{n - 1} < a_n$.

***Yêu cầu:*** Từ $m$ cột cho trước hay sắp xếp tạo thành dốc thỏa tính chất trên sao cho chiều dài con dốc là dai nhất.

## Input

- Dòng đầu tiên chứa số nguyên dương $m$ - số lượng cột.
- Dòng thứ hai chứa các số nguyên $a_1, a_2, a_3, \dots, a_m$ - chiều cao của cột thứ $i$.

## Constraints

- $1 \le n \le 10^5$.
- $1 \le a_i \le 500$.

## Output

- Một số nguyên duy nhất là chiều dài của con dốc dài nhất có thể tạo được.

## Sample Input

```
6
1 1 2 2 3 3
```

## Sample Output

```
5
```

## Explanation

Một con dốc có chiều dài $5$ là: $1, 2, 3, 2, 1$. Con dốc $1, 2, 3, 3, 2, 1$ không hợp lệ.
