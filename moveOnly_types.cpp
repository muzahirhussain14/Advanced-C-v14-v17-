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
                
        String(String& otherstr) = delete;                      // delete copy constructor
        String& operator = (String & otherstring) = delete;     // delete assignment operator

        String() = default;
        String(char* otherstr) {
            std::cout << "Created\n";

            size = strlen(otherstr);
            str = new char[size];

            memcpy(str, otherstr, size);
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
};


int main() {

    String my_str("Hello");
    String my_str_2 (my_str);                   // copy constructor can't be called, its deleted.

    String my_str3;
    my_str3 = my_str;                            // normal assignment operator can't be called, its deleted.

    std::cout << std::endl;
    return 0;
}