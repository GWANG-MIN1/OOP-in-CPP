#include <iostream>
#include <string>
using namespace std;

// [1] Logger: 추상 인터페이스 역할
class Logger {
public:
    virtual void log(string s) = 0;  // 순수 가상 함수
};

// [2] Printer: 기존 클래스 (Adaptee 역할)
class Printer {
public:
    void print(string s) {
        cout << s << endl;
    }
};

// [3] PrintLogger: 어댑터 클래스 (다중 상속)
class PrintLogger : public Logger, public Printer {
public:
    void log(string s) override {
        // Printer의 print 함수를 이용하여 log 기능을 구현
        print(s);
    }
};

// [4] App: 클라이언트 (Logger만 알고 있음)
class App {
    Logger* mylogger;

public:
    App(Logger* pl) { mylogger = pl; }

    void start() {
        mylogger->log("박광민: 시스템 이상 무");
    }
};

// [5] main 함수
int main() {
    App* r1;
    r1 = new App(new PrintLogger());
    r1->start();

    delete r1; // 메모리 해제 (good practice)
    return 0;
}
