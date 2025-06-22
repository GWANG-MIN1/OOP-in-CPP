#include <iostream>

// 기반 클래스
class Base {
public:
    Base() { std::cout << "1. Base constructor" << std::endl; }
    ~Base() { std::cout << "4. Base destructor" << std::endl; }
};

// 파생 클래스
class Derived : public Base {
public:
    Derived() { std::cout << "2. Derived constructor" << std::endl; }
    ~Derived() { std::cout << "3. Derived destructor" << std::endl; }
};

int main() {
    std::cout << "--- Creating Derived object ---" << std::endl;
    Derived d;
    std::cout << "--- Deleting Derived object ---" << std::endl;
    
    // main 함수가 끝나면 d가 소멸되면서 소멸자가 역순으로 호출됨
    // 출력 순서: 1 -> 2 -> 3 -> 4
    return 0;
}