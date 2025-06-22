#include <iostream>
#include <string>

// 개선된 설계: 캡슐화와 정보 은닉 적용
class GoodBankAccount {
private:
    // 데이터 멤버를 private으로 보호
    std::string ownerName;
    double balance;

public:
    // 생성자를 통해 안전하게 초기 상태를 설정
    GoodBankAccount(const std::string& owner, double initialDeposit) {
        ownerName = owner;
        // 초기 입금액이 0보다 작으면 잔액을 0으로 설정
        balance = (initialDeposit > 0) ? initialDeposit : 0.0;
    }

    // public 인터페이스를 통해 안전하게 상태를 변경
    void deposit(double amount) {
        // 양수 금액만 입금 허용
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited " << amount << ". ";
        } else {
            std::cout << "Deposit amount must be positive. ";
        }
        displayBalance();
    }

    bool withdraw(double amount) {
        // 양수 금액이면서 잔액이 충분할 때만 출금 허용
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Withdrew " << amount << ". ";
            displayBalance();
            return true; // 출금 성공
        }
        std::cout << "Withdrawal failed. ";
        displayBalance();
        return false; // 출금 실패
    }

    // public 인터페이스를 통해 상태를 조회 (읽기 전용)
    double getBalance() const {
        return balance;
    }
    
    void displayBalance() const {
        std::cout << "Current balance is " << balance << "." << std::endl;
    }
};

int main() {
    GoodBankAccount myAccount("Jane Doe", 1000.0);
    
    // myAccount.balance = -500.0; // 컴파일 오류! private 멤버에 접근 불가
    
    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);
    myAccount.withdraw(2000.0); // 잔액 부족으로 실패
    myAccount.deposit(-100.0); // 유효하지 않은 금액으로 실패
    
    std::cout << "\nFinal balance: " << myAccount.getBalance() << std::endl;
    return 0;
}