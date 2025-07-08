#include <iostream>
#include <string>
using namespace std;
string operator+(string s1, string s2) {
    return s1.append(s2);
}

int main() {
    string s1("Hello"), s2("world");
    cout << s1 + s2 << endl;
}