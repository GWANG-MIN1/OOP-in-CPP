#include <iostream>
using namespace std;

class Rect {
public:
    int m_width;
    int m_height;
    void show() {
        cout << "면적: " << m_width * m_height <<endl;
           };
};

int main()
{
    Rect *rect;//클래스 포인터 할당 
    rect = new Rect;//new를 이용하여 동적 메모리 할당
    rect -> m_width = 5;
    rect -> m_height = 6;
    rect ->show (); //메서드 show() 호출 
}