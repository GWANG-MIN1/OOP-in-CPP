#include <iostream>
using namespace std;

class Rect {
protected:    
    int width, height;

public: 
    Rect() { width = 1; height = 2; }  // 기본 생성자
    Rect(int w, int h) { width = w; height = h; }  // 필요한 생성자 추가
    int area() { return width * height; }
};

class Square : public Rect {
public:
    Square() { width = 2; height = 2; }
    Square(int w, int h) : Rect(w, h) {}
};

int main() {
    Square s(3, 4);
    cout << s.area() << endl;  // 출력: 12
}
