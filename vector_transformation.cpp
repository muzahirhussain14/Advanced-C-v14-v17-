#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    vector<int> x{2,1,2,3,4,5,2};
    vector<int> result;
    transform(begin(x), end(x), back_inserter(result), [](int x){ return x * 5;});    

    for(int x : result) {
        cout << x << " ";
    }
    cout << "\n";

    // Inplace transformation
    transform(begin(result), end(result), begin(result), [](int x) { return x / 5;});
    for(int x : result) {
        cout << x << " ";
    }


    cout << endl;
    return 0;
}