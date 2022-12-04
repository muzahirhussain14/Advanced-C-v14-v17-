#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    vector<int> x {2,3,4,5,6,2};
    vector<int> y {6,5,4,3,1};
    vector<int> result;

    sort(begin(x), end(x));
    sort(begin(y), end(y));

    merge(begin(x), end(x), begin(y), end(y), back_inserter(result));

    for(int i:result) {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}