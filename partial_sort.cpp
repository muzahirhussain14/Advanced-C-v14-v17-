#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    //vector<int> x = {2,1,5,23,1,5,7,4,2,1};
    string x = "qwertyuiopasdfghhjk";
    auto start = begin(x);

    partial_sort(start, start + 5, end(x));                 // first 5 elements will be sorted, rest won't be.

    cout << "First 5 characters after sort: " << x.substr(0, 5) << "\n";
    cout << "Printing after sorting first five: " << x << "\n";
    cout << endl;
    return 0;
}