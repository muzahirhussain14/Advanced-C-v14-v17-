#include<iostream>
#include<sstream>
#include<string>

using namespace std;

/*
seekg sets the current position in the input stream
tellg returns the current position in an input stream

seekp sets the current position in the output stream
tellp returns the current position in an outstream stream


-> tell operations return a pos_type object
-> This represents a position in a stream and it can be converted into an int.
-> The operation fails if the stream is in an invalid state, and the return value will be -1

    auto pos = file.tellg();
    if (pos != -1) {
        ...
    }

-> We can use these functions with any stream object i.e. whether stringstreams or file streams
*/


int main() {

    ostringstream output;
    string data{"It is time to say "};
    output << data;

    auto marker = output.tellp();
    cout << data.size() << " characters written to stream\n";
    cout << "String marker is " << marker << " bytes into the stream\n";

    output << "Hello";
    cout << "String marker is now " << output.tellp() << " bytes into the stream\n";

    cout << output.str() << endl;

    if (marker != -1)             // set marker to the old position (before writting Hello) in the stream
        output.seekp(marker);
    output << "Goodnight";
    cout << output.str() << endl;


    cout << endl;
    return 0;
}