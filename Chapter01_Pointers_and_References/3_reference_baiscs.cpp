#include <iostream>

int main() {
    int original = 100;
    int& ref = original; // ref는 original의 별명(alias)

    std::cout << "Original: " << original << ", Reference: " << ref << std::endl;
    std::cout << "Address of original: " << &original << std::endl;
    std::cout << "Address of reference: " << &ref << std::endl; 

    ref = 200; // 참조를 통해 값을 변경하면 원본 변수의 값도 변경됨
    
    std::cout << "After modification -> Original: " << original << std::endl;
    
    return 0;
}