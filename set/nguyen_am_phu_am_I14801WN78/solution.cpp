#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int cnt, flag;
    set < char > st;
    cin >> s;
    s += '0';
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'o' && s[i]!= 'u' && s[i] != 'i' && s[i] != '0') {
            st.insert(s[i]);
            if (cnt >= 3) flag = 1;
            cnt = 0;
        }
        else cnt++;
    }

    if (flag && (int)st.size() >= 5) cout << "YES\n";
    else cout<< "NO\n";
    return 0;
}
