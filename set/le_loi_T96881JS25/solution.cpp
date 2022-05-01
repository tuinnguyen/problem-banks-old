#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, value;
    cin >> k;
    vector < int > a;
    set < int > b;
    while (cin >> value) {
        a.push_back(value);
        b.insert(value);
    }

    int ans = 0;
    for (int item: b) {
        int counter = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            if (item == a[i]) counter++;
        }
        if (counter != 4) ans = item;
    }
    cout << ans << "\n";
}