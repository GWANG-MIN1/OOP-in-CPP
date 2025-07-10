#include <iostream>
#include <string>
using namespace std;

template <typename T>
T add (T a, T b) {
    return a + b;
}

int main() {
    int int_sum = add(5,3);
    cout << "정수 덧셈: " << int_sum << endl; 

    double double_sum = add(2.5, 3.7);
    cout << "실수 덧셈: " << double_sum <<endl;

    string str_num = add(string("Hello "), string("World!"));
    cout << "문자열 덧셈: " << str_num << endl;

    return 0;
}