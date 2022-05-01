#include <bits/stdc++.h>
#include "random-functions.h"

using namespace std;

// ! | Setting's configurations start below.

const int DATE = 01;
const int NUMBER_OF_TESTCASES = 40;
const bool ZIP_TESTCASES = true;
const bool REMOVE_TESTCASES_AFTER_ZIP = true;

// ! | Setting's configurations end above.



// ! | Functions begin below

// * | Write input generate code here
void gen_input(const int test_number, ofstream &cout) {
    int min_n, max_n, min_value, max_value;

    if (test_number <= 10) {
        min_n = 10;
        max_n = 20;
        min_value = 10;
        max_value = 30;
    }
    else {
        min_n = 1000;
        max_n = 10000;
        min_value = 1000;
        max_value = 100000;
    }

    int n = rand_int(min_n, max_n), p = rand_int(5, n), q = rand_int(5, n);
    vector < int > x = rand_list(n, min_value, max_value, true);
    vector < int > a = rand_list(p, min_value, max_value, true);
    vector < int > b = rand_list(q, min_value, max_value, true);
    cout << n << "\n";
    print_vector(x, cout);
    cout << p << "\n";
    print_vector(a, cout);
    cout << q << "\n";
    print_vector(b, cout);
}


// * | Paste "int main() {}" in your solution here and rename "gen_output()" and other functions in your code (if needed) above
// * | Aware DO NOT RETURN 0! Just "return;" or return nothing.
void gen_output(ifstream &cin, ofstream &cout) {
    int n, p, q;
    cin >> n;
    set < int > x, a, b;
    vector < int > ans;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        x.insert(value);
    }
    cin >> p;
    for (int i = 0; i < p; ++i) {
        int value;
        cin >> value;
        a.insert(value);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int value;
        cin >> value;
        b.insert(value);
    }
    for (int item: b) {
        if (a.count(item)) {
            ans.push_back(item);
        }
    }
    if (ans.size()) {
        cout << ans.size() << "\n";
        for (int i = 0; i < (int)ans.size() - 1; ++i) {
            cout << ans[i] << " ";
        }
        cout << ans.back() << "\n";
    }
    else {
        cout << -1 << "\n";
    }
    ans.clear();

    for (int item: x) {
        if (a.count(item) == 0 and b.count(item) == 0) {
            ans.push_back(item);
        }
    }
    if (ans.size()) {
        cout << ans.size() << "\n";
        for (int i = 0; i < (int)ans.size() - 1; ++i) {
            cout << ans[i] << " ";
        }
        cout << ans.back() << "\n";
    }
    else {
        cout << -1 << "\n";
    }
}

// ! | Functions end above


void UCODE(int test_number) {
    string txt = "";

    ifstream get_input((to_string(test_number) + ".in").c_str());
    ifstream get_output((to_string(test_number) + ".out").c_str());
    ofstream print("testcases.txt", std::ofstream::app);

    //  * | Making Input
    while (get_input.eof() == false) {
        getline(get_input, txt);
        if (get_input.eof()) break;
        print << txt << "\n";
    }
    get_input.close();

    print << "---\n";

    //  * | Making Output
    while (get_output.eof() == false) {
        getline(get_output, txt);
        if (get_output.eof()) break;
        print << txt << "\n";
    }
    get_output.close();
    print.close();
    return;
}


int main() {
    srand(time(NULL));

    cerr << "Generate " << NUMBER_OF_TESTCASES << " testcases!\n\n";

    system("rm testcases.txt");
    system("touch testcases.txt");
    cerr << "testcases.txt created!\n\n";

    for (int index = 1; index <= NUMBER_OF_TESTCASES; index++) {
        cerr << "Generating test " << index << " - th!\n";

        // * | Making inputs
        ofstream input_source ((to_string(index) + ".in").c_str());
        gen_input(index, input_source);
        input_source.close();

        // * | Making Outputs
        ifstream inputs ((to_string(index) + ".in").c_str());
        ofstream answer_source ((to_string(index) + ".out").c_str());
        gen_output(inputs, answer_source);
        inputs.close();
        answer_source.close();

        // * | Making Ucode's format
        ofstream ucode_output("testcases.txt", std::ofstream::app);
        string test_alert = "### Test #" + format_number(index, NUMBER_OF_TESTCASES);
        ucode_output << test_alert << "\n";
        ucode_output.close();
        UCODE(index);

        cerr << "Complete test " << index << " - th!\n---\n";
    }

    // * | Making a list of files including .in and .out files
    string files = "";
    for (int index = 1; index <= NUMBER_OF_TESTCASES; index++) {
        files += to_string(index) + ".in " + to_string(index) + ".out ";
    }

    // * | Zip files
    if (ZIP_TESTCASES) system(("zip testcases.zip " + files).c_str());

    // * | Remove files
    if (REMOVE_TESTCASES_AFTER_ZIP) system(("rm " + files).c_str());
    cerr << "\n" << NUMBER_OF_TESTCASES << " testcases is generated!\n\n";

    cerr << "Process completed!\n\n";

    cerr << "Problem ID: " << id_generate(DATE) << "\n\n";

    return 0;
}