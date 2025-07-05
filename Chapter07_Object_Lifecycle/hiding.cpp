#include <iostream>
using namespace std;

class Boonsoo {
private:
    int ja;
    int mo;

public:
    void set(int j, int m){
        ja = j;
        mo = m;
    }

    int get_ja() {return ja;}
    int get_mo() {return mo;}

    void Add(Boonsoo *b) {
        int new_ja = this ->ja * b -> get_mo() + b -> get_ja() * this -> mo;
        int new_mo = this -> mo * b -> get_mo();
        this -> ja = new_ja;
        this -> mo = new_mo;
    }
    void print(){
        cout << ja << "/" << mo << endl;
    }
};
Boonsoo* boonMult (Boonsoo &one, Boonsoo &two) {
        Boonsoo* result = new Boonsoo();

        int new_ja = one.get_ja() * two.get_ja();
        int new_mo = one.get_mo() * two.get_mo();

        result -> set(new_ja, new_mo);
        return result;
    }

int main(){

    Boonsoo boonA, boonB;

    boonA.set(2,3);
    boonB.set(3,5);

    boonA.print();
    boonB.print();

    Boonsoo * boonC = boonMult(boonA, boonB);
    boonC -> print();

    boonA.Add(&boonB);
    boonA.print();

    delete boonC;

    return 0;
}