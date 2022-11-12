/*
You are given the attached languages.txt file and the following type definition:

    struct language {
        string lang;
        string designer;
        int date;
    };

The format of the languages.txt file is:

    C++ Stroustrup 1979
    Java Gosling 1991

Write a program which will:

    Read in the data from the attached languages.txt file

    Use each line of input to populate a language object

    Add this object to a vector

    Print out all the data in the vector, separated by commas

Your output should look like this:

    C++, Stroustrup, 1979
    Java, Gosling, 1991
*/

#include<iostream>
#include<sstream>
#include<vector>
#include<fstream>

using namespace std;

struct language {
    string lang;
    string designer;
    int date;
};

int main() {
    ifstream file("languages.txt");
    string sentence;
    vector <language> languages;
    int i = 0;

    while(getline(file, sentence)) {
        stringstream s{sentence};
        language l {};
        s >> l.lang;
        s >> l.designer;
        s >> l.date;

        languages.push_back(l);
        ++i;
    }
    
    for(language l : languages)
        cout << l.lang << ", " << l.designer << ", " << l.date << "\n";

    cout << endl;
    return 0;
}