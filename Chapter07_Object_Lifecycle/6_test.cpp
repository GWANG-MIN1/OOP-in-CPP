#include <iostream>
using namespace std;

class Card {
public:
    // 클래스 변수(정적 멤버 변수) num_instance 선언
    static int num_instance;
    int m_data;

    // 기본 생성자
    Card() {
        cout << "일련 번호: " << ++num_instance << endl;
    }
};

// 클래스(정적) 변수 초기화 (반드시 클래스 외부에서 해야 함)
int Card::num_instance = 0;

// C++ 표준에 따라 int main()을 사용합니다.
int main() {
    Card c1;
    Card c2;
    Card c3; // 테스트를 위해 카드 한 장 더 생성

    return 0;
}