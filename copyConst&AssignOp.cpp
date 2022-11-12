#include<iostream>
using namespace std;

class String {
    private:
        string a;

    public:
        String() {
            cout << "Default Constructor called\n";
            a = "";
        }

        String(string s) {
            cout << "Parameterized Constructor called\n";
            a = s;
        }

        // Copy Constructor
        String(String& s) {
            cout << "Copy Constructor called\n";
            a = s.a;
        }

        void operator= (String& other) {
            cout << "Assignment Operator called\n";
            this->a = other.a;
        }

        string get_value() {
            return a;
        }
};

int main() {

    String a{"Hello"s};                 // parameterized Constructor
    String b(a);                        // Copy Constructor called

    String c;                           // Default Constructor
    c = a;                              // Assignment operator


    cout << "\n" << a.get_value() << "  " << b.get_value() << "  " << c.get_value() << "\n";

    cout << endl;
    return 0;
}