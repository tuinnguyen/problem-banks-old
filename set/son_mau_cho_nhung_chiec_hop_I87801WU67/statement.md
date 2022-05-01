# Sơn màu cho những chiếc hộp

Tí có $n$ chiếc hộp và cậu ấy quyết định sơn màu cho chúng.

Cậu ấy muốn chọn $w$ cái hộp liền kề nhau và tặng nó cho Tèo vào ngày sinh nhật của anh ấy. Tí muốn tất cả các hộp $w$ mà anh ấy tặng có cùng màu sơn. Cậu ấy sơn màu lại cho một số cái hộp và tự hỏi rằng có bao nhiêu cách để tặng $w$ cái hộp cho Tèo.

***Yêu cầu:*** Hãy giúp Tí tính số cách để tặng $w$ cái hộp cho Tèo.

## Input

- Dòng đầu tiên là số nguyên $t$ chỉ số lượng truy vấn.
- Với mỗi truy vấn gồm:
    - Dòng đầu tiên gồm hai số nguyên $n, w$ chỉ số lượng chiếc hộp và số lượng hộp liền kề nhau mà Tí muốn tặng cho Tèo.
    - Dòng thứ hai gồm $n$ số nguyên $A_1, A_2, ..., A_n$ chỉ màu ban đầu của những cái hộp.
    - Dòng thứ ba chứa một số nguyên $q$ biểu thị số lần Tí sơn lại một cái hộp. 
    - $q$ dòng tiếp theo mỗi dòng chứa hai số nguyên $Pos_i$ và $Col_i$ nghĩa là hộp tại vị trí $Pos$ đã được sơn lại bằng màu $Col$.

## Constraints

- $1 \le t \le 10$.
- $1 \le w, Pos \le n$.
- $1 \le A_i, Col \le 10^9$.

## Subtasks

- Subtask 1 ($30\%$ số điểm): 
    - $1 \le q \le 10^3$.
    - $1 \le n \le 10^4$.
    
- Subtask 2 ($70\%$ số điểm còn lại): 
    - $1 \le q \le 10^4$.
    - $1 \le n \le 10^5$.

## Output

Sau mỗi truy vấn sơn màu lại, xuất ra số cách Tí có thể tặng Tèo $w$ cái hộp liền kề cùng màu.

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

- Sau lần sơn lại thứ nhất, các hộp có màu $[1,1,1,1]$, nghĩa là có $3$ cách chọn $2$ hộp liền nhau cùng màu.
- Sau lần sơn lại thứ hai, các hộp có màu $[2,1,1,1]$, nghĩa là có $2$ cách chọn $2$ ô liền nhau cùng màu.
- Sau khi sơn lại thứ ba, các hộp có màu $[2,2,1,1]$, nghĩa là có $2$ cách chọn $2$ hộp liền nhau cùng màu.
