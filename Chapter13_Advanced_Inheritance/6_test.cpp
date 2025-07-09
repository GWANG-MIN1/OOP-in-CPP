#include <iostream>
using namespace std;

class Dog{
public:
    void bark() {cout << "멍멍!" << endl;}
};
class Bird{
public:
    void fly() {cout << "쓩~!" <<endl;}
};

class FlyingDog : public Dog, public Bird {
};

int main() {
    FlyingDog fd;
    fd.bark();
    fd.fly();
}