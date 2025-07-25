# Chapter 12: 동적 다형성의 동작 원리 (핵심 요약)

이 장에서는 C++가 `virtual` 함수를 통해 어떻게 런타임 다형성을 구현하는지, 그 내부 동작 원리를 알아봅니다.

---

## 1. 바인딩: 호출과 구현의 연결

-   **정적 바인딩 (Static Binding):** **컴파일 시**에 호출할 함수가 결정됩니다.
    -   `virtual`이 아닌 일반 함수에 해당합니다.
    -   포인터의 **선언된 타입**을 따릅니다. (예: `Shape*` 포인터는 `Shape`의 함수를 호출)

-   **동적 바인딩 (Dynamic Binding):** **실행 시**에 호출할 함수가 결정됩니다.
    -   `virtual` 함수에 해당합니다.
    -   포인터가 **실제로 가리키는 객체**의 타입을 따릅니다. (예: `Shape*` 포인터가 `Circle` 객체를 가리키면 `Circle`의 함수를 호출)

## 2. 다형성을 위한 핵심 도구

-   **`virtual` 키워드:** 부모 클래스 함수에 붙여 "이 함수는 동적 바인딩을 사용하겠다"고 선언하는 **핵심 스위치**입니다.

-   **`override` 키워드 (C++11):** 자식 클래스 함수에 붙여 "나는 부모의 가상 함수를 재정의(오버라이딩)하는 것이 맞다"고 명시합니다. 의도와 다를 경우 컴파일러가 에러를 발생시켜주는 **안전장치**입니다.

-   **가상 소멸자 (`virtual ~Base()`):** 부모 클래스의 포인터로 자식 객체를 `delete` 할 때, 자식의 소멸자까지 모두 호출되도록 보장합니다. 메모리 누수를 막기 위해 상속을 사용한다면 **반드시 필요**합니다.

## 3. 어떻게 동작하는가? (vtable과 vptr)

동적 바인딩은 마법이 아니라, 정해진 메커니즘을 따릅니다.

1.  **vtable (가상 함수 테이블):** `virtual` 함수를 가진 클래스는, 어떤 함수가 어느 메모리 주소에 있는지 기록된 **'가상 함수 주소록'**을 갖습니다.
2.  **vptr (가상 포인터):** 해당 클래스의 모든 객체는, 자신 클래스의 `vtable`을 가리키는 **숨겨진 포인터(`vptr`)**를 내부에 갖게 됩니다.
3.  **호출 과정:** `객체 포인터` → `vptr` → `vtable` → `실제 함수 주소` 순서로 찾아가서 최종 함수를 호출합니다.

## 4. 추상 클래스: "인터페이스"의 강제

-   **순수 가상 함수 (Pure Virtual Function):** `virtual void func() = 0;` 처럼, 구현부가 없는 함수입니다. "구현은 자식들이 알아서 해라"는 의미입니다.
-   **추상 클래스 (Abstract Class):** 순수 가상 함수를 하나 이상 가진 클래스입니다.

#### 추상 클래스의 핵심 규칙

-   🚫 **규칙 1:** 추상 클래스는 **객체를 직접 생성할 수 없습니다.** (`Shape s;` -> 에러)
-   ✅ **규칙 2:** 자식 클래스는 부모의 **모든 순수 가상 함수를 반드시 구현(오버라이딩)**해야만 객체를 생성할 수 있습니다.

➡️ **결론:** 추상 클래스는 자식들에게 "이 기능들은 반드시 만들어야 해!"라고 강제하는 **인터페이스(계약서)** 역할을 합니다.