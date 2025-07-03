#include <iostream>

class Student {
private:
    char name[15];
    int kor;
    int eng;
    int math;

public:
    // 이름을 설정하는 함수 (for 반복문으로 직접 구현)
    void setName(const char* newName) { //배열을 함수 인자로 보낼때는 포인터로 전달됨 따라서 const char * 필요하다.
        
        for (int i = 0; i < 14; i++) {
            name[i] = newName[i]; // 한 글자씩 복사합니다.

            
            if (newName[i] == '\0') {
                break;
            }
        }
    
        name[14] = '\0';
    }

    // 국어 점수를 설정하는 함수
    void setKor(int newKor) {
        kor = newKor;
    }

    // 영어 점수를 설정하는 함수
    void setEng(int newEng) {
        eng = newEng;
    }

    // 수학 점수를 설정하는 함수
    void setMath(int newMath) {
        math = newMath;
    }

    // 이름을 반환하는 함수
    const char* getName() const {
        return name;
    }

    // 국어 점수를 반환하는 함수
    int getKor() const {
        return kor;
    }

    // 영어 점수를 반환하는 함수
    int getEng() const {
        return eng;
    }

    // 수학 점수를 반환하는 함수
    int getMath() const {
        return math;
    }
};

// 클래스 사용 예시
int main() {
    Student student1;

    student1.setName("홍길동");
    student1.setKor(90);
    student1.setEng(85);
    student1.setMath(95);

    std::cout << "이름: " << student1.getName() << std::endl;
    std::cout << "국어: " << student1.getKor() << std::endl;
    std::cout << "영어: " << student1.getEng() << std::endl;
    std::cout << "수학: " << student1.getMath() << std::endl;

    return 0;
}