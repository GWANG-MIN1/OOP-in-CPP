#include <iostream>
#include <string>
using namespace std;

// [1] Logger 인터페이스
class Logger {
public:
    virtual void log(string s) = 0;
};

// [2] Printer 클래스 (기존 기능)
class Printer {
public:
    void print(string s) {
        cout << s << endl;
    }
};

// [3] PrintLogger: 객체 어댑터 방식
class PrintLogger : public Logger {
public:
    PrintLogger(Printer* p) {
        m_str = p;
    }

    void log(string s) override {
        m_str->print(s);  // Printer 기능 위임
    }

private:
    Printer* m_str;  // Printer 객체 포함
};

// [4] App: Logger 인터페이스만 사용
class App {
    Logger* mylogger;

public:
    App(Logger* pl) {
        mylogger = pl;
    }

    void start() {
        mylogger->log("홍길동: 시스템 이상 무");
    }
};

// [5] main 함수
int main() {
    Printer* p1 = new Printer();
    Logger* logger = new PrintLogger(p1);  // Printer를 포함하는 Logger

    App* r1 = new App(logger);
    r1->start();

    // 정리
    delete p1;
    delete logger;
    delete r1;

    return 0;
}
