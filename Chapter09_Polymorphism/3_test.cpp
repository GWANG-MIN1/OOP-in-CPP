#include <iostream>
using namespace std;

class Figure {
protected:
    float width, height;

public:
    Figure() : width(0), height(0) {}
    Figure(float w, float h) : width(w), height(h) {}

    virtual void setsize(float w, float h) {
        width = w;
        height = h;
    }

    virtual float area() = 0; // 순수가상함수: 추상 클래스
};

class Triangle : public Figure {
public:
    float area() override {
        return width * height / 2.0;
    }
};

class Rectangle : public Figure {
public:
    float area() override {
        return width * height;
    }
};

int main() {
    Figure* f = nullptr;

    int type;
    float width, height;

    cout << "타입과 너비, 높이를 입력하세요 (0: 삼각형, 1: 사각형): ";
    cin >> type >> width >> height;

    if (type == 0) {
        f = new Triangle();
        f->setsize(width, height);
        cout << "삼각형의 면적은 " << f->area() << endl;
    } else {
        f = new Rectangle();
        f->setsize(width, height);
        cout << "사각형의 면적은 " << f->area() << endl;
    }

    delete f; // 메모리 해제
    return 0;
}
