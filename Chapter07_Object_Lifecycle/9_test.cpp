#include <iostream>
using namespace std;

class Dragoon{
public:
    Dragoon(int power, int life) {this -> power = power; this -> life = life;}
    //Dragoon :: power , Dragoon :: life
    //this -> power 
    //power(power)
    //m_power = power;
    void show() {cout << "힘: " << power << "\n생명: " << life << endl;}

private:
    int power;
    int life;
};

int main() {
    Dragoon d1(100,100);  
    d1.show();
}