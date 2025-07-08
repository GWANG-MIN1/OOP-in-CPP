#include <iostream>
#include <cstring>  // for strcpy, strlen
using namespace std;

class Str {
private:
    char* strdata;

public:
    // 기본 생성자
    Str() {
        strdata = new char[1];
        strdata[0] = '\0';
    }

    // 대입 연산자 오버로딩 (const char* 사용)
    Str& operator=(const char* s) {
        delete[] strdata;  // 기존 메모리 해제
        strdata = new char[strlen(s) + 1];
        strcpy(strdata, s);
        return *this;
    }

    void show() {
        cout << strdata << endl;
    }

    // 소멸자
    ~Str() {
        delete[] strdata;
    }
};

int main() {
    Str t;
    t = "Hello";  // 끝에 세미콜론 `;` 필요 (`,` 아님!)
    t.show();
}
