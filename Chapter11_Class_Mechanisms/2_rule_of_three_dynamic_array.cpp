#include <iostream>
#include <algorithm> // std::copy 사용

class DynamicArray {
private:
    int* data;
    size_t size;

public:
    // 생성자: 동적 메모리 할당
    DynamicArray(size_t s) : size(s), data(new int[s]) {
        std::cout << "Constructor: Allocated memory for " << size << " integers." << std::endl;
    }

    // 1. 소멸자: 할당된 메모리 해제
    ~DynamicArray() {
        std::cout << "Destructor: Freed memory." << std::endl;
        delete[] data;
    }

    // 2. 복사 생성자 (깊은 복사)
    DynamicArray(const DynamicArray& other) : size(other.size), data(new int[other.size]) {
        std::cout << "Copy Constructor (Deep Copy): Copied " << size << " integers." << std::endl;
        std::copy(other.data, other.data + size, data);
    }

    // 3. 복사 대입 연산자 (깊은 복사)
    DynamicArray& operator=(const DynamicArray& other) {
        std::cout << "Copy Assignment Operator (Deep Copy)." << std::endl;
        if (this == &other) { // 자기 자신에 대한 대입 방지
            return *this;
        }
        
        delete[] data; // 기존 메모리 해제
        
        size = other.size;
        data = new int[size]; // 새로운 메모리 할당
        std::copy(other.data, other.data + size, data); // 내용 복사
        
        return *this;
    }
};

int main() {
    std::cout << "--- Creating arr1 ---" << std::endl;
    DynamicArray arr1(5); // 생성자

    std::cout << "\n--- Creating arr2 from arr1 ---" << std::endl;
    DynamicArray arr2 = arr1; // 복사 생성자

    std::cout << "\n--- Creating arr3 and assigning arr1 to it ---" << std::endl;
    DynamicArray arr3(2);
    arr3 = arr1; // 복사 대입 연산자

    std::cout << "\n--- End of main ---" << std::endl;
    // main 함수가 끝나면 arr1, arr2, arr3가 소멸되며 각 소멸자가 호출됨
    return 0;
}