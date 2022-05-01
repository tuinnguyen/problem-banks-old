# Dãy bậc thang

Tí rất thích các dãy số nguyên. Cậu ấy đặc biệt thích các dãy số bậc thang. Dãy $a_1, a_2, ..., a_n$ với $n$ là số phần tử của dãy $a$ là dãy bậc thang nếu với $i$ $(1 \le i \le n)$ thỏa mãn điều kiện sau: $a_1 < a_2 < ... < a_{i - 1} < a_i > a_{i + 1}> ... > a_{n - 1} > a_n$. Ví dụ, dãy $[1, 2, 3, 2]$ và $[4, 2]$ là dãy bậc thang còn dãy $[3, 1, 2]$ thì không.

Để khoảng thời gian giãn cách do đại dịch COVID-19 không nhàm chán, Tí đã đưa ra một thử thách cho Tèo - bạn thân của cậu ấy. Nhiệm vụ của Tèo là tạo ra một dãy số bậc thang có độ dài lớn nhất từ dãy số $a$ gồm $n$ phần tử mà Tí cung cấp. 

***Yêu cầu:*** Bạn hãy giúp Tèo hoàn thành thử thách này.

## Input

- Dòng đầu tiên chứa số nguyên $n$ là số lượng phần tử của dãy số mà Tí cung cấp.
- Dòng tiếp theo gồm $n$ số nguyên $a_1, a_2, ..., a_n$ là các phần tử trong dãy số của Tí.

## Constraints

- $1 \le n \le 10^5$.
- $1 \le a_i \le 500$.

## Output

In ra trên một dòng một số nguyên là số phần tử của dãy số bậc thang có độ dài lớn nhất mà Tèo tạo được.

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

Dãy bậc thang mà tèo có thể tạo được là $[1, 2, 3, 2, 1]$. 
