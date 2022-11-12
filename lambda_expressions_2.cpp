/* Passing local variables to the lambda expression */

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main() {

    int length{9};            // local variable declared using a new c++17 syntax
    vector<string> names{"alii", "harry", "hassain", "muzahir", "spider-man"};

    auto result = find_if(cbegin(names), cend(names), [length](const string& n) {return n.size() > length;});
    if (result != cend(names))
        cout << "Name: " << *result << "\n";

    

    // mutable lambda expressions.
    // if we want to be able to modify the local variables, we need to make our lambda expressions mutable.
    int index = -1;
    result = find_if(  cbegin(names),
                            cend(names), 
                            [length, index] (const string& n) mutable {++index; return n.size() > length;}
                            );

     if (result != cend(names))
        // index will still have -1. The reason for this is that when we create a lambda expression,
        // compilers writes a functor that has the same body as the lambda expression, and all the local variables
        // that are passed to the lambda expression, compiler creates private members variables for all those variables.
        // So when we modify the 'index', it is actually modifying the functors 'index' variable and not the local one.
        cout << "Name: " << *result << " found at index: " << index << "\n";

    cout << endl;
    return 0;
}