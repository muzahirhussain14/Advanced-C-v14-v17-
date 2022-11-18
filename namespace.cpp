#include<iostream>

int x{23};                  // c++-14 way of initialization
namespace abc {

    int x = 47;

    void func() {
        std::cout << "x: " << x << "\n";                // namespace x
        std::cout << "x: " << ::x << "\n";              // global x
    }

}

int main() {

    abc::func();

    std::cout << std::endl;
    return 0;
}