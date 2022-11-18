#include<iostream>
using namespace std;

int main() {

    string s = "Hello World"s;

    // iterators

    cout << "\nNormal Iterator: ";
    for(auto i = s.begin(); i != s.end(); ++i)
        cout << *i << " ";


    cout << "\nReverse Iterator: ";
    for(auto i = s.rbegin(); i != s.rend(); ++i)
        cout << *i << " ";


    cout << "\nconst Iterator: ";
    for(auto i = s.cbegin(); i != s.cend(); ++i)
        cout << *i << " ";


    cout << "\nconst reverse Iterator: ";
    for(auto i = s.crbegin(); i != s.crend(); ++i)
        cout << *i << " ";


    cout << "\nConcise loop: ";
    for (char ch : s)
        cout << ch << " ";
        
    cout << endl;
    return 0;
}