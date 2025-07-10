#include <iostream>
using namespace std;

class Complex {
public:
    Complex() : re(0), im(0) {}
    Complex(double r, double i) : re(r), im(i) {}
    void print() { cout << re << "+" << im << "i\n"; }

    // friend 함수 선언
    friend Complex operator*(int b, Complex a);
    friend Complex operator+(Complex a, Complex b);

private:
    double re, im;
};

// 외부 연산자 함수 정의
Complex operator*(int b, Complex a) {
    return Complex(a.re * b, a.im * b);
}

Complex operator+(Complex a, Complex b) {
    return Complex(a.re + b.re, a.im + b.im);
}

int main() {
    Complex a(1.1, 2.2), b(2.2, 1.1);
    Complex c;
    c = 2 * (a + b); // 6.6 + 6.6i
    c.print();
}
