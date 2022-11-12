#include<iostream>
using namespace std;

class Alpha {

    private:
        int& x;

    public:
        Alpha(int& a) : x(a) {}

        void increment() {
            ++x;
        }
};

int main() {

    int x = 10;
    Alpha alpha(x);

    alpha.increment();
    alpha.increment();
    alpha.increment();
    alpha.increment();
    
    cout << "Value of x: " << x;
    
    cout << endl;
    return 0;
}