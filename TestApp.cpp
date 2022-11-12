#include<iostream>
using namespace std;

int main() {

    int y = 1;
    auto lambda = [y = y+1](int x) { return x + y; };
    
    int x = lambda(5);
    cout << x << endl;
    cout << y << endl;

    // int x{42}, y{99};
    // int z{0};
    
    // auto lam = [=,&z]() mutable { ++x; ++y; z = x + y; };
    // lam();
    
    // lam();

    // cout << x << " ," << y << " ," <<  z << "\n";
    // int * data = new int[15];
    
    
    // delete [] data;
    // cout << "Single Delete Data Done\n";

    // delete [] data;
    // cout << "Double Delete Data Done\n";

    cout << endl;
    return 0;
}