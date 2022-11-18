#include<iostream>
#include<string>

using namespace std;

int main() {

    string str{"Hello World"};
    size_t pos = str.find('o');

    // npos is the value returned by the different member function when they fail
    if (pos != string::npos) {
        str[pos] = 'p';
        cout << "Character found: " << str << '\n';
    } else {
        cout << "Could not find the character: " << str << "\n";
    }



    // rfind - reverse find, starts finding from the end of the string
    string str2{"Musahir Hussain"};
    size_t pos2 = str2.rfind('s', 7);               // start find from the 7th index from left

    if (pos2 != string::npos) {
        str2[pos2] = 'S';
        cout << "Character found: " << str2 << '\n';
    } else {
        cout << "Could not find the character: " << str2 << "\n";
    }


    /*
        find_first_of() and find_last_of() search for the first (last) occurrence of any character from the argument string
        string str {"Hello World"}
        string vowels {"aeiou"}

        str.find_first_of(vowels);              // Returns 1
        str.find_last_of(vowels);               // Returns 7 
    */


    /*
        find_first_not_of() and find_last_not_of() search for the first (last) occurance of any character not in the argument
        str.find_first_not_of(vowels);          // return 0 ('H' is not in the vowels)
        str.find_last_not_of(vowels);           // return 10 ('d' is not in the vowels)
    */
    cout << endl;
    return 0;
}