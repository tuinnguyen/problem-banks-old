# Lênh đênh trên biển - Editorial

Để tối ưu diện tích của cái bè, Tuân sẽ xếp các miếng gỗ theo chiều dọc. Như vậy, ta có nhận xét: diện tích của miếng gỗ thứ $i$ đến miếng gỗ thứ $j$ và chiều cao của miếng gỗ thấp nhất từ miếng gỗ thứ $i$ đến miếng gỗ thứ $j$ là $h$. Khi đó diện tích của hình chữ nhật lớn nhất sẽ là: $S = (j - i + 1) \times h$.

Gọi $f(i)$ là vị trí của miếng gỗ có chiều cao thấp hơn miếng gỗ thứ $i$, nằm bên trái và gần $i$ nhất.
Gọi $g(i)$ là vị trí của miếng gỗ có chiều cao thấp hơn miếng gỗ thứ $i$, nằm bên phải và gần $i$ nhất.

Dựa vào nhận xét trên và cách định nghĩa $f(i)$ và $g(i)$. Ta sẽ xét các miếng gỗ từ $1$ đến $n$, sau đó diện tích của hình chữ nhật lớn nhất như nhận xét trên sẽ là $(g(i) - f(i) - 1) * h_i$. Ta sẽ liên tục cập nhật kết quả với diện tích của hình chữ nhật hiện tại đang xét.
