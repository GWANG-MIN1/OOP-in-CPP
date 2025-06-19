// 📄 1_abstraction_shape.cpp

#define _USE_MATH_DEFINES // M_PI 상수를 사용하기 위해 추가
#include <cmath>          // M_PI 와 같은 수학 상수를 사용하기 위해 포함
#include <iostream>

// 추상 클래스 Shape
class Shape {
public:
    virtual void draw() const = 0;
    virtual double getArea() const = 0;
    virtual ~Shape() {
        std::cout << "Shape destructor called." << std::endl;
    }
};

// 파생 클래스 Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    ~Circle() {
        std::cout << "Circle destructor called." << std::endl;
    }

    void draw() const override {
        std::cout << "Drawing a circle with radius " << radius << "." << std::endl;
    }
    // M_PI를 이제 정상적으로 사용할 수 있습니다.
    double getArea() const override {
        return M_PI * radius * radius;
    }
};

// 파생 클래스 Square
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    ~Square() {
        std::cout << "Square destructor called." << std::endl;
    }

    void draw() const override {
        std::cout << "Drawing a square with side " << side << "." << std::endl;
    }
    double getArea() const override {
        return side * side;
    }
};

int main() {
    Shape* pShape1 = new Circle(10.0);
    Shape* pShape2 = new Square(5.0);

    pShape1->draw();
    std::cout << "Area of circle: " << pShape1->getArea() << std::endl;
    std::cout << std::endl;

    pShape2->draw();
    std::cout << "Area of square: " << pShape2->getArea() << std::endl;
    std::cout << std::endl;
    
    delete pShape1;
    delete pShape2;

    return 0;
}