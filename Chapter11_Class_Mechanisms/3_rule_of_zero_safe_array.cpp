#include <iostream>
#include <vector> // C++ 표준 라이브러리 컨테이너 사용
#include <algorithm>

// "0의 법칙"을 따르는 클래스
// 자원 관리를 std::vector에 위임했기 때문에,
// 소멸자, 복사 생성자, 복사 대입 연산자를 직접 작성할 필요가 없음
class SafeArray {
private:
    std::vector<int> data;

public:
    SafeArray(size_t s) : data(s) { // std::vector가 알아서 메모리 관리
        std::cout << "Constructor: SafeArray with " << s << " integers created." << std::endl;
    }

    // 소멸자? -> 필요 없음! std::vector가 자동으로 처리.
    // 복사 생성자? -> 필요 없음! std::vector가 자동으로 처리.
    // 복사 대입 연산자? -> 필요 없음! std::vector가 자동으로 처리.
    // 이동 연산자들? -> 필요 없음! std::vector가 자동으로 처리.
};

int main() {
    std::cout << "--- Creating arr1 ---" << std::endl;
    SafeArray arr1(5);

    std::cout << "\n--- Creating arr2 from arr1 ---" << std::endl;
    SafeArray arr2 = arr1; // 컴파일러가 생성한 기본 복사 생성자가 호출되지만,
                           // 내부의 std::vector가 안전하게 깊은 복사를 수행함.

    std::cout << "\n--- End of main ---" << std::endl;
    // main 함수가 끝나도 우리가 할 일은 없음. 모든 자원 관리는 std::vector가 책임짐.
    return 0;
}