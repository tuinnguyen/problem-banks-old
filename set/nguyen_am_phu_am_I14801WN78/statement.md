# Nguyên âm phụ âm

Một chuỗi được gọi là "hợp lệ" là một chuỗi có ít nhất $3$ nguyên âm liên tiếp và ít nhất $5$ phụ âm khác nhau. 

Ví dụ, với chuỗi `ACQUAINTANCES` là chuỗi "hợp lệ", vì nó chứa $3$ nguyên âm liên tiếp `U`, `A`, `I` và $5$ phụ âm khác nhau `C`, `Q`, `N`, `T`, `S` nhưng `ACQUAINT` thì không, vì nó chứa $3$ nguyên âm nhưng chỉ có $4$ phụ âm khác nhau `C`, `Q`, `N`, `T`.

***Yêu cầu:*** Kiểm tra xem chuỗi $S$ có phải là chuỗi "hợp lệ" hay không.

## Input

- Một chuỗi chỉ gồm các kí tự viết thường trong bảng chữ cái tiếng Anh.

## Constraints

- $8 \le |S| \le 10^5$.

## Subtasks

- Subtask $1$ ($25\%$ số điểm): có $1 \le |S| \le 15$.
- Subtask $2$ ($75\%$ số điểm): không có ràng buộc gì thêm.

## Output

- Xuất ra màn hình `YES` nếu chuỗi đầu vào là chuỗi "hợp lệ", ngược lại, in ra `NO`. 

## Sample Input

```
ACQUAINTANCES
```

## Sample Output

```
YES
```