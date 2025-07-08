#include <iostream>
#include <Windows.h>
using namespace std;

class KyoChon{
public:
    void make_chicken() {
        int n;
        cout << "닭을 기름에 넣는다. \n";
        for(n=5; n >=1; n--) {
            cout << "닭을" << n << "분간 더 튀깁니다.\n ";
            Sleep(2000);
        }
        cout << "닭이 다 익었습니다." <<endl;
    }
};
class Padak : public KyoChon {
public:
    Padak();
    void make_chicken(){
        pd -> make_chicken();
        cout << "파를 100그램 얹습니다." << endl;
    }
private:
    KyoChon *pd;
};

Padak :: Padak() {
    pd = new KyoChon();
}

int main() {
    Padak p1;
    p1.make_chicken();
    return 0;
}