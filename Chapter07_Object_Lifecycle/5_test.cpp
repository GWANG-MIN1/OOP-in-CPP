#include <iostream>
using namespace std;

class Rect {
    int m_width;
    int m_height;
public:
    // 기본 생성자 추가
    // 객체가 생성될 때 자동으로 호출되어 멤버 변수를 초기화합니다.
    Rect() : m_width(5), m_height(6) {
        // 멤버 이니셜라이저 리스트를 사용하여 변수 초기화
    }

    void show() {
        cout << "면적: " << m_width * m_height << endl;
    }
};

// C++ 표준에 따라 int main()을 사용합니다.
int main() {
    Rect* rect; // Rect 클래스 포인터 선언
    rect = new Rect(); // new를 이용해 객체 생성 (이때 생성자가 호출됨)

    rect->show(); // 함수 show() 호출

    delete rect; // 동적으로 할당된 메모리 해제
    return 0;
}