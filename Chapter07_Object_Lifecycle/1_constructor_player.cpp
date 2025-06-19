#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int level;

public:
    // 1. 기본 생성자 (Default Constructor)
    Player() {
        name = "Unknown";
        level = 1;
        std::cout << "기본 생성자 호출! " << name << " 생성." << std::endl;
    }

    // 2. 매개변수 있는 생성자 (Parameterized Constructor)
    Player(std::string pName, int pLevel) {
        name = pName;
        level = pLevel;
        std::cout << "매개변수 생성자 호출! " << name << " 생성." << std::endl;
    }

    void showStatus() const {
        std::cout << "Name: " << name << ", Level: " << level << std::endl;
    }
};

int main() {
    Player p1; // 기본 생성자 호출
    Player p2("Hero", 10); // 매개변수 있는 생성자 호출

    p1.showStatus();
    p2.showStatus();
    
    return 0;
}