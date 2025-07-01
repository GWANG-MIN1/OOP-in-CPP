#include <iostream>
using namespace std;

struct Bird{
public:
    string name;
    void sing() {
        cout << "My name is" << 
        this -> name;
    }
};
int main(){
Bird b,c;
b.name = "Tweety";
c.name = "Birdy";
b.sing();
c.sing();
}