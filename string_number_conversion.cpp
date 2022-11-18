#include<iostream>
using namespace std;

int main() {

    string hello{"Hello Pi, "};
    string pi = to_string(3.14159);                     // converting number to string

    hello += pi;
    cout << hello << '\n';



    // stoi() is used to convert string to integer
    cout << stoi("42"s) << '\n';

    // failed stoi()
    string str {" 3141 231"};
    size_t n_processed;
    size_t i = stoi(str, &n_processed);

    if (n_processed < str.length()) {
        cout << "Non numeric character at index: " << n_processed << '\n';
    }
    else {
        cout << "After conversion: " << i << '\n';
    }


    // String to floating point
    // stod() is the method used for this

    
    cout << endl;
    return 0;
}