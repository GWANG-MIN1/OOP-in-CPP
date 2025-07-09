#include <iostream>
using namespace std;

class Figure {
public:
    Figure(float w, float h) : m_width(w), m_height(h) {}
    virtual float area() { return m_width * m_height; }  // 면적 계산
protected:
    float m_width;
    float m_height;
};

class Parallelogram : public Figure {
public:
    Parallelogram(float w, float h, float degree)
        : Figure(w, h), m_degree(degree) {}

    float area() override {  // 오버라이딩: 매개변수 없이 재정의
        return m_width * m_height * m_degree;// 삼각함수 사용
    }

private:
    float m_degree;
};

int main() {
    Figure f(3, 4);
    Parallelogram p(4, 3, 60.0);
    cout << "면적 = " << f.area() << endl;
    cout << "사각형(60도)의 면적 = " << p.area() << endl;
}
