#include <iostream>
using namespace std;

struct Bird {
    char name[10];
    void fly() {
        cout << "I Can Fly\n";
    }
    void sing() {
        cout << "La La La\n";
    }
};

int main() {
    Bird b;
    b.fly();
    b.sing();
    return 0;
}
