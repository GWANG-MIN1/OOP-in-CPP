#include <iostream>
#include <string>
#include <vector>

// 기본 클래스
class Shape {
public:
    // 생성자
    Shape(int x, int y) { /* 좌표 초기화 등 */ }

    // 가상 소멸자
    // 파생 클래스의 소멸자까지 모두 호출되게 하려면 반드시 virtual로 선언해야 합니다.
    virtual ~Shape() { 
        std::cout << "Shape destructor" << std::endl; 
    }

    // 가상 함수
    // 이 함수는 파생 클래스에서 재정의(override)될 수 있습니다.
    virtual void draw() const {
        std::cout << "Drawing a generic shape." << std::endl;
    }
};

// 파생 클래스 1
class Rectangle : public Shape {
private:
    int width, height;
public:
    Rectangle(int x, int y, int w, int h) : Shape(x, y), width(w), height(h) {}
    
    ~Rectangle() { 
        std::cout << "Rectangle destructor" << std::endl; 
    }

    // 부모의 가상 함수를 재정의 (override 키워드는 실수를 방지해주는 좋은 습관)
    void draw() const override {
        std::cout << "Drawing a rectangle." << std::endl;
    }
};

// 파생 클래스 2
class Circle : public Shape {
private:
    int radius;
public:
    Circle(int x, int y, int r) : Shape(x, y), radius(r) {}

    ~Circle() { 
        std::cout << "Circle destructor" << std::endl; 
    }

    // 부모의 가상 함수를 재정의
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

int main() {
    // 부모 클래스 포인터의 벡터를 사용하여 다양한 자식 객체들을 관리
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle(0, 0, 10, 20));
    shapes.push_back(new Circle(10, 10, 5));
    shapes.push_back(new Rectangle(20, 20, 30, 30));

    std::cout << "--- Drawing all shapes ---" << std::endl;
    // 하나의 인터페이스(Shape::draw)로 여러 형태(Rectangle, Circle)의 객체를 다룸
    for (const auto& shape_ptr : shapes) {
        // shape_ptr은 Shape* 타입이지만, virtual 덕분에 실제 객체의 draw()가 호출됨
        shape_ptr->draw(); // 이것이 바로 동적 바인딩(런타임 다형성)
    }
    std::cout << "--------------------------" << std::endl;


    std::cout << "\n--- Deleting all shapes ---" << std::endl;
    // 할당된 메모리 해제
    for (const auto& shape_ptr : shapes) {
        delete shape_ptr; // 가상 소멸자 덕분에 각 객체 타입에 맞는 소멸자가 모두 호출됨
    }
    shapes.clear();
    std::cout << "---------------------------" << std::endl;

    return 0;
}