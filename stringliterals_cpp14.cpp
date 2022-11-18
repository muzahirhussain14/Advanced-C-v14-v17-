#include<iostream>
#include<string>

using namespace std;
using namespace std::literals;

string get_string() {
    return "Hello World"s;              // using 's' we tell compiler that it is a string object
}

int main() {

    string hw = get_string();
    cout << hw << '\n';

    return 0;
}