# Phần tử nhỏ hơn

Bạn được cung cấp một mảng $A$ gồm $n$ phần tử.

***Yêu cầu:*** Với mỗi phần tử $A_i$, bạn cần tìm ra phần tử $A_j$ lớn nhất, trong đó $1 \le j < i \le n$ và $A_j < A_i$.

## Input

- Dòng đầu tiên chứa số nguyên $n$ chỉ số phần tử của mảng $A$.
- Dòng thứ hai gồm $n$ số nguyên phân biệt phân cách bởi dấu cách chỉ các phần tử của mảng $A$.

## Constraints

- $1 \le n \le 10^5$.
- $1 \le A_i \le 10^{15}$.

## Subtasks

- Subtask 1 ($30\%$ số điểm): $1 \le n \le 1000$.
- Subtask 2 ($70\%$ số điểm còn lại) không có ràng buộc gì thêm.

## Output

Xuất ra màn hình $n$ dòng với mỗi dòng là một giá trị thoã điều kiện của bài. Nếu không thoã điều kiện, xuất ra màn hình $-1$.

## Sample Input

```
5
1 2 3 5 4
```

## Sample Output

```
-1
1
2
3
3
```
