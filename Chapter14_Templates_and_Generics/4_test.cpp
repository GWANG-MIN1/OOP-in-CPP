#include <iostream>
using namespace std;

// 템플릿 클래스 선언
template <typename T>
class Rect {
private:
    T w, h;

public:
    Rect(T w, T h) : w(w), h(h) {}

    T area() {
        return w * h;
    }
};

int main() {
    // 정수형 사각형
    Rect<int> a(2, 3);
    // 실수형 사각형
    Rect<double> b(2.5, 3.5);

    cout << a.area() << endl;  // 출력: 6
    cout << b.area() << endl;  // 출력: 8.75
}
