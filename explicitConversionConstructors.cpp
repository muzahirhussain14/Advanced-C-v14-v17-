#include<iostream>
using namespace std;

int n = 0;

class C {

public:
  C() {
      cout << "Default Called\n";
  }
  explicit C(int i) {                      // explict is used to avoid the conversion from int to this class.
      cout << "Parameterized Called\n";
      n += i;
  }
  C(const C&) { 
        cout << "Copy Called\n";
        ++n; 
  }

  operator int() {                      // Acts as a conversion operator. Object will be converted into integer because of this function.
      return n;
  }
};                      // it modifies an object with static storage duration


void test (C temp) {
    cout << "Function called";
}

int main(){

    // Implicit conversion

    // if we didn't use explicit in the constructor this would've worked. '5' would've been converted to the struct of 
    // type 'C' and then that would've have been copied into the variable c1, and that would've invoked a copyconstructor.
    // This can cause unexpected results when passing a integer instead of a C object as a function argument (Example below line 38), 
    // because we would get a silent conversion which we might be unaware of.
    
    //C c1 = 5; 

    // This function call would also have worked if we didn't used explicit keyword. Again 55 would've been converted
    // the an object of class C and passed in to the function.
    // test(55);                          

    // But because we used the word 'explicit', the implicit(automatic) conversion was disabled.
    // So there for this is how an object will be created now.
    C c1(5);


    // Conversion Operator
    cout << "Conversion Operator: " << c1 << "\n";             // we were able to print c1 because of the int conversion operator in the class


    cout << endl;
    return 0;
}