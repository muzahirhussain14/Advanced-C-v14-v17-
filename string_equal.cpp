/*
    isdigit(c);
    islower(c);
    isupper(c);
    isspace(c);
    ispunct(c);
*/


#include<iostream>
using namespace std;


bool isStringEqual(string a, string b) {

    if (a.size() != b.size())
        return false;

    auto start_a = cbegin(a);
    auto start_b = cbegin(b);
    
    while(start_a != cend(a) && start_b != cend(b)) {

        if (toupper(*start_a) != toupper(*start_b))
            return false;

        ++start_a;
        ++start_b;
    }

    return true;
}

int main() {

    cout << "Is Equal: " << (isStringEqual("abc"s, "abc"s) ? "Yes\n" : "No\n");                              // equal
    cout << "Is Equal: " << (isStringEqual("abc"s, "AbC"s) ? "Yes\n" : "No\n");                              // equal
    cout << "Is Equal: " << (isStringEqual("abd"s, "AbC"s) ? "Yes\n" : "No\n");                              // not equal
    

    cout << endl;
    return 0;
}