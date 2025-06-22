#include <iostream>
#include <string>

// 최상위 기반 클래스
class Person {
protected:
    std::string name;
public:
    Person(const std::string& n) : name(n) {
        std::cout << "Person constructor called for: " << name << std::endl;
    }
    ~Person() {
        std::cout << "Person destructor called for: " << name << std::endl;
    }
    void printName() const {
        std::cout << "My name is " << name << std::endl;
    }
};

// 가상 상속을 사용하는 중간 파생 클래스 1
class Student : virtual public Person {
public:
    Student(const std::string& n) : Person(n) {
        std::cout << "Student constructor called." << std::endl;
    }
    ~Student() {
        std::cout << "Student destructor called." << std::endl;
    }
};

// 가상 상속을 사용하는 중간 파생 클래스 2
class Faculty : virtual public Person {
public:
    Faculty(const std::string& n) : Person(n) {
        std::cout << "Faculty constructor called." << std::endl;
    }
    ~Faculty() {
        std::cout << "Faculty destructor called." << std::endl;
    }
};

// 최하위 파생 클래스
class TeachingAssistant : public Student, public Faculty {
public:
    // 가장 마지막 파생 클래스가 가상 기반 클래스의 생성자를 명시적으로 호출해야 함
    TeachingAssistant(const std::string& n) 
        : Person(n), Student(n), Faculty(n) {
        std::cout << "TeachingAssistant constructor called." << std::endl;
    }
    ~TeachingAssistant() {
        std::cout << "TeachingAssistant destructor called." << std::endl;
    }
};

int main() {
    std::cout << "--- Creating a TeachingAssistant object ---" << std::endl;
    TeachingAssistant ta("Jane Doe");
    std::cout << "-----------------------------------------" << std::endl;
    
    // 이제 모호성 없이 name 멤버에 접근 가능
    ta.printName();

    std::cout << "\n--- Deleting a TeachingAssistant object ---" << std::endl;
    // Person 생성자가 단 한 번만 호출된 것을 통해 다이아몬드 문제가 해결되었음을 확인할 수 있음
    return 0;
}