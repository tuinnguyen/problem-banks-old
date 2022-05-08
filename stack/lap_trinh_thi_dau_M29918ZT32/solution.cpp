#include <bits/stdc++.h>

using namespace std;

int main() {
    int queries;
    cin >> queries;

    stack < int > st;

    for (int qq = 0; qq < queries; ++qq) {
        char type;
        cin >> type;
        if (type == '+') {
            int value;
            cin >> value;
            if (st.empty()) {
                st.push(value);
            }
            else {
                int new_max = max(st.top(), value);
                st.push(new_max);
            }
        }
        else if (type == '-') {
            if (st.empty() == false) {
                st.pop();
            }
        }
        else if (type == '?') {
            if (st.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << st.top() << "\n";
            }
        }
    }
}