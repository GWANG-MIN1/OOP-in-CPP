#include <iostream>

class Student {
private:
    char name[15];
    int kor;
    int eng;
    int math;

public:
    // 1. 기본 생성자 (Default Constructor)
    // 객체가 생성될 때 이름, 국어, 영어, 수학 점수를 기본값("NONE", 0, 0, 0)으로 초기화합니다.
    Student() {
        setName("NONE");
        kor = 0;
        eng = 0;
        math = 0;
    }

    // 2. 초기화 생성자 (Initializer Constructor)
    // 객체를 생성함과 동시에 전달받은 값들로 멤버 변수를 초기화합니다.
    Student(const char* newName, int newKor, int newEng, int newMath) {
        setName(newName);
        kor = newKor;
        eng = newEng;
        math = newMath;
    }

    // --- Setter & Getter 함수 ---
    void setName(const char* newName) {
        for (int i = 0; i < 14; i++) {
            name[i] = newName[i];
            if (newName[i] == '\0') {
                break;
            }
        }
        name[14] = '\0';
    }

    void setKor(int newKor) { kor = newKor; }
    void setEng(int newEng) { eng = newEng; }
    void setMath(int newMath) { math = newMath; }

    const char* getName() const { return name; }
    int getKor() const { return kor; }
    int getEng() const { return eng; }
    int getMath() const { return math; }
};

int main() {
    // 3. Student 객체 포인터 A, B, C 선언
    Student *A, *B, *C;

    // new 키워드를 사용해 객체를 동적으로 생성하고, 초기화 생성자를 호출합니다.
    A = new Student("Kim", 95, 95, 90);
    B = new Student("Park", 90, 85, 90);
    C = new Student("Lee", 95, 95, 95);

    // 각 객체의 정보 출력 (포인터이므로 '->' 연산자 사용)
    std::cout << "--- 학생 정보 ---" << std::endl;
    std::cout << "학생 A: " << A->getName() << ", " << A->getKor() << ", " << A->getEng() << ", " << A->getMath() << std::endl;
    std::cout << "학생 B: " << B->getName() << ", " << B->getKor() << ", " << B->getEng() << ", " << B->getMath() << std::endl;
    std::cout << "학생 C: " << C->getName() << ", " << C->getKor() << ", " << C->getEng() << ", " << C->getMath() << std::endl;

    // 동적으로 할당한 메모리 해제
    delete A;
    delete B;
    delete C;

    return 0;
}