#include <iostream>

// 참조에 의한 전달(pass-by-reference)을 사용하는 swap 함수
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int first = 10;
    int second = 20;

    std::cout << "Before swap: ";
    std::cout << "first = " << first << ", second = " << second << std::endl;

    // swap 함수를 호출하면 first와 second의 원본 값이 직접 변경됨
    swap(first, second);

    std::cout << "After swap:  ";
    std::cout << "first = " << first << ", second = " << second << std::endl;

    return 0;
}