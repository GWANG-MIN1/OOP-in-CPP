#include <iostream>

int main() {
    int number = 88;
    int* pNumber = &number;  // 포인터 선언 및 초기화

    // pNumber에 저장된 주소 값 출력
    std::cout << "Address stored in pNumber: " << pNumber << std::endl;
    
    // pNumber가 가리키는 주소의 값 출력 (역참조)
    std::cout << "Value at that address: " << *pNumber << std::endl;

    // 포인터를 통해 원본 변수의 값 변경
    *pNumber = 99;
    std::cout << "New value of number: " << number << std::endl; 

    return 0;
}