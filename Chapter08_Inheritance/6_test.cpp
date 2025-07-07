#include <iostream>
using namespace std;

// 추상 클래스 (다형성의 기반)
class Polygon {
protected:
    int m_width, m_height;

public:
    void setSize(int w, int h) {
        m_width = w;
        m_height = h;
    }

    virtual int area() = 0;  // 순수 가상 함수 → 다형성
};

// 사각형 클래스
class Rectangle : public Polygon {
public:
    int area() override {
        return m_width * m_height;
    }
};

// 삼각형 클래스
class Triangle : public Polygon {
public:
    int area() override {
        return (m_width * m_height) / 2;
    }
};

// main 함수 (시작점)
int main() {
    Rectangle r;
    r.setSize(3, 4);  // 너비 3, 높이 4

    Triangle t;
    t.setSize(10, 5);  // 너비 10, 높이 5

    int r_a = r.area();
    int t_a = t.area();

    cout << "사각형의 넓이 = " << r_a << endl;
    cout << "삼각형의 넓이 = " << t_a << endl;

    return 0;
}
