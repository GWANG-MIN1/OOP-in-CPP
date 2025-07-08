#include <iostream>
using namespace std;

int max(int i, int j) {
    return i > j ? i:j;   
}

int max(int a, int b, int c) {
    return max(max(a,b),c);
}


int main() {
    int x,y,z;
    while(cin >>x >>y>>z) {
        cout << max(x,y,z) << endl;
    }
}