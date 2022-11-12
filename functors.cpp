/*
Functor:
A functor is pretty much just a class which defines the operator(). That lets you create objects which "look like" a 
function.
*/


#include<iostream>
using namespace std;

class add_x {
    private:
        int x;

    public:
        add_x(int val) : x(val) {}                      // Constructor
        int operator()(int y) const { return x + y; }
};


int main() {

    add_x add_45(45);                       // create an instance of the functor class
    int updated_value = add_45(5);          // and "call" it
    cout << updated_value << "\n";

    /*
        One of the nice things about functors is that,  they can contain state. The above example creates a 
        function which adds 42 to whatever you give it. But that value 42 is not hardcoded, it was specified 
        as a constructor argument when we created our functor instance. I could create another adder, which 
        added 27, just by calling the constructor with a different value. This makes them nicely customizable.
    */

   /*
        As the last lines show, you often pass functors as arguments to other functions such as std::transform or 
        the other standard library algorithms. You could do the same with a regular function pointer except, as I 
        said above, functors can be "customized" because they contain state, making them more flexible
   */


    cout << endl;
    return 0;
}