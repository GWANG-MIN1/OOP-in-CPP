#include <iostream>
#include <string>

// 잘못된 설계: 모든 멤버가 public으로 노출됨
class BadBankAccount {
public:
    std::string ownerName;
    double balance;

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
    }
    
    void display() {
        std::cout << "Owner: " << ownerName << ", Balance: " << balance << std::endl;
    }
};

int main() {
    BadBankAccount myAccount;
    myAccount.ownerName = "John Doe";
    myAccount.balance = 1000.0;
    
    std::cout << "Initial state:" << std::endl;
    myAccount.display();
    
    // 외부에서 잔액을 직접 조작하여 객체의 무결성이 깨지는 심각한 문제 발생
    std::cout << "\nDirectly manipulating balance to a negative value..." << std::endl;
    myAccount.balance = -500.0;
    
    std::cout << "State after manipulation:" << std::endl;
    myAccount.display(); // balance가 음수가 되는, 비논리적인 상태가 됨

    return 0;
}