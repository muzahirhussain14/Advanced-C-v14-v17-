#include<iostream>
using namespace std;

class LiftOff {

    private:
        int timer{10};

    public:
        void countdown() {
            // this passes the members data of the class to the lambda expression by reference
            [this] () mutable {
                if (timer > 0)
                    cout << timer << "\n";
                
                else if (timer == 0)
                    cout << "Liftoff !!!";
                --timer;
            }();

            // the brackets () at the end cause the lambda expression to execute right away.
        }
};

int main() {

    LiftOff lift;

    for(int i = 0; i <= 10; ++i)
        lift.countdown();

    cout << endl;
    return 0;
}