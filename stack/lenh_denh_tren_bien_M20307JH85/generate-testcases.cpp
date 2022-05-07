#include <bits/stdc++.h>
#include "random-functions.h"

using namespace std;

// ! | Setting's configurations start below.

const int DATE = 07;
const int NUMBER_OF_TESTCASES = 40;
const bool ZIP_TESTCASES = true;
const bool REMOVE_TESTCASES_AFTER_ZIP = true;
const bool ANSWER_LOG = true;
const bool ZIP_LOGS = true;
const bool REMOVE_LOGS = true;

// ! | Setting's configurations end above.



// ! | Functions begin below

// * | Write input generate code here
void gen_input(const int test_number, ofstream &cout) {
    int min_n, max_n, min_value, max_value;

    if (test_number <= 10) {
        min_n = 5;
        max_n = 20;
        min_value = 1;
        max_value = 50;
    }
    else {
        min_n = 1000;
        max_n = 100000;
        min_value = 1000;
        max_value = 1000000000;
    }

    int n = rand_int(min_n, max_n);
    cout << n << "\n";
    vector < int > a = rand_list(n, min_value, max_value);
    print_vector(a, cout);
}


// * | Paste "int main() {}" in your solution here and rename "gen_output()" and other functions in your code (if needed) above
// * | Aware DO NOT RETURN 0! Just "return;" or return nothing.

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


void gen_output(ifstream &cin, ofstream &cout, ofstream &log) {
    int n;
    cin >> n;
    vector < long long > a(n);
    for (long long &item: a) cin >> item;

    vector < long long > left = calculate_left(a), right = calculate_right(a);

    long long ans = -1;
    int l, r, h;
    for (int i = 0; i < n; ++i) {
        long long current = (right[i] - left[i] - 1) * a[i];
        if (current > ans) {
            l = left[i];
            r = right[i];
            h = a[i];
            ans = current;
        }
    }
    cout << ans << "\n";
    log << "l = " << l + 1 << "\n";
    log << "r = " << r - 1 << "\n";
    log << "h = " << h << "\n";
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
    if (ZIP_LOGS) system(("zip testcases_log.zip " + log_files).c_str());


    //  * | Remove files
    if (REMOVE_TESTCASES_AFTER_ZIP) system(("rm " + files).c_str());
    if (REMOVE_LOGS) system(("rm " + log_files).c_str());


    cerr << "\n" << NUMBER_OF_TESTCASES << " testcases is generated!\n\n";
    cerr << "Process completed!\n\n";
    cerr << "Problem ID: " << id_generate(DATE) << "\n\n";

    return 0;
}
