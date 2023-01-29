#include <iostream>

using namespace std;

int strlen(const char *str)
{
    int length = 0;
    for (int i = 0; *(str + i) != '\0'; ++i)
        ++length;

    return length;
}

class String
{

private:
    char *my_str;
    int size;

public:
    String() = default;

    String(const char *other_str)
    {
        cout << "Created\n";

        size = strlen(other_str);
        my_str = new char[size];

        memcpy(my_str, other_str, size);
    }

    String(const String& other_str) 
    {
        cout << "Copied\n";

        size = other_str.size;
        my_str = new char[size];

        memcpy(my_str, other_str.my_str, size);
    }

    String(String&& other_str) noexcept
    {
        cout << "Moved\n";

        size = other_str.size;
        my_str = other_str.my_str;
    
        other_str.size = 0;
        other_str.my_str = nullptr;
    }

    ~String() 
    {
        cout << "Deleted\n";
        delete my_str;
    }
    
    void print() 
    {
        cout << "String: " << my_str << "\n";
    }
};

void printString(String other_str) {

    String my_str = other_str;
    my_str.print();

}


void printStringMove(String other_str) {

    String my_str = std::move(other_str);
    my_str.print();

}

int main()
{
    // If we do not have a move constructor, this 'str' will be copied to the function (to the other_str),
    // and then from other_str it will be copied to my_str in that function, which will then print it.

    // Since we do not use "str" after passing it to the function and similiary other_str in the function also donot do anything
    // with the string except passing it to my_str, therefore there is no point of coping. We should move values both time.
    String str("Muzahir");
    //printString(str);


    // We have move constructor so thats exactly what happens.
    printStringMove(std::move(str));            // this lhs value will me moved to the function's other_str which will then move to my_str.
    


    cout << endl;
    return 0;
}