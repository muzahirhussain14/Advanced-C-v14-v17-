#include<iostream>


int GetValue()
{
    return 10;          // returns an l-value
}

int& GetValueRef()
{
    static int x = 10;
    return x;
}

void SetValue(int& value)
{}

void SetValueConst(const int& value)
{}

void SetRValue(int&& value)
{}

int main() {

    // 1)
    int i = 10;             // not always true, but value on left side (i) is called l-value and value on right(10) is r-value.
    int a = i;              // l-value is assigned to another l-value.


    // 2)
    int i = GetValue();     // Correct -- r-value is assigned to an l-value.
    GetValue() = 5;         // Wrong -- R-value being assigned to another R-Value 

    // However, if we return l-value reference, then it would work.
    GetValueRef() = 10;     // Correct


    // 3)
    // You cannot take an l-value reference from an r-value.
    SetValue(i);             // Correct -- Assigning l-value to an l-value reference
    SetValue(5);             // Wrong -- Assiging r-value to an l-value reference. If the function wasn't taking reference, it would've be correct


    // However, there is a special Rule. If we had a const l-value reference, we can assign it both l-value and r-value.
    int &x = 10;            // Wrong -- cannot assign an r-value to a l-value reference
    const int &x = 10;      // Correct -- Compiler probably creates a temporary variable with your value (10) and then assigns it to lvalue const.

    // Therefore we can also take this to functions.
    SetValueConst(x);       // Correct -- assigning l-value reference to another l-value reference
    SetValueConst(12);      // Correct -- as shown above const l-value reference can take r-value.
    


    // 4)
    // So-far we have a way to send only l-value to the function, which is "void SetValue(int& value)".
    // We also have a way to send both l-value and r-value to the function, which is "void SetValueConst(const int& value)".
    // Do we have a way to send only R-value? Yes -- using R-value Reference
    
    SetRValue(15);         // Correct -- The function takes R-value
    SetRValue(x);          // Wrong -- Lvalue cannot be assigned to a function taking only Rvalue.
    SetRValue(i);          // Wrong -- Lvalue cannot be assigned to a function taking only Rvalue.
    
    
    std::cout << std::endl;
    return 0;
}