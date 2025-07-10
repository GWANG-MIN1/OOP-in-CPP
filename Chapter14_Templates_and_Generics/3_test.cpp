#include <iostream>

// std 네임스페이스 사용
using namespace std;

// 두 아이템 중 더 큰 값을 찾는 템플릿 함수.
// 비교 연산자(>)를 사용하도록 올바르게 수정되었습니다.
template <typename T>
T maxi(T x, T y) {
    return (x > y) ? x : y;
}

// 사각형의 너비와 높이를 나타내는 클래스
class Rect {
private:
    int w, h;

public:
    // 너비와 높이를 초기화하는 생성자
    Rect(int w, int h) : w(w), h(h) {}

    bool operator>(const Rect &r) {
        return this->area() > r.area();
    }

    int area() const {
        return w * h;
    }

    // 사각형의 크기를 출력하는 함수
    void show() {
        cout << "사각형 " << w << "x" << h << endl;
    }
};

int main() {
    // 'a'와 'b' 두 Rect 객체를 올바르게 선언
    Rect a(1, 2); // 넓이 = 2
    Rect b(2, 3); // 넓이 = 6
    Rect c = maxi(a,b);
    c.show();

    return 0; // 프로그램 성공적 종료
}