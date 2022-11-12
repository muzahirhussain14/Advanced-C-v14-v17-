#include<iostream>
using namespace std;

class Complex {

    private:
        double real{0.0};
        double imaginary{0.0};

    public:
        Complex(){}
        Complex(double r, double i) : real(r), imaginary(i) {}
        Complex(double r) : real(r) {}

        void print() {
            cout << "Real: " << real << ", Imaginary: " << imaginary << "\n\n";
        }

        Complex operator += (const Complex& other) {
            this->real += other.real;
            this->imaginary += other.imaginary;
            return *this;
        }

        friend bool operator == (const Complex& left, const Complex& right);        // if this was not a friend function, line 55 would've resulted in an error.
};

Complex operator+ (const Complex& left, const Complex& right) {
    Complex temp = left;
    temp += right;                      // calls overloaded member function

    return temp;
}

bool operator== (const Complex& left, const Complex& right) {
    return (left.real == right.real && left.imaginary == right.imaginary);
}

int main() {

    Complex a(5.0, 2.0);
    Complex b(2.0, 3.3);
    Complex c(3.3, 11.2);

    a += b;                             // calls the overloaded operator
    a.print();

    Complex d = b + c;                  // calls the operator+ method
    d.print();

    Complex e = 1 + d;                  // 1 is converted to the object of type complex because of the third constructor, and then the operator+ method is called
    e.print();

    Complex f(1.0);
    cout << "Bool result: " << boolalpha << (1 == f) << "\n";

    cout << endl;
    return 0;
}