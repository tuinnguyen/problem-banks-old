# Phần tử nhỏ hơn - Editorial

## Subtask 1

Với mỗi phần tử $A_i$ trong đoạn $[1, \dots, n]$, ta sẽ duyệt qua từng phần tử $A_j$ trong nữa khoảng $[1, \dots, i)$ để tìm ra được một giá trị $A_j$ lớn nhất sao cho $A_j < A_i$.

Độ phức tạp: $O(n^2)$.

## Subtask 2

Thay vì phải duyệt từng phần tử $A_j$ trong đoạn $[1, \dots, i]$ như trên, ta sẽ đưa các giá trị $A_i$ vào một `set` và sắp xếp chúng lại theo giá trị tăng hoặc giảm dần. Khi đó ta chỉ cần tìm kiếm nhị phân trên `set` đó để tìm ra phần tử có giá trị nhỏ hơn $A_i$.

Độ phức tạp: $O(n \log n)$.
