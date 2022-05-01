#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector < int > a(n);
    for (int &item: a) cin >> item;

    set < int > values;
    for (int item: a) values.insert(item);

    cout << values.size() << "\n";
    vector < int > items;
    for (int value: values) items.push_back(value);
    for (int i = 0; i < (int)items.size() - 1; ++i) {
        cout << items.at(i) << " ";
    }
    cout << items.back() << "\n";

    // from line 15 - 20 you can minimize like this
    // for (int value: values) cout << value << " ";
    // cout << "\n";
}