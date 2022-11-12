/*
In C++ computer programming, copy elision refers to a compiler optimization technique that eliminates unnecessary copying of objects. 
This usually occurs when copying temporary variables during function calls.
This applies even if copy constructors has side effects i.e. copy constructors are actually performing operations such as changing values etc.
*/


#include<iostream>
using namespace std;

int n = 0;

struct C {
  C() {
      cout << "Default Called\n";
  }
  C(int) {                      // explict is used to avoid the conversion from int to this class.
      cout << "Parameterized Called\n";
  }
  C(const C&) { 
        cout << "Copy Called\n";
        ++n; 
  }  // the copy constructor has a visible side effect
};                      // it modifies an object with static storage duration


C Test(){
    C obj;
    return obj;             // should call a copy constructor here, but won't call because of CopyElision
}

int main() {

    // Example of Copy Elision 1 
    cout << "Exmaple 1\n";
    C c1(42);                           // direct-initialization, calls C::C(int)
    C c2(C(42));                        // copy-initialization, calls C::C(const C&), won't call copy constructor
    std::cout << n << std::endl;        // prints 0 if the copy was elided, 1 otherwise


    // Example of Copy Elision 2
    cout << "Exmaple 2\n";
    C c3 = Test();                      // should call a copy constructor here, but won't call because of CopyElision

    cout << endl;
    return 0;
}