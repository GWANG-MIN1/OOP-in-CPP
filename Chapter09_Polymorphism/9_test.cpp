#include <iostream>
using namespace std;

class Rect {
public:
    // 생성자 정의
    Rect(int w, int h) : m_width(w), m_height(h) {}

    // 연산자 * 정의 (단항 연산자 오버로딩)
    int operator*() const {
        return m_width * m_height;
    }

private:
    int m_width, m_height;
};

int main() {
    Rect r(2, 3); // width 2, height 3
    cout << *r << endl;  // 출력: 6
}
