#include<iostream>
#include<string>
using namespace std;

int main() {

    // To insert the elements at the end, we have append() method as well as '+'.
    // However if we want to insert in the middle we have insert()

    string str {"Ho"};
    cout << "Before inserting: " << str << '\n';
    str.insert(1, "ell"s);                           // second parameter can be c style string or the string object
    cout << "After inserting: " << str << '\n';


    // we can also use iterators
    string str2 {"word"};
    auto last = end(str2) - 1;       // index to the second last character - end() returns the iterators to the last element. Similarly we have begin() that returns the iterator to the first element
    str2.insert(last, 'l');

    cout << "Before inserting: " << str2 << '\n';
    cout << "After inserting: " << str2 << '\n';
    
    // Removing the character
    string hello{"Hello"};
    cout << "\nBefore Erasing: " << hello << '\n';

    hello.erase(1,3);                                   // erase 2 character starting from index 1
    cout << "After Erasing: " << hello << '\n';
    
    // just like with insert() we can use iterator with the erase() method as well
    

    // Assignment
    string str3{"Hello"};
    cout << "Str3: " << str3 << '\n';

    str3.assign("Goodbye");                     // Same as str3 = "Goodbye";
    cout << "Str3 (After assigning): " << str3 << '\n';


    cout << endl;
    return 0;
}