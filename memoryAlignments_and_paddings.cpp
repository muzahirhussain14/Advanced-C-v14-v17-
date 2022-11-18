#include<iostream>
using namespace std; 

#pragma pack(push, 1)                     // 1 byte memory alignment
struct Point {
    char c;
    int32_t x;
    int32_t y;
};
#pragma pack(pop)                         // revert back to the default alignment (which is 4 bytes)


int main() {

    Point p{'a', 1,2};
    cout << "Size of P is: " << sizeof(p) << '\n';

    cout << endl;
    return 0;
}


/*
    When we set the memory alignment to 1 byte and do the sizeof() we get 9 bytes. Because there is no extra bytes to do the padding.
    However if we do the sizeof() without the memory alignment we get the 14 bytes, because default alignment is 4 bytes.
*/