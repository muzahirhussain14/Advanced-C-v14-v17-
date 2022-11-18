#include<iostream>
#include<sstream>           // for stringstreams
#include<fstream>           // for input file
#include<vector>

using namespace std;

/*
There are two types of stringstreams,
-   input stringstream (istringstream)
-   output stringstream (ostringstream)

- An output stream has an empty std::string object
- We can store data in this string, using the same operations as for other output streams.
- The Str() member function will return a copy of the stream's string.

- An input stream object uses a copy of an existing string
- We can then read the data from the string, using the same operations as for other input streams.
- This is useful for processing input, e.g. breaking up a line of text into words or numbers.
*/




// Example of output Stream
template <typename T>
string To_String(T input) {
    ostringstream s;
    s << input;                             // converts input of any type to string and writes it to output stream
    return s.str();
}


// Example of input Stream
void process_file_using_istringstream(string name) {

    ifstream infile(name);
    if (!infile) {
        cout << "Could not open the file";
        return;
    }

    string line;
    vector<int> numbers;

    while(getline(infile, line)) {
        istringstream s(line);
        int num = 0;

        while (s >> num) {
            numbers.push_back(num);
        }
    }

    double sum {0.0};
    for (int n : numbers) {
        cout << n << '\n';
        sum += n;
    }

    cout << "Average: " << sum/numbers.size() << '/n';
}

int main() {

    int a = 150;
    float b = 1.2312;
    char c = 'A';

    cout << To_String(a) << '\n';
    cout << To_String(b) << '\n';
    cout << To_String(c) << '\n';


    cout << "\n\n";
    process_file_using_istringstream("data.txt");


    cout << endl;
    return 0;
}