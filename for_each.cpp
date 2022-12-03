#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {

    vector<int> int_vec{2,1,2,43,5,1,2};

    // for_each to print a vector
    cout << "For each:  ";
    for_each(begin(int_vec), end(int_vec), [](const int c){ cout << c << " "; });

    cout << "\nRange For-Loop: ";
    for (auto c: int_vec) {
        cout << c << " ";
    }

    cout << endl;
    return 0;
}