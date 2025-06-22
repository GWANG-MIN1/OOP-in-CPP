#include <iostream>
#include <vector>
#include <string>
#include <stdexcept> // std::out_of_range 예외를 사용하기 위해

// 실제 프로젝트에서는 템플릿의 선언과 정의를 모두 헤더 파일(.hpp)에 넣는 것이 일반적입니다.
// 이 예제에서는 설명을 위해 하나의 파일에 모두 작성합니다.

//--- 클래스 템플릿 선언 ---
template <typename T>
class Stack {
private:
    std::vector<T> elems; // std::vector를 사용하여 내부 데이터 관리

public:
    void push(T const&);  // 스택에 요소 추가
    void pop();           // 스택에서 요소 제거
    T const& top() const; // 스택의 최상단 요소 반환
    bool empty() const {  // 스택이 비어있는지 확인
        return elems.empty();
    }
};

//--- 멤버 함수 외부 정의 ---
// 클래스 템플릿의 멤버 함수를 외부에서 정의할 때는 'template <typename T>'를 다시 붙여줘야 합니다.

template <typename T>
void Stack<T>::push(T const& elem) {
    elems.push_back(elem); // 벡터의 끝에 요소 추가
}

template <typename T>
void Stack<T>::pop() {
    if (elems.empty()) {
        // 비어있는 스택에서 pop을 시도하면 예외 발생
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back(); // 벡터의 마지막 요소 제거
}

template <typename T>
T const& Stack<T>::top() const {
    if (elems.empty()) {
        // 비어있는 스택에서 top을 시도하면 예외 발생
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elems.back(); // 벡터의 마지막 요소 반환
}


//--- 템플릿 사용 예제 (main 함수) ---
int main() {
    try {
        // int 타입을 사용하는 스택 생성
        Stack<int> intStack;
        std::cout << "Pushing integers: 10, 20" << std::endl;
        intStack.push(10);
        intStack.push(20);
        std::cout << "Top element is: " << intStack.top() << std::endl;
        intStack.pop();
        std::cout << "Top element after pop is: " << intStack.top() << std::endl;

        std::cout << "\n---------------------------\n" << std::endl;

        // std::string 타입을 사용하는 스택 생성
        Stack<std::string> stringStack;
        std::cout << "Pushing strings: \"Hello\", \"World\"" << std::endl;
        stringStack.push("Hello");
        stringStack.push("World");
        std::cout << "Top element is: " << stringStack.top() << std::endl;
        stringStack.pop();
        std::cout << "Top element after pop is: " << stringStack.top() << std::endl;
        stringStack.pop();

        std::cout << "\n---------------------------\n" << std::endl;
        
        // 비어있는 스택에서 예외 처리 테스트
        std::cout << "Trying to pop from empty string stack..." << std::endl;
        stringStack.pop(); // 이 라인에서 예외가 발생해야 함

    } catch (std::exception const& ex) {
        // 발생한 예외를 잡아 메시지 출력
        std::cerr << "Exception: " << ex.what() << std::endl;
        return 1; // 오류를 나타내며 프로그램 종료
    }

    return 0;
}