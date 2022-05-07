#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector < int > a(n);    // n = 5 -> a = ([0], [1], [2], [3], [4])
    for (int &item: a) cin >> item; // a = {1, 2, 3, 4, 5}
    cin >> m;
    vector < int > b(m);    // m = 6 -> b = ([0], [1], [2], [3], [4], [5])
    for (int &item: b) cin >> item; // b = {2, 4, 6, 8, 10, 12}

    set < int > data;
    for (int item: b) data.insert(item);
    int p = data.size();
    for (int item: a) data.insert(item);
    cout << n - (data.size() - p) << "\n";
}