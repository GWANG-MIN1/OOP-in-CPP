#include <iostream>
using namespace std;

class Dog{
    public:
        static int numDog;
        int mynum;
        ~Dog() {cout << "dog" << mynum << " is dead. \n";}
        Dog() {mynum = numDog++; cout << "Dog" << mynum << " is born . \n";}

};
int Dog :: numDog = 0;
int main() {
    Dog *d;
    d = new Dog[5];
    delete[] d ;
}