#include<algorithm>         // for sort, find
#include<iostream>
#include<vector>
#include<string>

using namespace std;

// predicate function
bool is_grt(string x, string y) {
    return x.size() < y.size();
}

// predicate functor
class is_grt_then {
    private:
        const int limit;

    public:
        is_grt_then(int x) : limit(x) {}
        
        // having a constant function and passing by reference is Not a requirement
        // However having only one argument is a requirement
        // The advantage of using a functor here instead of a normal function is that now we can have a
        // 'limit' variable that allows us to find specific length string.
        bool operator () (const string& x) const {
            return x.size() > limit;
        }  
};


int main() {

    vector<string> names = { "Philip", "Muzahir", "Ali", "David", "Ba"};
    for (string name:names)
        cout << name << ",";
    cout << "\n";

    sort(begin(names), end(names));

    for (string name:names)
        cout << name << ",";
    cout << "\n";

    // **************** Predicate Function ************************
    // assiging our own sort function, a.k.a Predicate function
    sort(begin(names), end(names), is_grt);

    for (string name:names)
        cout << name << ",";
    cout << "\n";


    // We can also pass functors as predicate function
    // begin() returns an iterator to beginning while cbegin() returns a const_iterator to beginning
    auto x = find_if(cbegin(names), cend(names), is_grt_then(6));
    if (x != cend(names))
        cout << *x << "\n";


    cout << endl;
    return 0;
}