/*
Argument Types Summary

Lvalue:
    -> We can pass an lvalue
    -> The function has a copy of the passed object's data
    -> Or we can pass a moveable rvalue
    -> The function now owns the passed object's data.

Lvalue Reference:
    -> We can pass an lvalue, but not an rvalue.
    -> The function can modify the passed object's data through reference

Const lvalue Reference:
    -> We can pass an lvalue or an rvalue.
    -> The function cannot modify the passed object's data through the reference.

RValue Reference:
    -> We can pass a moveable rvalue, but not an lvalue.
    -> The function now owns the passed object's data.
*/

#include<iostream>

using namespace std;

//Func's argument is an R value reference.
void moveRValue(int && x) {

    cout << "moveRValue: Received Value: " << x << "\n";
    x = 10;
}

int main() {

    int y = 5;
    moveRValue(2);
    //moveRValue(y);                Error, cannot move L-Value to this function.
    moveRValue(std::move(y));       // Inorder to move the L-value to a function expecting R value, use std::move()
    cout << "Y after moving: " << y << "\n";


    cout << endl;
    return 0;
}