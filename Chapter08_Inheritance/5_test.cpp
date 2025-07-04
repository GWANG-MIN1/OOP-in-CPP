#include <iostream>
#include <string>  // string 클래스 사용을 위한 헤더
using namespace std;

class Dog {
public:
    Dog(string n) : m_name(n) {}
    void bark() { cout << "멍멍~" <<endl;}
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

class FlyingDog : public Dog {
public: 
    FlyingDog (string n) : Dog (n) {}
    void fly() {cout << "훨훨!" << endl;};    
};
class NoisyDog : public Dog {
public:
    NoisyDog(string n): Dog(n) {}
    void bark() {Dog :: bark(),Dog :: bark(); }
};
int main() {
    Dog d("치와와");
    Jindo j("진도개");
    NoisyDog n ("시끄러운 개 ");
    n.show();   
    n.bark();   
}
