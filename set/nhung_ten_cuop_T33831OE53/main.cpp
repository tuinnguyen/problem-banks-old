#include <bits/stdc++.h>
#include "random-functions.h"

using namespace std;

// ! | Setting's configurations start below.

const int DATE = 01;
const int NUMBER_OF_TESTCASES = 20;
const bool ZIP_TESTCASES = true;
const bool REMOVE_TESTCASES_AFTER_ZIP = true;

// ! | Setting's configurations end above.



// ! | Functions begin below

// * | Write input generate code here

bool user_exist(vector < string > users, string target) {
    if ((int)users.size() == 0) return false;
    for (string user: users) {
        if (target == user) return true;
    }
    return false;
}

void gen_input(const int test_number, ofstream &cout) {
    int min_n, max_n, min_len, max_len;

    if (test_number <= 10) {
        min_n = 5;
        max_n = 100;
        min_len = 4;
        max_len = 30;
    }
    else {
        min_n = 100;
        max_n = 10000;
        min_len = 10;
        max_len = 1000;
    }

    int n = rand_int(min_n, max_n);
    int m = rand_int(1, n);
    vector < string > users;
    for (int i = 0; i < n; ++i) {
        string user = "";
        do {
            user = rand_str(rand_int(min_len, max_len));
        } while (user_exist(users, user));
        users.push_back(user);
    }
    vector < int > indices = rand_list(m, 0, n - 1, true);
    cout << n << "\n";
    for (string user: users) cout << user << "\n";
    cout << m << "\n";
    for (int index: indices) {
        int flag = rand_int(0, 1);
        if (flag) cout << users[index] << "\n";
        else {
            cout << rand_str(rand_int(min_len, max_len)) << "\n";
        }
    }
}


// * | Paste "int main() {}" in your solution here and rename "gen_output()" and other functions in your code (if needed) above
// * | Aware DO NOT RETURN 0! Just "return;" or return nothing.
void gen_output(ifstream &cin, ofstream &cout) {
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