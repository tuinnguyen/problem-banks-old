# Những tên cướp

Một băng cướp có $m$ tên cướp khác nhau đang lẫn trốn vào $n$ người trong một khu mua sẵm. Các đặc vụ đã rất xuất sắc tìm ra tên của $m$ tên cướp này và thu thập được tên thật của những người ở trong khu mua sắm nhờ nghiệp vụ đặc cảnh. Lưu ý, mỗi người đều có một cái tên khác nhau.

***Yêu cầu:*** Biết tên của những tên cướp và những người trong khu mua sắm, đưa ra số tên trộm đang lẫn trốn trong khu mua sắm.

## Input

- Dòng đầu tiên là số nguyên dương $n$.
- $n$ dòng tiếp theo, mỗi dòng là tên của một người trong khu mua sắm.
- Dòng tiếp theo là số nguyên dương $m$.
- $m$ dòng tiếp theo, mỗi dòng là tên của một tên cướp trong băng cướp.

## Constraints

- $1 \le n, m \le 10^5$.
- Độ dài của các tên không quá $1000$ kí tự và chỉ gồm các kí tự latin in thường.

## Subtasks

- Subtask $1$ ($25\%$ số điểm): có $1 \le n, m \le 100$.
- Subtask $2$ ($75\%$ số điểm): không có ràng buộc gì thêm.

## Output

- Một số nguyên duy nhất là số lượng tên cướp lẫn trốn trong $n$ người ở khu mua sắm.

## Sample Input

```
5
joe
jessy
john
lennon
sammy
3
joe
john
jes
```

## Sample Output

```
2
```
