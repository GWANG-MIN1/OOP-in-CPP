#include <iostream>
#include <string>

class BankAccount {
private:
    // 멤버 변수들은 외부에서 접근할 수 없도록 private으로 선언 (정보 은닉)
    std::string ownerName;
    double balance;

    // 클래스 내부에서만 사용될 헬퍼 함수도 private으로 선언 가능
    bool isValidAmount(double amount) const {
        return amount > 0;
    }

public:
    // 생성자: 객체 생성 시 호출됨
    BankAccount(std::string name, double initialDeposit) {
        ownerName = name;
        if (isValidAmount(initialDeposit)) {
            balance = initialDeposit;
        } else {
            balance = 0.0;
        }
        std::cout << ownerName << "'s account created. Initial balance: " << balance << std::endl;
    }

    // public 메서드(인터페이스)를 통해서만 private 데이터에 접근 가능
    
    // Setter: 입금 기능. 데이터의 무결성을 검사하는 로직을 포함할 수 있음.
    void deposit(double amount) {
        if (isValidAmount(amount)) {
            balance += amount;
            std::cout << "Deposit successful. New balance: " << balance << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    // Setter: 출금 기능. 데이터의 무결성을 검사하는 로직을 포함할 수 있음.
    void withdraw(double amount) {
        if (!isValidAmount(amount)) {
            std::cout << "Invalid withdrawal amount." << std::endl;
        } else if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
        } else {
            std::cout << "Insufficient funds for withdrawal." << std::endl;
        }
    }

    // Getter: 잔액 조회 기능. const를 붙여 이 함수가 멤버 변수를 변경하지 않음을 명시.
    double getBalance() const {
        return balance;
    }

    std::string getOwnerName() const {
        return ownerName;
    }
};

int main() {
    BankAccount myAccount("John Doe", 1000.0);
    std::cout << "------------------------------------" << std::endl;

    // myAccount.balance = -500; // 컴파일 오류! private 멤버에 직접 접근 불가

    std::cout << "Current balance for " << myAccount.getOwnerName() << ": " << myAccount.getBalance() << std::endl;

    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);
    myAccount.withdraw(2000.0); // "Insufficient funds" 메시지 출력
    myAccount.deposit(-100.0); // "Invalid deposit" 메시지 출력

    std::cout << "------------------------------------" << std::endl;
    std::cout << "Final balance: " << myAccount.getBalance() << std::endl;

    return 0;
}