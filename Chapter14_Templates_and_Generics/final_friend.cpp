#include <iostream>
#include <string>
using namespace std;

class Human{
private:
    string secret =  "나는 사실 햄버거를 좋아해";
    friend void showSecret(const Human& human);

public:
    string name;
    Human(string name) : name(name) {}
};

void showSecret(const Human& human) {
     cout << human.name << "의 비밀: " << human.secret << endl;
}

int main() {
    Human friend1("철수");
    showSecret(friend1);
    return 0;
}