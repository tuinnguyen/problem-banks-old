#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    set < int > pos, neg;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int value;
        cin >> value;
        if (value > 0) pos.insert(value);
        else if (value < 0) neg.insert(value);
    }
    int s1 = 0, s2 = 0;
    for (int item: pos) s1 += item;
    for (int item: neg) s2 += item;
    cout << s1 << "\n" << s2 << "\n";
}