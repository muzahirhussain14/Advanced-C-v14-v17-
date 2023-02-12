/*
std::unique_ptr is a smart pointer in C++ that manages the lifetime of dynamically allocated objects and ensures that the 
object is deleted when the unique_ptr goes out of scope.

std::make_unique is a function template introduced in C++14, which creates a unique_ptr object and directly initializes the 
dynamically allocated object, without having to use new and without having to specify the type of the object. This helps avoid 
memory leaks and makes the code cleaner and easier to read.

For example:

    std::unique_ptr<int> p1 = std::make_unique<int>(42);

is equivalent to:

    std::unique_ptr<int> p2(new int(42));

In general, it is recommended to use std::make_unique instead of directly using new and std::unique_ptr, as std::make_unique provides 
a safer and more concise way to create unique_ptr objects.
*/

#include <iostream>
#include <memory>

using namespace std;

class Point {
    public:
        int x;
        int y;

    
        Point(int x, int y){this->x = x; this->y = y;}
};

unique_ptr<Point> get_Pointer_to_Point() {
    Point point(12,21);

    auto ptr = make_unique<Point>(point);
    //std::unique_ptr<Point> ptr(new Point(point));

    return ptr;
}

int main() {

    std::unique_ptr<int> p1(new int (42));

    // allocate array of 6 ints
    std::unique_ptr<int[]> arr(new int[6]);

    auto p2 = std::make_unique<int>(55);                    // exactly as unique_ptr - just we dont need 'new' keyword with this.
    auto p3 = std::move(p1);                                // move one pointer to another. p1 will be unusedable after this
    
    p1 = nullptr;
    cout << *p3 << "\n";


    // getting unique_ptr to a class from a function.
    std::unique_ptr<Point> point = get_Pointer_to_Point();
    cout << "X: " << point->x << ", Y: " << point->y << "\n";

    cout << endl;
    return 0;
}