# Chapter 8: 사례 연구, 상속

상속(Inheritance)은 객체 지향 프로그래밍의 핵심 기둥 중 하나로, 코드 재사용성을 높이고 클래스 간의 계층적 관계를 모델링하는 강력한 메커니즘입니다. 이 장에서는 상속의 기본 개념을 구체적인 사례를 통해 깊이 있게 살펴보고, C++에서 상속을 어떻게 구현하고 활용하는지 알아봅니다.

## 8.1 상속의 개념: "is-a" 관계

상속은 **"A는 B의 한 종류이다(A is-a B)"** 관계를 표현합니다. 예를 들어, "개는 동물이다", "사각형은 도형이다"와 같은 관계가 상속에 해당합니다.

-   **기본 클래스 (Base Class):** 부모 또는 슈퍼 클래스라고도 불리며, 공통된 속성과 기능을 물려주는 클래스입니다. (예: `Shape`, `Animal`)
-   **파생 클래스 (Derived Class):** 자식 또는 서브 클래스라고도 불리며, 기본 클래스로부터 속성과 기능을 물려받는 새로운 클래스입니다. (예: `Rectangle`, `Dog`)

파생 클래스는 기본 클래스의 멤버들을 상속받아 재사용하면서, 자신만의 고유한 멤버를 추가하여 기능을 확장하거나, 기본 클래스의 기능을 **재정의(override)**하여 다르게 동작하도록 만들 수 있습니다.

## 8.2 상속 구현하기: Shape 클래스 사례

다양한 도형을 표현하는 프로그램을 만든다고 가정해 봅시다. 모든 도형은 '위치'와 '색상'이라는 공통된 속성을 가질 수 있습니다. 이러한 공통 속성을 `Shape`라는 기본 클래스에 정의하고, 구체적인 도형 클래스들이 이를 상속받도록 설계할 수 있습니다.

### 접근 제어 지정자 (public, protected, private)

상속 관계에서 기본 클래스의 멤버에 대한 파생 클래스의 접근 권한은 접근 제어 지정자에 의해 결정됩니다.

-   `public`: 외부에서 접근 가능한 멤버입니다.
-   `protected`: 클래스 내부와 파생 클래스에서만 접근 가능한 멤버입니다. 외부에서는 접근할 수 없습니다.
-   `private`: 해당 클래스 내부에서만 접근 가능하며, 파생 클래스에서도 접근할 수 없습니다.

일반적으로 기본 클래스의 멤버 중 파생 클래스와 공유해야 할 멤버는 `protected`로, 외부에 공개할 인터페이스는 `public`으로 선언합니다.

### 상속과 생성자/소멸자 호출 순서

-   **생성자 호출 순서:** 기본 클래스 → 파생 클래스
-   **소멸자 호출 순서:** 파생 클래스 → 기본 클래스 (생성자 호출의 역순)

### 전체 코드 예제

```cpp
#include <iostream>
#include <string>

// 기본 클래스 (Base Class)
class Shape {
protected: // 파생 클래스에서 접근 가능하도록 protected로 선언
    int x, y;
    std::string color;
public:
    // 기본 클래스 생성자
    Shape(int x_coord, int y_coord, std::string c) : x(x_coord), y(y_coord), color(c) {
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
class Rectangle : public Shape {
private:
    int width, height;
public:
    // 파생 클래스 생성자
    Rectangle(int x, int y, std::string c, int w, int h) 
        : Shape(x, y, c), width(w), height(h) { // 기본 클래스의 생성자를 명시적으로 호출
        std::cout << "Rectangle constructor called." << std::endl;
    }

    // 파생 클래스 소멸자
    ~Rectangle() {
        std::cout << "Rectangle destructor called." << std::endl;
    }

    // 메서드 오버라이딩 (Method Overriding)
    void draw() const {
        std::cout << "Drawing a " << color << " rectangle of size " 
                  << width << "x" << height << " at (" << x << ", " << y << ")" << std::endl;
    }

    int getArea() const {
        return width * height;
    }
};

int main() {
    std::cout << "--- Creating Rectangle object ---" << std::endl;
    Rectangle rect(10, 20, "blue", 100, 50);
    
    std::cout << "\n--- Calling methods ---" << std::endl;
    rect.draw(); // Rectangle의 오버라이딩된 draw() 호출
    std::cout << "Area: " << rect.getArea() << std::endl;

    // 기본 클래스의 draw()를 명시적으로 호출
    rect.Shape::draw(); 

    std::cout << "\n--- Deleting Rectangle object ---" << std::endl;
    return 0;
}