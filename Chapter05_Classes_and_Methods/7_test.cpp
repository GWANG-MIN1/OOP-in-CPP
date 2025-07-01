#include <iostream>
#include <string> // string 클래스 사용을 위해 추가

using namespace std;

class Bank_Account {
private:
    string BA_number; // 계좌번호
    string BA_name;   // 계좌주 이름
    int balance;      // 잔고

public:
    // 계좌번호 설정
    void Set_BA_number(string num) {
        BA_number = num;
    }

    // 계좌주 이름 설정
    void Set_BA_name(string name) {
        BA_name = name;
    }

    // 초기 잔고 설정
    void Set_balance(int b) {
        balance = b;
    }

    // 입금
    void Deposit(int amount) {
        balance += amount; // balance = balance + amount;
    }

    // 출금
    void Withdraw(int amount) {
        balance -= amount; // balance = balance - amount;
    }

    // 계좌 정보 출력
    void Print() {
        cout << "계좌번호: " << BA_number << endl;
        cout << "계좌주: " << BA_name << endl;
        cout << "잔고: " << balance << "원" << endl;
    }
}; // 클래스 정의 끝에 세미콜론(;) 추가

// main 함수는 int형을 반환하는 것이 표준입니다.
int main() {
    Bank_Account park; // Bank_Account 객체 생성

    // 정보 설정
    park.Set_BA_number("60212184");
    park.Set_BA_name("박광민");
    park.Set_balance(1000);

    // 입금 및 출금
    park.Deposit(500);
    park.Withdraw(300);

    // 최종 정보 출력
    park.Print();

    return 0; // 프로그램 정상 종료
}