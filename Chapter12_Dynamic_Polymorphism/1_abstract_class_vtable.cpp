#include <iostream>
#include <vector>

// 추상 클래스 (Abstract Class)
// 하나 이상의 순수 가상 함수를 포함합니다.
class Shape {
public:
    // 순수 가상 함수 (Pure Virtual Function)
    // 파생 클래스는 이 함수를 반드시 구현(오버라이딩)해야 합니다.
    virtual double getArea() const = 0; 

    // 일반 가상 함수 (Virtual Function)
    // 기본 구현을 제공할 수 있으며, 파생 클래스에서 선택적으로 오버라이딩할 수 있습니다.
    virtual void draw() const {
        std::cout << "Drawing a generic shape." << std::endl;
    }

    // 가상 소멸자 (Virtual Destructor)
    // 다형적 소멸을 위해 기반 클래스의 소멸자는 반드시 virtual이어야 합니다.
    virtual ~Shape() {}
};

// 파생 클래스 1
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    // 기반 클래스의 순수 가상 함수를 반드시 오버라이딩
    double getArea() const override {
        return 3.14159 * radius * radius;
    }

    // 기반 클래스의 일반 가상 함수를 선택적으로 오버라이딩
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

// 파생 클래스 2
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // 기반 클래스의 순수 가상 함수를 반드시 오버라이딩
    double getArea() const override {
        return width * height;
    }

    // 이 클래스는 draw()를 오버라이딩하지 않음.
    // 따라서 draw() 호출 시 기반 클래스(Shape)의 draw()가 실행됨.
};


int main() {
    // Shape myShape; // 컴파일 오류! 추상 클래스는 객체화할 수 없음.

    // 추상 클래스의 포인터는 파생 클래스 객체를 가리킬 수 있음.
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(10));
    shapes.push_back(new Rectangle(5, 4));

    for (const auto& shape : shapes) {
        // 동적 바인딩: shape이 실제로 가리키는 객체의 draw()가 호출됨
        shape->draw(); 
        
        // 동적 바인딩: shape이 실제로 가리키는 객체의 getArea()가 호출됨
        std::cout << "Area: " << shape->getArea() << std::endl;
        std::cout << "----------" << std::endl;
    }

    // 메모리 해제
    for (const auto& shape : shapes) {
        delete shape;
    }
    shapes.clear();

    return 0;
}