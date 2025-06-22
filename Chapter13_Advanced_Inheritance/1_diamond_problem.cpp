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
};

// 중간 파생 클래스 1
class Student : public Person {
public:
    Student(const std::string& n) : Person(n) {
        std::cout << "Student constructor called." << std::endl;
    }
    ~Student() {
        std::cout << "Student destructor called." << std::endl;
    }
};

// 중간 파생 클래스 2
class Faculty : public Person {
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
    // 각 부모의 생성자를 호출해야 함
    TeachingAssistant(const std::string& n) 
        : Student(n), Faculty(n) {
        std::cout << "TeachingAssistant constructor called." << std::endl;
    }
    ~TeachingAssistant() {
        std::cout << "TeachingAssistant destructor called." << std::endl;
    }
};

int main() {
    std::cout << "--- Creating a TeachingAssistant object ---" << std::endl;
    TeachingAssistant ta("John Doe");
    std::cout << "-----------------------------------------" << std::endl;
    
    // ta.name = "Jane"; // 컴파일 오류! 모호함 (ambiguous)
    // Student를 통한 name과 Faculty를 통한 name 중 어느 것인지 알 수 없음

    std::cout << "\n--- Deleting a TeachingAssistant object ---" << std::endl;
    // Person 생성자가 두 번 호출된 것을 통해 다이아몬드 문제를 확인할 수 있음
    return 0;
}