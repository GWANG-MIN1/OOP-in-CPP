#include <iostream>
using namespace std;
struct Rect {
    int m_width;
    int m_height;
    int area(){
        return m_width * m_height;
    }
};

int  main(){

    Rect r;
    r.m_width = 5;
    r.m_height = 6;
    cout << "면적 " << r.area() << endl;

}