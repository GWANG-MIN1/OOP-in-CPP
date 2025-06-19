#include <iostream>

int main() {
    // 단일 정수 동적 할당
    int* p_int = new int(42);
    std::cout << "Dynamically allocated int: " << *p_int << std::endl;

    // 단일 정수 메모리 해제
    delete p_int;
    p_int = nullptr; // 좋은 습관: 해제 후 포인터를 nullptr로 설정

    // 정수 배열 동적 할당
    int size = 5;
    int* p_array = new int[size];

    for (int i = 0; i < size; ++i) {
        p_array[i] = i * 10;
    }

    std::cout << "Dynamically allocated array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << p_array[i] << " ";
    }
    std::cout << std::endl;

    // 배열 메모리 해제
    delete[] p_array;
    p_array = nullptr; // 좋은 습관

    return 0;
}