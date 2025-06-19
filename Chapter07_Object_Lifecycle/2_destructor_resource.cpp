#include <iostream>

class ResourceManager {
private:
    int* data;

public:
    // 생성자: 객체 생성 시 자원을 할당 (메모리)
    ResourceManager() {
        data = new int[10];
        std::cout << "Resource acquired (Memory allocated)." << std::endl;
    }

    // 소멸자: 객체 소멸 시 자원을 해제
    // 이 클래스는 RAII 패턴을 따릅니다.
    ~ResourceManager() {
        delete[] data;
        data = nullptr; // 안전을 위한 조치
        std::cout << "Resource released (Memory deallocated)." << std::endl;
    }
};

void useResource() {
    std::cout << "Entering useResource function..." << std::endl;
    ResourceManager local_res; // 함수 내 지역 객체 생성 -> 생성자 호출
    std::cout << "Resource is being used." << std::endl;
    std::cout << "Exiting useResource function..." << std::endl;
    // 함수가 끝나면 local_res가 범위를 벗어나므로 소멸자가 자동으로 호출됨
}

int main() {
    useResource();
    return 0;
}