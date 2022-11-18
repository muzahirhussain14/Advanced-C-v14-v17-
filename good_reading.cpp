#include<iostream>
#include<limits>

using namespace std;

int main() {

    int x{0};
    cout << "Please enter a number: "; cin >> x;

    bool flag{false};

    while (flag == false) {
        if (cin.good()) {
            cout << "\nYou entered the number: " << x;
            flag = true;
        }
        else if (cin.fail()) {
            cout << "\nPlease try again and enter a number: ";
            cin.clear();
            //cin.ignore(20, '\n');                                 // ignore first 20 characters from input buffor or ignore characters until you find newline, whichever comes first
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // ignore (maximum number of characters that can be stored in the input buffer) or ignore until you find newline, whichever comes first 
            cin >> x;
        }
    }

    cout << endl;
    return 0;
}