#include <iostream>
using namespace std;

class Animal{
public :
    virtual void monya() {cout << "동물! \n";}
    void whatRU () {cout << "An animal!\n";}
};
class Dog : public Animal{
public:
    virtual void monya() {cout << "멍멍이! \n";}
    void whatRU () {cout << "A Dog!\n";}
};

int  main()
{
    Animal *ap ; 
    Animal a2;
    Dog *fido = new Dog(); 
    Dog doggy;
    ap = fido; a2 = doggy;

    fido -> monya(); fido -> whatRU();
    ap -> monya(); ap -> whatRU();
    a2.monya(); a2.whatRU();
}