#include <iostream>

// 링크드 리스트의 기본 구성 요소인 노드 구조체
struct Node {
    int data;
    Node* next;

    // 생성자를 사용하면 노드 생성이 편리합니다.
    Node(int val) : data(val), next(nullptr) {}
};

// 링크드 리스트 클래스
class LinkedList {
private:
    Node* head; // 리스트의 시작을 가리키는 포인터

public:
    // 생성자: head를 nullptr로 초기화
    LinkedList() : head(nullptr) {}

    // 소멸자: 클래스 객체가 소멸될 때 모든 노드의 메모리를 자동으로 해제 (RAII)
    ~LinkedList() {
        std::cout << "Destroying LinkedList..." << std::endl;
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next; // 다음 노드를 임시 저장
            delete current;                 // 현재 노드 메모리 해제
            current = nextNode;             // 다음 노드로 이동
        }
        std::cout << "LinkedList destroyed. All nodes freed." << std::endl;
    }

    // 리스트 맨 앞에 새 노드를 추가하는 메서드
    void push_front(int data) {
        Node* newNode = new Node(data); // 1. 힙에 새 노드 동적 할당
        newNode->next = head;           // 2. 새 노드가 기존의 head를 가리키게 함
        head = newNode;                 // 3. head가 새 노드를 가리키도록 업데이트
    }

    // 리스트의 모든 노드 데이터를 출력하는 메서드
    void display() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList list;
    list.push_front(30);
    list.push_front(20);
    list.push_front(10);
    
    std::cout << "My Linked List: ";
    list.display(); // 출력: My Linked List: 10 -> 20 -> 30 -> nullptr
    
    // main 함수가 끝나면 list 객체가 범위를 벗어나므로 소멸자가 자동으로 호출됩니다.
    return 0;
}