/*
Lambda functions can be thought of as anonymous local functions, similar to closures in other languages.
Once a compiler encounters a lambda expression, it will write a code that defines that functor.
The name of the function will be unique, chosen by the compiler. It will then add body and return type.
Then compiler will write code to create a functor object.
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

    vector<int> vec{2,4,9,8};

    // pass a lambda function
    // lambda functions alway starts with '[]'. So it goes like, [](parameters){ function body; }
    auto odd_it = find_if(cbegin(vec), cend(vec), [](int x) { return (x % 2 == 1); });

    if (odd_it != end(vec)) {
        cout << "First odd element is: " << *odd_it << "\n";
    }

    cout << endl;
    return 0;
}