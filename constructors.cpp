#include<iostream>
using namespace std;

class Internet {
    public:
        void connect() {
            cout << "Internet connected\n";
        }
        void login(const string& id, const string& pw) {
            cout << "Logged in with username: " << id;
            cout << " and password: " << pw << "\n";
        }
};

class Refrigerator {

    private:
    int temperature {2};            // setting default values, possible in newer versions of C++
    bool door_open {false};
    bool power_on {true};
    Internet internet;

    public:
        Refrigerator() : Refrigerator("me", "secret") {                     // calling parameterized constructor from default constructor
            //internet.connect();
            //internet.login("me", "secret");
        }
        Refrigerator(int temperature) : Refrigerator("me", "secret") {      // calling another parameterized constructor from this constructor
            //internet.connect();
            //internet.login("me", "secret");
        }
        Refrigerator(const string& id, const string& pw) {
            internet.connect();
            internet.login(id, pw);
        }

        void print() {
            cout << "temperature = " << temperature << "\n";
            cout << boolalpha;                                  // prints actual true/false instead of 1/0 for boolean variables
            cout << "door_open = " << door_open << "\n";
            cout << "power_on = " << power_on << "\n" << endl;
        }
};

int main() {

    Refrigerator fridge;
    fridge.print();

    Refrigerator fridge2{"user1", "password1"};
    fridge2.print();

    cout << endl;
    return 0;
}