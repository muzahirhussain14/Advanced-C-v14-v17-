#include<iostream>

int strlen(const char *str)
{
    int length = 0;
    for (int i = 0; *(str + i) != '\0'; ++i)
        ++length;

    return length;
}

class String {

    private:
        char* str;
        int size;


    public:
        String() = default;

        String(char* other_str) {
            std::cout << "Created\n";

            size = strlen(other_str);
            str = new char[size];

            memcpy(str, other_str, size);
        }

        String(String && other_str) noexcept {
            std::cout << "Moved\n";

            str = other_str.str;
            size = other_str.size;

            other_str.str = nullptr;
            other_str.size = 0;
        } 

        String& operator= (String&& other_str) noexcept {
            std::cout << "Move assignment\n";

            if (this != &other_str) 
            {
                str = other_str.str;
                size = other_str.size;

                other_str.size = 0;
                other_str.str = nullptr;
            }

            return *this;
        }

        ~String() {
            std::cout << "Destroyed\n";
            
            delete str;
            size = 0;
        }

        void print() {
            std::cout << str << "\n";
        }
};

int main() {

    String my_str( "Muzahir");
    String my_str_2;

    my_str_2 = std::move(my_str);


    std::cout << std::endl;
    return 0;
}