#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector < string > users(n);
    for (string &user: users) cin >> user;
    int m;
    cin >> m;
    set < string > thieves;
    for (int i = 0; i < m; ++i) {
        string thief;
        cin >> thief;
        thieves.insert(thief);
    }
    int counter = 0;
    for (string user: users) {
        if (thieves.count(user)) counter++;
    }
    cout << counter << "\n";
}