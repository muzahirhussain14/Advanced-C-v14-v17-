#include<iostream>
using namespace std;


using pfunc = void(*)(int, int);            // pointer to any function that takes two parameters of type int

// typedef void (*) (const string&, const string&) pfunc;       // older c++


void func(int x, int y) {
    cout << x << " + " << y << " = " << x+y << "\n";
}

void some_func(int x, int y, pfunc pfunc_ptr) {                     // passing function pointer to the function

    (*pfunc_ptr)(x,y);
}

pfunc other_func() {                                                // return function pointer from a function
    return func;
}

int main() {

    auto func_ptr = other_func();                                   // get pointer to the function
    (*func)(12,2);

    some_func(1, 2, func_ptr);

    cout << endl;
    return 0;
}