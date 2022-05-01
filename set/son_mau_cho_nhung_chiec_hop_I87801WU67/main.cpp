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
void gen_input(const int test_number, ofstream &cout) {
    int tmax, nmax, ran, qmax;
    if (test_number <= 3) {
        tmax = 2;
        nmax = 10;
        ran = 10;
        qmax = 4;
    }
    else if (test_number <= 6) {
        tmax = 10;
        nmax = 1e4;
        ran = 1e9;
        qmax = 1e3;
    }
    else {
        tmax = 10;
        nmax = 1e5;
        ran = 1e9;
        qmax = 1e4;
    }

    int t = rand_int(1, tmax);
    cout << t << "\n";
    for (int rep = 0; rep < t; rep++) {
        int n = rand_int(1, nmax);
        int w = rand_int(1, n);
        cout << n << " " << w << "\n";
        vector < int > a = rand_list(n, 1, ran);
        print_vector(a, cout);
        int q = rand_int(1, qmax);
        cout << q << "\n";
        for (int i = 0; i < q; ++i) {
            cout << rand_int(1, n) << " " << rand_int(1, ran) << "\n";
        }
    }
}


// * | Paste "int main() {}" in your solution here and rename "gen_output()" and other functions in your code (if needed) above
// * | Aware DO NOT RETURN 0! Just "return;" or return nothing.

#define ll long long

int t;
ll ar[100005];
ll n, w;

void solve(ifstream &cin, ofstream &cout) {
	cin >> n >> w;
	vector<ll> c(n + 1);
	c[w] = 1;
	for(int i = w+1; i <= n; ++i) c[i] = c[i - 1] + 1;
	
	set<ll> s;
	for(int i = 0; i < n; ++i) {
		cin >> ar[i];
		if (i == 0) s.insert(0);
		else if (ar[i] != ar[i - 1]) s.insert(i);
	}
	
	int q;
	cin >> q;
	ll ans = 0;
	for (set<ll>::iterator it = s.begin(); it != s.end(); ++it) {
		ll curr = (*it);
		++it;
		ll next;
		if(it == s.end()) next = n;
		else next = (*it);
		--it;
		ans += c[next-curr];
	}

	while (q--) {
		ll po,color;
		cin >> po >> color;
		if (n == 1) {
			cout << c[1] << "\n";
			continue;
		}
		--po;

		if (ar[po] == color) {
			cout << ans << "\n";
			continue;
		}
		
		ll prev = ar[po];
		ar[po] = color;
		if (po == 0 || po == n - 1) {
			if (po == 0) {
				if (ar[po + 1] == ar[po]) {
					auto it = s.upper_bound(po + 1);
					ll l;
					if (it == s.end()) l = n - (po + 1);
					else l = (*it)-(po+1);

					ans -= c[l] + c[1];
					ans += c[l + 1];
					s.erase(po + 1);
					s.insert(po);
				}
				else {
					if (ar[po + 1] == prev) {
						auto it = s.upper_bound(po);
						ll l;
						if (it == s.end()) l = n - (po);
						else l = (*it) - po;

						ans -= c[l];
						ans += c[1] + c[l - 1];
					}

					s.insert(po + 1);
				}
			}
			else {
				if (ar[po - 1] == ar[po]) {
					auto it = s.lower_bound(po);
					--it;
					ll l;
					if (it == s.begin()) l = po;
					else l = po - (*it);

					ans -= c[l] + c[1];
					ans += c[l + 1];
					s.erase(po);
				}
				else {
					if (prev == ar[po - 1]) {
						auto it = s.end();
						--it;
						ll l = n - (*it);

						ans -= c[l];
						ans += c[1] + c[l - 1];
					}

					s.insert(po);
				}	
			}
		}
		else {
			if (ar[po - 1] == ar[po] && ar[po + 1] == ar[po]) {
				auto it = s.lower_bound(po);
				ll l = 0;
				it--;
				ll left = *it;
				it++;
				ans -= c[po - left];
				ans -= c[1];
				l += 1 + (po - left);
				ll right = po + 1;
				++it; 
				++it;
				if (it == s.end()) {
					ans -= c[n - right];
					l += (n - right);
				}
				else {
					ans -= c[(*it) - right];
					l += (*it) - right;
				}
				--it;
				--it;
				ans += c[l];
				s.erase(po);
				s.erase(po + 1);
			}
			else {
				if (ar[po + 1] == ar[po]) {
					auto it = s.lower_bound(po + 1);
					--it;
					if (ar[po - 1] == prev) {
						ans -= c[po + 1 - (*it)];
						ans += c[po - (*it)];	
					}
					else ans -= c[1];
					++it;
					++it;
					if (it == s.end()) {
						ans -= c[n - po - 1];
						ans += c[n - po];
					}
					else {
						ans -= c[(*it) - po - 1];
						ans += c[(*it) - po];
					}
					--it;
					s.erase(po + 1);
					s.insert(po);
				}
				else {
					if (ar[po - 1] == ar[po]) {
						auto it = s.lower_bound(po);
						--it;
						ans -= c[po - (*it)];
						ans += c[po + 1 - (*it)];
						++it;
						++it;
						if (prev == ar[po + 1]) {
							if (it == s.end()) {
								ans -= c[n - po];
								ans += c[n - po - 1];
							}
							else {
								ans -= c[(*it) - po];
								ans += c[(*it) - po - 1];
							}
						}
						else ans -= c[1];
						--it;
						s.erase(po);
						s.insert(po + 1);
					}
					else {
						s.insert(po);
						auto it = s.lower_bound(po);
						--it;
						ll left = *it;
						++it;
						++it;
						ll right;
						if (it == s.end()) right = n;
						else right = *it;
						
						if (prev == ar[po - 1] && prev == ar[po + 1]){
							ans -= c[right - left];
							ans += c[1] + c[po - left] + c[right - po - 1];	
						}
						else {
							if (prev == ar[po - 1]) {
								ans -= c[po + 1 - left];
								ans += c[po - left] + c[1];
							}
							else {
								if (prev == ar[po + 1]) {
									ans -= c[right - po];
									ans += c[right - (po + 1)] + c[1];
								}
							}
						}
						s.insert(po + 1);
					}
				}
			}
		}
		cout << ans << "\n";
	}
}

void gen_output(ifstream &cin, ofstream &cout) {
    cin >> t;
	while (t--) {
		solve(cin, cout);
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