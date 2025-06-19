#include <iostream>
#include <string>

// --- 클래스 선언부 ---
// 클래스 안에는 함수의 선언(프로토타입)만 남겨둡니다.
class Dog {
private:
    std::string name;
    int age;

public:
    // 생성자 선언
    Dog(std::string dogName, int dogAge);
    
    // 멤버 함수 선언
    void bark() const;
    void setAge(int newAge);
    int getAge() const;
};

// --- 멤버 함수 구현부 ---
// 스코프 해석 연산자(::)를 사용하여 각 함수가 Dog 클래스 소속임을 명시합니다.

Dog::Dog(std::string dogName, int dogAge) {
    name = dogName;
    age = dogAge;
    std::cout << name << " (이)가 태어났습니다! (외부 정의)" << std::endl;
}

void Dog::bark() const {
    std::cout << name << "가 짖습니다: 멍멍! (외부 정의)" << std::endl;
}

void Dog::setAge(int newAge) {
    if (newAge > 0 && newAge < 30) {
        age = newAge;
    }
}

int Dog::getAge() const {
    return age;
}


// --- main 함수 (테스트) ---
int main() {
    Dog aDog("뭉치", 2);
    
    std::cout << "현재 나이: " << aDog.getAge() << "살" << std::endl;
    aDog.bark();
    
    aDog.setAge(3);
    std::cout << "새 나이: " << aDog.getAge() << "살" << std::endl;

    return 0;
}