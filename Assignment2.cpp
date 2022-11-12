/*
The file format has changed from the program in the first part of this workshop. It now looks like this:

    C Kernighan & Ritchie 1970
    C++ Stroustrup 1979
    Java Gosling 1991
    C# Hejlsberg 1999
    Python van Rossum 1991

Modify your program so that it handles the attached languages2.txt correctly
Questions for this assignment

If you need help, click on the Instructor Example to get some hints.
*/

#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>

using namespace std;

struct Language {
    string lang;
    string designer;
    int date;
};

int main() {

    ifstream file("languages2.txt");
    string sentence;
    vector <Language> lang;

    while(getline(file, sentence)){
        istringstream stream{sentence};
        Language l{};
        stream >> l.lang;
        
            // C Kernighan & Ritchie 1970
            // C++ Stroustrup 1979

        string word;
        stream >> word;
        while(!isdigit(word[0])) {
             l.designer += word + " ";
            stream >> word;
        }
        l.date = atoi(word.c_str());
        lang.push_back(l);
    }

    for (Language l : lang) 
        cout << l.lang << " " << l.designer << " " << l.date << "\n";
    
    cout << endl;
    return 0;
}