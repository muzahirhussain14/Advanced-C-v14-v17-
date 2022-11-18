#include<iostream>
#include<iomanip>

using namespace std;

int main() {

    cout << setw(15) << "Penguins " << 5 << "\n";
    cout << setw(15) << "Polar Bears " << 2 << "\n";
    
    cout << "\nWith left alignment\n";
    cout << left                                        // set left alignment
        << setw(15) << "Penguins " << 5 << "\n"
        << setw(15) << "Polar Bears " << 2 << "\n";
    cout << right;                                      // set back to right alignment



    cout << "\nWith fill character\n";
    cout << setfill('#');                               // replace the default fill character (which is a whitespace) with '#'

    cout << setw(15) << "Penguins " << 5 << "\n";
    cout << setw(15) << "Polar Bears " << 2 << "\n";
    

    cout << endl;
    return 0;
}