#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long int a[100005];
    set < long long > s;
    set < long long > :: iterator it; 
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        it = s.lower_bound(a[i]);
        if (it == s.begin()) cout << "-1\n";
        else {
            --it;
            cout << *it << "\n";
        }
        s.insert(a[i]);
    }
}
