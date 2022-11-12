/*
Write a function that takes a vector of int as argument and uses a range-for loop to print out the elements of the vector.
Write a program that calls this function. Check that your program compiles and runs correctly.
Modify your program so that it sorts the elements in descending order, with the largest element first. For example, if the vector elements are 1, 2, 3, 4, 5, the output will be
5, 4, 3, 2, 1
Use a suitable standard algorithm with a lambda expression as predicate.
Display the elements of the vector after sorting them. Check that your program still compiles and runs correctly.
Questions for this assignment
Implement the program as described. If you need help, click on "Instructor Example" for some hints.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print_vec(const vector<int>& vec) {

    for(int x : vec) 
        cout << x << " ";
    
    cout << endl;
}

int main() {

    vector<int> x {2,1,3,4,2,6,1};

    sort(begin(x), end(x), [](int x, int y) { return (x>=y); } );
    print_vec(x);

    cout << endl;
    return 0;
}