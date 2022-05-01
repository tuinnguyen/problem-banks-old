# Lẻ loi

Một lớp có $n$ học sinh được chia thành $m$ nhóm được đánh số từ $1$ đến $m$ và nhóm thứ $i$ có số hiệu $b_i$, mỗi nhóm đúng $k$ học sinh. $n$ học sinh được đánh số từ $1$ đến $n$ và học sinh thứ $i$ có nhóm $a_i$. Song, không may thay có đúng $1$ học sinh không thuộc nhóm nào, học sinh này được xếp vào một nhóm đặc biệt với giáo viên là nhóm có số hiệu $q$.

***Yêu cầu:*** Biết danh sách nhóm của $n$ học sinh kia và số nguyên dương $k$ hãy tìm giá trị $q$.

## Input

- Dòng đầu tiên là số nguyên dương $k$.
- Dòng tiếp theo gồm $n$ số nguyên dương $a_1, a_2, a_3, \dots, a_n$ là số nhóm của học sinh thứ $i$.

## Constraints

- $1 \le k \le 1000$.
- $1 \le a_i \le 10000$.

## Subtasks

- Subtask $1$ ($25\%$ số điểm): có giáo viên ở nhóm $k + 1$.
- Subtask $2$ ($75\%$ số điểm): không có ràng buộc gì thêm.

## Output

- Một số nguyên duy nhất là giá trị $q$ cần tìm.

## Sample Input

```
4
1 1 1 1 2 2 2 2 3 3 3 3 10
```

## Sample Output

```
4
```

## Explanation

Ta thấy chỉ có nhóm số $10$ không có đủ $4$ thành viên nên chắc chắn học sinh này sẽ được ghép với giáo viên.
