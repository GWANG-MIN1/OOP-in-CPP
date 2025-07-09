#include <iostream>
class COUT {
public:
    COUT& operator << (int i) {
        std::cout << i << std :: endl;
        return *this;
    }
    COUT& operator << (const char* i) {
        std:: cout << i << std :: endl;
        return *this;
    }
    COUT& operator << (double i) {
        std:: cout << i << std :: endl;
        return *this;
    }
    
};

int main() {
    COUT cout;
    cout << 99 << "Hello world" << 3.14;
}

