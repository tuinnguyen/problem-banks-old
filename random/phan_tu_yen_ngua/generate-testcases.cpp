#include <bits/stdc++.h>
#include "random-functions.h"

using namespace std;

// ! | Setting's configurations start below.

const int DATE = 07;
const int NUMBER_OF_TESTCASES = 20;
const bool REMOVE_TRASH = true;
const bool ZIP_TESTCASES = true;
const bool REMOVE_TESTCASES_AFTER_ZIP = true;
const bool ANSWER_LOG = false;
const bool ZIP_LOGS = false;
const bool REMOVE_LOGS = true;

// ! | Setting's configurations end above.



// ! | Functions begin below

// * | Write input generate code here
bool cmp(int a, int b) {
    return (a > b);
}

void gen_input(const int test_number, ofstream &cout) {
    int min_n, max_n, min_m, max_m, min_value, max_value;

    if (test_number) {
        min_n = 5;
        max_n = 10;
        min_m = 5;
        max_m = 10;
        min_value = -100;
        max_value = 100;
    }
    else {
        min_n = 50;
        max_n = 100;
        min_m = 50;
        max_m = 100;
        min_value = -10000;
        max_value = 10000;
    }

    int n, m;
    do {
        n = rand_int(min_n, max_n);
        m = rand_int(min_m, max_m);
    } while (n % 2 == 0 or m % 2 == 0);

    cout << n << " " << m << "\n";

    vector < vector < int > > res;

    for (int i = 1; i <= n; ++i) {
        vector < int > a = rand_list(m, min_value, max_value, true);
        sort(a.begin(), a.end(), cmp);
        vector < int > b;
        for (int i = m / 2; i < m; ++i) b.push_back(a[i]);
        for (int i = m / 2 - 1; i >= 0; --i) b.push_back(a[i]);
        res.push_back(b);
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n / 2; ++i) {

        }
    }

    for (vector < int > row: res) {
        for (int item: row) {
            cout << item << " ";
        }
        cout << "\n";
    }
}


// * | Paste "int main() {}" in your solution here and rename "gen_output()" and other functions in your code (if needed) above
// * | Aware DO NOT RETURN 0! Just "return;" or return nothing.
void gen_output(ifstream &cin, ofstream &cout, ofstream &log) {
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
                return;
            }
        }
    }
    cout << "-1" << "\n";
    return;
}

// ! | Functions end above


void UCODE(int test_number) {
    string txt = "";
    string logs = "";

    ifstream get_input((to_string(test_number) + ".in").c_str());
    ifstream get_output((to_string(test_number) + ".out").c_str());
    ifstream get_logs((to_string(test_number) + ".txt").c_str());
    ofstream print("testcases.txt", std::ofstream::app);
    ofstream log("testcases-log.txt", std::ofstream::app);

    //  * | Making Input
    while (get_input.eof() == false) {
        getline(get_input, txt);
        logs = txt;
        if (get_input.eof()) break;
        print << txt << "\n";
        log << txt << "\n";
    }
    get_input.close();

    print << "---\n";
    log << "---\n";


    //  * | Making Output
    while (get_output.eof() == false) {
        getline(get_output, txt);
        logs = txt;
        if (get_output.eof()) break;
        print << txt << "\n";
        log << txt << "\n";
    }

    log << "---logs---\n";


    //  * | Making answer's logs
    while (get_logs.eof() == false) {
        getline(get_logs, logs);
        if (get_logs.eof()) break;
        log << logs << "\n";
    }

    get_output.close();
    print.close();
    get_logs.close();
    log.close();
    return;
}


int main() {
    srand(time(NULL));

    cerr << "Generate " << NUMBER_OF_TESTCASES << " testcases!\n\n";

    system("rm testcases.txt");
    system("touch testcases.txt");
    cerr << "testcases.txt created!\n\n";

    if (ANSWER_LOG) {
        system("rm testcases-log.txt");
        system("touch testcases-log.txt");
        cerr << "testcases-log created!\n\n";
    }

    for (int index = 1; index <= NUMBER_OF_TESTCASES; index++) {
        cerr << "Generating test " << index << " - th!\n";

        //  * | Making inputs
        ofstream input_source ((to_string(index) + ".in").c_str());

        gen_input(index, input_source);

        input_source.close();


        //  * | Making Outputs
        ifstream inputs ((to_string(index) + ".in").c_str());
        ofstream answer_source ((to_string(index) + ".out").c_str());
        ofstream answer_log ((to_string(index) + ".txt").c_str());

        gen_output(inputs, answer_source, answer_log);

        inputs.close();
        answer_source.close();
        answer_log.close();


        //  * | Making Ucode's format
        ofstream ucode_output("testcases.txt", std::ofstream::app);
        ofstream ucode_log("testcases-log.txt", std::ofstream::app);

        string test_alert = "### Test #" + format_number(index, NUMBER_OF_TESTCASES);

        ucode_output << test_alert << "\n";
        ucode_log << test_alert << "\n";

        ucode_output.close();
        ucode_log.close();
        UCODE(index);


        cerr << "Complete test " << index << " - th!\n---\n";
    }

    //  * | Making a list of files including .in and .out files
    string files = "", log_files = "";
    for (int index = 1; index <= NUMBER_OF_TESTCASES; index++) {
        files += to_string(index) + ".in " + to_string(index) + ".out ";
        log_files += to_string(index) + ".txt ";
    }


    //  * | Zip files
    if (ZIP_TESTCASES) system(("zip testcases.zip " + files).c_str());
    if (ZIP_LOGS) system(("zip testcases-log.zip " + log_files).c_str());


    //  * | Remove files
    if (REMOVE_TESTCASES_AFTER_ZIP) system(("rm " + files).c_str());
    if (REMOVE_LOGS) system(("rm " + log_files).c_str());


    //  * | Remove trash
    if (REMOVE_TRASH) system("rm solution generate-testcases input.txt");


    cerr << "\n" << NUMBER_OF_TESTCASES << " testcases is generated!\n\n";
    cerr << "Process completed!\n\n";
    cerr << "Problem ID: " << id_generate(DATE) << "\n\n";

    return 0;
}
