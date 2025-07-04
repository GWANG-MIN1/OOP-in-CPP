#include <iostream>
#include <string>  // string 클래스 사용을 위한 헤더
using namespace std;

class Dog {
public:
    Dog(string n) : m_name(n) {}
    void show() {
        cout << "나는 " << m_name << "입니다." << endl;
    }

private:
    string m_name;
};

class Jindo : public Dog {
public:
    Jindo(string n) : Dog(n) {}
};  

int main() {
    Dog d("치와와");
    Jindo j("진도개");

    d.show();   // 출력: 나는 치와와입니다.
    j.show();   // 출력: 나는 진도개입니다.
}
