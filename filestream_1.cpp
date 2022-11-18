// reading from file

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main() {
    
    // Reading from the file
    ifstream ifile("test.txt");                     // ifstream is used for reading from the file
    if (ifile) {
        string text{""};
        //while(ifile >> text) {                      // reads a single world at a time
        while(getline(ifile, text)) {               // reads complete line
            cout << text << ",\n";
        }
    }


    // Writing to the file
    ofstream ofile("text_out.txt");                 // ostream is used for writing into the file
    vector<string> words = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "fox"};
    for (string word: words) {
        ofile << word << ",";
    }
    cout << endl;
    return 0;
}