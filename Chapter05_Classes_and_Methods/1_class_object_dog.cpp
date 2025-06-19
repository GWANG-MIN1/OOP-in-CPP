#include <iostream>
#include <string>

class Dog {
private: // 정보 은닉: 데이터 멤버는 private으로 보호
    std::string name;
    int age;

public: // 공개 인터페이스: 멤버 함수는 public으로 제공
    // 생성자: 객체 생성 시 이름과 나이를 초기화
    Dog(std::string dogName, int dogAge) {
        name = dogName;
        age = dogAge;
        std::cout << name << " (이)가 태어났습니다!" << std::endl;
    }

    // Setter 메서드
    void setAge(int newAge) {
        if (newAge > 0 && newAge < 30) { // 간단한 유효성 검사
            age = newAge;
        }
    }

    // Getter 메서드
    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    // 일반 멤버 함수 (메서드)
    void bark() const {
        std::cout << name << "가 짖습니다: 멍멍!" << std::endl;
    }
};

int main() {
    // Dog 클래스로부터 두 개의 객체(인스턴스) 생성
    Dog myDog("해피", 3);
    Dog yourDog("코코", 5);

    // 점 연산자(.)를 통해 public 멤버 함수 호출
    std::cout << myDog.getName() << "의 나이: " << myDog.getAge() << "살" << std::endl;
    myDog.bark();

    std::cout << yourDog.getName() << "의 나이: " << yourDog.getAge() << "살" << std::endl;
    yourDog.bark();

    // myDog.name = "슬픔"; // 컴파일 오류! 'name'은 private 멤버이므로 직접 접근 불가

    // Setter를 통해 안전하게 나이 변경
    myDog.setAge(4);
    std::cout << myDog.getName() << "의 새 나이: " << myDog.getAge() << "살" << std::endl;

    return 0;
}