#include<iostream>
using namespace std;

int main() {

    char ch = 'A';
    const char * str = "Hello World";

    // static cast  ( convert one type into to another )
    int a = static_cast<int>(ch);


    // const_cast   ( convert consts type into non-constants )
    char * str_2 = const_cast<char*>(str);

    cout << "a: " << a << '\n';
    cout << "str_2: " << str_2 << '\n';

    // reinterpret_cast<>()		( used to convert data in the buffer to untyped binary data )
	// dynamic_cast<>()		( converts pointer of the base class objects to the derived class object -- can also be used for the references )
    
    cout << endl;
    return 0;
}