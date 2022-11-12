#include<iostream>
using namespace std;


auto return_lambda(string x) {
    return [x](){x + ", " + "concatinated";};
}

int main() {

    string hello {"Hello"};
    auto lambda_ex = return_lambda(hello);

    lambda_ex();
    
    cout << endl;
    return 0;
}