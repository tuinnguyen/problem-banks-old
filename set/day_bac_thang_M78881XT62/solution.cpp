#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, num[100005];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> num[i];
    
    sort(num + 1,num + n + 1);
    int largest = num[n];
    
    set < int > first, second;
    second.insert(largest);
    for (int i = n - 1; i >= 1; i--) {
        if (num[i] != largest) {
            if (num[i + 1] == num[i]) first.insert(num[i]);
            else second.insert(num[i]);
        }
    }

    vector < int > ans;
    for (auto it = first.begin(); it != first.end(); it++) ans.push_back(*it);
    for (auto it = prev(second.end()); it != second.begin(); it--) ans.push_back(*it);

    auto it = second.begin();
    ans.push_back(*it);

    cout << ans.size();
    return 0;
}
