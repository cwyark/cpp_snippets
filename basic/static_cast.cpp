#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Int {
    int x_;
    public:
    explicit Int(int x = 0) 
        : x_(x) { }
    operator string() {
        return to_string(x_);
    }
};

int main() {
    Int obj(3);
    string str = static_cast<string>(obj);
    cout << str.c_str() << endl;
    obj = static_cast<Int>(20);
    int a = 30;
    cout << &a << endl;
    int b = static_cast<char>(a);
    cout << &b << endl;
    cout << b << endl;
    exit(EXIT_SUCCESS);
}