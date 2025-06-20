#include <iostream>
#include <string>

// 기본 클래스 (Base Class)
class Shape {
protected: // 파생 클래스에서 접근 가능하도록 protected로 선언
    int x, y;
    std::string color;
public:
    // 기본 클래스 생성자
    Shape(int x_coord, int y_coord, std::string c) 
        : x(x_coord), y(y_coord), color(c) {
        std::cout << "Shape constructor called." << std::endl;
    }

    // 기본 클래스 소멸자
    ~Shape() {
        std::cout << "Shape destructor called." << std::endl;
    }

    void draw() const {
        std::cout << "Drawing a " << color << " shape at (" << x << ", " << y << ")" << std::endl;
    }
};

// 파생 클래스 (Derived Class)
// Rectangle은 Shape의 한 종류이다. (is-a 관계)
class Rectangle : public Shape {
private:
    int width, height;
public:
    // 파생 클래스 생성자
    // 초기화 리스트를 통해 기본 클래스의 생성자를 명시적으로 호출해야 함.
    Rectangle(int x, int y, std::string c, int w, int h) 
        : Shape(x, y, c), width(w), height(h) {
        std::cout << "Rectangle constructor called." << std::endl;
    }

    // 파생 클래스 소멸자
    ~Rectangle() {
        std::cout << "Rectangle destructor called." << std::endl;
    }

    // 메서드 오버라이딩 (Method Overriding)
    // 부모와 동일한 이름, 동일한 매개변수 리스트를 가진 함수를 자식이 재정의
    void draw() const {
        std::cout << "Drawing a " << color << " rectangle of size " 
                  << width << "x" << height << " at (" << x << ", " << y << ")" << std::endl;
    }

    // 파생 클래스에만 있는 새로운 기능
    int getArea() const {
        return width * height;
    }
};

int main() {
    std::cout << "--- Creating Rectangle object ---" << std::endl;
    Rectangle rect(10, 20, "blue", 100, 50);
    
    std::cout << "\n--- Calling methods ---" << std::endl;
    // 오버라이딩된 자식 클래스의 draw()가 호출됨
    rect.draw(); 
    std::cout << "Area: " << rect.getArea() << std::endl;

    // 스코프 해석 연산자(::)를 사용하면 부모 클래스의 버전을 명시적으로 호출 가능
    rect.Shape::draw(); 

    std::cout << "\n--- Deleting Rectangle object ---" << std::endl;
    // main 함수가 끝나면 rect 객체가 소멸되면서 소멸자가 역순으로 호출됨
    return 0;
}