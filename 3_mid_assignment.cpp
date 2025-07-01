#include <iostream>

class Student {
private:
    char name[15];
    int kor;
    int eng;
    int math;

public:
    // 기본 생성자
    Student() {
        setName("NONE");
        kor = 0;
        eng = 0;
        math = 0;
    }

    // 초기화 생성자
    Student(const char* newName, int newKor, int newEng, int newMath) {
        setName(newName);
        kor = newKor;
        eng = newEng;
        math = newMath;
    }

    // --- 추가된 멤버 함수 ---
    // 학생의 모든 정보를 형식에 맞춰 출력합니다.
    void showStudent() const {
        std::cout << name << "\t" << kor << "\t" << eng << "\t" << math << std::endl;
    }

    // --- 기존 Setter & Getter 함수 ---
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
    Student *A, *B, *C;

    A = new Student("Kim", 95, 95, 90);
    B = new Student("Park", 90, 85, 90);
    C = new Student("Lee", 95, 95, 95);

    // 힌트에 나온 것처럼 헤더를 먼저 출력
    std::cout << "이름\t" << "국어\t" << "영어\t" << "수학" << std::endl;
    
    // 각 객체의 showStudent() 함수를 호출하여 정보 출력
    A->showStudent();
    B->showStudent();
    C->showStudent();

    // 동적으로 할당한 메모리 해제
    delete A;
    delete B;
    delete C;

    return 0;
}