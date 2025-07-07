#include <iostream>
using namespace std;

class Animal {
public:
    Animal(string n) : a_name(n) {}

    void show() { // virtual ❌
        cout << "Animal " << a_name << endl;
    }

protected:
    string a_name;
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    void show() { // 오버라이딩 아님 → 함수 숨김(hiding)
        cout << "Dog " << a_name << endl;
    }
};

int main() {
    Animal* a = new Dog("개"); // 부모 포인터 → 자식 객체
    Dog* d = new Dog("개");

    a->show(); // Animal::show() 호출 (정적 바인딩)
    d->show(); // Dog::show() 호출

    delete a;
    delete d;
    return 0;
}
