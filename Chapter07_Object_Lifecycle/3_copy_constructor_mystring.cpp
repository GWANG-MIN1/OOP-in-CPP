#include <iostream>
#include <cstring> // strcpy, strlen 함수를 사용하기 위해

class MyString {
private:
    char* str;
    int len;

public:
    // 일반 생성자
    MyString(const char* s) {
        std::cout << "Constructor called for: " << s << std::endl;
        len = strlen(s);
        str = new char[len + 1]; // 널 문자를 위한 공간(+1) 할당
        strcpy(str, s);
    }

    // 깊은 복사를 수행하는 사용자 정의 복사 생성자
    MyString(const MyString& other) {
        std::cout << "User-defined copy constructor called (Deep Copy)." << std::endl;
        len = other.len;
        // 1. 원본과는 별개의 새로운 메모리 공간을 힙에 할당
        str = new char[len + 1];
        // 2. 원본의 내용을 새로운 공간에 복사
        strcpy(str, other.str);
    }

    // 소멸자
    ~MyString() {
        std::cout << "Destructor called for: " << str << std::endl;
        delete[] str;
    }

    void display() const {
        std::cout << str << std::endl;
    }
};

int main() {
    std::cout << "--- Creating s1 ---" << std::endl;
    MyString s1("Hello");

    std::cout << "\n--- Creating s2 from s1 ---" << std::endl;
    MyString s2 = s1; // 복사 생성자 호출 (깊은 복사 발생)

    std::cout << "\n--- Displaying strings ---" << std::endl;
    std::cout << "s1: ";
    s1.display();
    std::cout << "s2: ";
    s2.display();

    std::cout << "\n--- End of main ---" << std::endl;
    // main 함수가 끝나면 s2와 s1이 소멸됨
    // 각 객체는 자신이 할당한 별개의 메모리를 안전하게 해제함
    return 0;
}