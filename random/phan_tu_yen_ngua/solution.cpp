#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int > > a(n, vector < int > (m));

    for (vector < int > &row: a) {
        for (int &item: row) {
            cin >> item;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int min_index = 0, max_index = 0;
            for (int r = 1; r < n; ++r) {
                if (a[min_index][j] < a[r][j]) min_index = r;
            }
            for (int c = 1; c < m; ++c) {
                if (a[i][max_index] > a[i][c]) max_index = c;
            }
            
            if (min_index == i and max_index == j) {
                cout << min_index << " " << max_index << "\n";
                return 0;
            }
        }
    }
    cout << "-1" << "\n";
}