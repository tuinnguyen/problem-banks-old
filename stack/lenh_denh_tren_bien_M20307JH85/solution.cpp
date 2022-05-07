#include <bits/stdc++.h>

using namespace std;

vector < long long > calculate_left(vector < long long > a) {
    stack < long long > st;
    vector < long long > res;
    for (int i = 0; i < a.size(); ++i) {
        while (st.empty() == false and a[st.top()] >= a[i]) st.pop();
        int ans = -1;
        if (st.empty() == false) ans = st.top();
        res.push_back(ans);
        st.push(i);
    }
    return res;
}

vector < long long > calculate_right(vector < long long > a) {
    stack < long long > st;
    vector < long long > res;
    for (int i = a.size() - 1; i >= 0; i--) {
        while (st.empty() == false and a[st.top()] >= a[i]) st.pop();
        int ans = a.size();
        if (st.empty() == false) ans = st.top();
        res.push_back(ans);
        st.push(i);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;
    vector < long long > a(n);
    for (long long &item: a) cin >> item;

    vector < long long > left = calculate_left(a), right = calculate_right(a);

    long long ans = -1;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, (right[i] - left[i] - 1) * a[i]);
    }
    cout << ans << "\n";
}