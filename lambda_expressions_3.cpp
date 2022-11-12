/*
Passing local variables by values and refernces to the functors.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    vector<string> vec {"Ali", "Dave", "Hussain", "Philiph"};
    int index = -1;    
    int length = 5;

    // pass length by value and index by reference
    auto find = find_if(cbegin(vec), cend(vec),  [=, &index] (const string& n) mutable { ++index;   return (n.size() >= length); } );

    if (find != end(vec))
        cout << "Name: " << *find << " index: " << index;

    // Also note these,
    // [=, &x]			// capture x by reference, all other by value
	// [&, =a, =b] 		// a and b by value all other by reference

    cout << endl;
    return 0;
}