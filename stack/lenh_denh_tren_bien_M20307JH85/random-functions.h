#include <bits/stdc++.h>

using namespace std;

long long binpow(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long res = binpow(a, b / 2);
    if (b % 2) return res * res * a;
    return res * res;
}

//  * | The function takes 2 values min_value and max_value
//  * | then return a random 32-bit integer between min_value and max_value.
long rand_int(long min_value, long max_value) {
    return rand() % (max_value - min_value + 1) + min_value;
}


//  * | The function takes 2 values min_value and max_value
//  * | then return a random 64-bit integer between min_value and max_value.
long long rand_int64(long long min_value, long long max_value) {
    return rand() % (max_value - min_value + 1) + min_value;
}


//  * | The function takes 3 values min_value, max_value and number_of_digit
//  * | then return a random 64-bit double with number_of_digit digits after
//  * | the floating-point between min_value and max_value. Default number_of_digit = 3
double rand_double(double min_value, double max_value, int number_of_digit = 3) {
    vector <double> values;
    for (long i = min_value; i <= max_value; ++i) {
        long long m = binpow(10, number_of_digit);
        for (long j = 0; j <= m - 1; ++j) {
            double decimals = (j * 1.0) / m;
            double result = 1.0 * i + decimals;
            values.push_back(1.0 * i + decimals);
        }
    }
    return values[rand_int(0, values.size() - 1)];
}


//  * | The function takes 3 values min_value, max_value and number_of_digit
//  * | then return a random 128-bit double with number_of_digit digits after
//  * | the floating-point between min_value and max_value. Default number_of_digit = 6
long double rand_double128(long double min_value, long double max_value, int number_of_digit = 6) {
    vector <long double> values;
    for (long long i = min_value; i <= max_value; ++i) {
        long long m = binpow(10, number_of_digit);
        for (long long j = 0; j <= m - 1; ++j) {
            long double decimals = (j * 1.0) / m;
            long double result = 1.0 * i + decimals;
            values.push_back(1.0 * i + decimals);
        }
    }
    return values[rand_int(0, values.size() - 1)];
}


//  * | The functions takes 2 value: len and template_string (default is alphabet)
//  * | then return a random string with len characters and all the characters are from the template_string.
string rand_str(int len, string template_string = "qwertyuiopasdfghjklzxcvbnm") {
    string result = "";
    for (int i = 0; i < len; ++i) {
        result += template_string[rand_int(0, template_string.length() - 1)];
    }
    return result;
}


//  * | The function takes 4 values: len, min_value, max_value and is_distinct then return a vector with size of len, all the values inside the vector are between min_value and max_value.
vector <int> rand_list(int len, int min_value, int max_value, bool is_distinct = false) {
    vector <int> result(len, 0), is_free(len, 0);

    if (is_distinct) {
        int a = min_value, b = max_value;
        while (b - a + 1 != len) {
            a = rand_int(min_value, max_value);
            b = rand_int(min_value, max_value);
        }

        for (int value = a; value <= b; ++value) {
            int index = -1;
            do {
                index = rand_int(0, len - 1);
            } while (is_free[index] != 0);
            result[index] = value;
            is_free[index] = 1;
        }
    } else {
        for (int &item: result) {
            item = rand_int(min_value, max_value);
        }
    }

    return result;
}


//  * | The function takes 4 values: len, min_value, max_value and is_distinct
//  * | then return a vector with size of len, all the values inside the vector are between min_value and max_value (64-bit integers).
//  * | If is_distinct equal to true then all the element inside the vector are distinct and vice versa.
vector <long long> rand_list_int64(int len, long long min_value, long long max_value, bool is_distinct = false) {
    vector <long long> result(len, 0), is_free(len, 0);

    if (is_distinct) {
        long long a = min_value, b = max_value;
        while (b - a + 1 != len) {
            a = rand_int(min_value, max_value);
            b = rand_int(min_value, max_value);
        }

        for (long long value = a; value <= b; ++value) {
            int index = -1;
            do {
                index = rand_int(0, len - 1);
            } while (is_free[index] != 0);
            result[index] = value;
            is_free[index] = 1;
        }
    } else {
        for (long long &item: result) {
            item = rand_int(min_value, max_value);
        }
    }

    return result;
}


//  * | The function takes 4 values: len, min_value, max_value and is_distinct
//  * | then return a vector with size of len, all the values inside the vector are between min_value and max_value (64-bit double).
//  * | If is_distinct equal to true then all the element inside the vector are distinct and vice versa.
vector <double> rand_list_double(int len, double min_value, double max_value, bool is_distinct = false) {
    vector <double> result(len, 0), is_free(len, 0);

    if (is_distinct) {
        double a = min_value, b = max_value;
        while (b - a + 1 != len) {
            a = rand_int(min_value, max_value);
            b = rand_int(min_value, max_value);
        }

        for (double value = a; value <= b; ++value) {
            int index = -1;
            do {
                index = rand_int(0, len - 1);
            } while (is_free[index] != 0);
            result[index] = value;
            is_free[index] = 1;
        }
    } else {
        for (double &item: result) {
            item = rand_int(min_value, max_value);
        }
    }

    return result;
}


//  * | The function takes 4 values: len, min_value, max_value and is_distinct
//  * | then return a vector with size of len, all the values inside the vector are between min_value and max_value (128-bit double).
//  * | If is_distinct equal to true then all the element inside the vector are distinct and vice versa.
vector <long double> rand_list_double128(int len, long double min_value, long double max_value, bool is_distinct = false) {
    vector <long double> result(len, 0), is_free(len, 0);

    if (is_distinct) {
        long double a = min_value, b = max_value;
        while (b - a + 1 != len) {
            a = rand_int(min_value, max_value);
            b = rand_int(min_value, max_value);
        }

        for (long double value = a; value <= b; ++value) {
            int index = -1;
            do {
                index = rand_int(0, len - 1);
            } while (is_free[index] != 0);
            result[index] = value;
            is_free[index] = 1;
        }
    } else {
        for (long double &item: result) {
            item = rand_int(min_value, max_value);
        }
    }

    return result;
}


//  * | the function takes an 64-bit integer then return number of digit of the integer
int count_digit(long long x) {
    int counter = 0;
    while (x > 0) {
        counter++;
        x /= 10;
    }
    return counter;
}


//  * | The function takes 2 values: 2 64-bit integers then return a formated string of the first integer
string format_number(long long x, long long max_val) {
    int max_digit = count_digit(max_val);
    int value_digit = count_digit(x);
    string s = "";
    for (int i = 0; i < max_digit - value_digit; ++i) s += "0";
    s += to_string(x);
    return s;
}

//  * | The function takes current date and return an ID
string id_generate(int date) {
    string custom_template = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string result = rand_str(1, "ITMC") + to_string(rand_int(10, 99)) + to_string(rand_int(10, 99)) + to_string(date) + rand_str(2, custom_template) + to_string(rand_int(10, 99));
    return result;
}


//  * | The tunction takes a vector of 32-bit integer then print the vector to the console
void print_vector(vector <int> a, ofstream &cout) {
    for (int i = 0; i < a.size() - 1; ++i)
        cout << a[i] << " ";
    cout << a[a.size() - 1] << "\n";
    return;
}


//  * | The tunction takes a vector of 64-bit integer then print the vector to the console
void print_vector_int64(vector <long long> a, ofstream &cout) {
    for (int i = 0; i < a.size() - 1; ++i)
        cout << a[i] << " ";
    cout << a[a.size() - 1] << "\n";
    return;
}


//  * | The tunction takes a vector of 64-bit double then print the vector to the console
void print_vector_double(vector <double> a, ofstream &cout) {
    for (int i = 0; i < a.size() - 1; ++i)
        cout << a[i] << " ";
    cout << a[a.size() - 1] << "\n";
    return;
}


//  * | The tunction takes a vector of 128-bit double then print the vector to the console
void print_vector_double128(vector <long double> a, ofstream &cout) {
    for (int i = 0; i < a.size() - 1; ++i)
        cout << a[i] << " ";
    cout << a[a.size() - 1] << "\n";
    return;
}


//  * | The function takes a matrix of n x m 32-bit integer then print the matrix to the console
void print_matrix(vector < vector <int> > a, ofstream &cout) {
    for (vector <int> row: a) {
        print_vector(row, cout);
    }
    return;
}


//  * | The function takes a matrix of n x m 64-bit integer then print the matrix to the console
void print_matrix_int64(vector < vector <long long> > a, ofstream &cout) {
    for (vector <long long> row: a) {
        print_vector_int64(row, cout);
    }
    return;
}


//  * | The function takes a matrix of n x m 64-bit double then print the matrix to the console
void print_matrix_double(vector < vector <double> > a, ofstream &cout) {
    for (vector <double> row: a) {
        print_vector_double(row, cout);
    }
    return;
}


//  * | The function takes a matrix of n x m 128-bit double then print the matrix to the console
void print_matrix_double128(vector < vector <long double> > a, ofstream &cout) {
    for (vector <long double> row: a) {
        print_vector_double128(row, cout);
    }
    return;
}
