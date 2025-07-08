#include <iostream>
using namespace std;

class Rect {
public:
    Rect(int w, int h) : m_width(w), m_height(h) {}

    // 전치 ++ (너비 증가)
    Rect& operator++() {
        m_width++;
        return *this;
    }

    // 후치 ++ (높이 증가)
    Rect operator++(int) {
        Rect temp = *this;
        m_height++;
        return temp;
    }

    // * 연산자: 넓이 반환
    int operator*() const {
        return m_width * m_height;
    }

private:
    int m_width, m_height;
};

int main() {
    Rect r(2, 3);       // width 2, height 3

    r++;                // 높이 증가 → height: 4
    cout << *r << endl; // 2 * 4 = 8

    ++r;                // 너비 증가 → width: 3
    cout << *r << endl; // 3 * 4 = 12
}
