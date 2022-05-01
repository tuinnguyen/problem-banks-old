#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p, q;
    cin >> n;
    set < int > x, a, b;
    vector < int > ans;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        x.insert(value);
    }
    cin >> p;
    for (int i = 0; i < p; ++i) {
        int value;
        cin >> value;
        a.insert(value);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int value;
        cin >> value;
        b.insert(value);
    }
    for (int item: b) {
        if (a.count(item)) {
            ans.push_back(item);
        }
    }
    if (ans.size()) {
        cout << ans.size() << "\n";
        for (int i = 0; i < (int)ans.size() - 1; ++i) {
            cout << ans[i] << " ";
        }
        cout << ans.back() << "\n";
    }
    else {
        cout << -1 << "\n";
    }
    ans.clear();

    for (int item: x) {
        if (a.count(item) == 0 and b.count(item) == 0) {
            ans.push_back(item);
        }
    }
    if (ans.size()) {
        cout << ans.size() << "\n";
        for (int i = 0; i < (int)ans.size() - 1; ++i) {
            cout << ans[i] << " ";
        }
        cout << ans.back() << "\n";
    }
    else {
        cout << -1 << "\n";
    }
}