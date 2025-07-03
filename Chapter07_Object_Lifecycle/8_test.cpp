#include <iostream>
using namespace std;

class Rect {
    int m_width, m_height;
public:
    Rect(){m_width= 1, m_height=1;}
    Rect(int w) {m_width = w , m_height = w;}
    Rect(int w, int h) {m_width =w, m_height = h;}
    void area() {cout << "면적 " << m_width * m_height << endl;}
}; //클래스 선언한 후에 세미콜론 찍기 
int main(){
    Rect * r1 = new Rect();
    r1 -> area();
    Rect *r2 = new Rect(2);
    r2 -> area();
    Rect *r3 = new Rect(3,4);
    r3 -> area();
}   