#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector < int > a(n);
    for (int &item: a) cin >> item;
    cin >> m;
    vector < int > b(n);
    for (int &item: b) cin >> item;

    set < int > data;
    for (int item: b) data.insert(item);
    int p = data.size();
    for (int item: a) data.insert(item);
    cout << n - (data.size() - p) << "\n";
}