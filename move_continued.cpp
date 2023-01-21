#include<iostream>

using namespace std;


void test(const string& s) {
    cout << "Lvalue reference version\n";
}

void test(string&& s) {
    cout << "Rvalue reference version\n";
}


int main() {

    string l{string("perm")};
    string& lr {l};                             

    cout << "Temporary Object: ";
    test(string{"Temp"});

    cout << "Lvalue variable: ";
    test(l);

    cout << "Lvalue Reference: ";
    test(lr);

    cout << "std::move(): ";
    test(std::move(l));

    cout << endl;
    return 0;
}