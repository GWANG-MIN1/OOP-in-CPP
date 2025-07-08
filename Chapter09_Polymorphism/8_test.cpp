#include <iostream>
using namespace std;

class INT {
public:
    INT() : m_data(0) {}
    INT(int i) : m_data(i) {}

    // 연산자 + 오버로딩 (멤버 함수)
    INT operator+(const INT& other) const {
        return INT(this->m_data + other.m_data);
    }

    // 연산자 * 오버로딩 (멤버 함수)
    INT operator*(const INT& other) const {
        return INT(this->m_data * other.m_data);
    }

    int getValue() const { return m_data; }

private:
    int m_data;
};

int main() {
    INT x(3), y(4), a, m;
    a = x + y;
    cout << a.getValue() << endl;  // 7
    m = x * y;
    cout << m.getValue() << endl;  // 12
}
