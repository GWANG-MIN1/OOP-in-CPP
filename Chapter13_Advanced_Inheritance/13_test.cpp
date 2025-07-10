#include <iostream>
using namespace std;

// 단일 연결 리스트 노드 클래스
class Link {
public:
    Link() {}
private:
    int m_data;
    Link* next;

    friend class List;  // List 클래스가 private 멤버 접근 가능하도록 허용
};

// 리스트 클래스
class List {
public:
    List() : m_first(0) {}

    // 특정 값을 찾는 함수 (있으면 true)
    bool find(int n) {
        Link* p;
        for (p = m_first; p; p = p->next) {
            if (p->m_data == n) return true;
        }
        return false;
    }

    // 리스트 맨 앞에 삽입
    void insert(int data) {
        Link* t = new Link();
        t->next = m_first;
        t->m_data = data;
        m_first = t;
    }

    // 전체 출력
    void printall() {
        Link* p;
        cout << "START: ";
        for (p = m_first; p; p = p->next) {
            cout << p->m_data << " --> ";
        }
        cout << "END" << endl;
    }

private:
    Link* m_first;
};

// Set 클래스: List 상속, 중복 허용 X
class Set : public List {
public:
    void insert(int data) {
        if (!find(data)) {
            List::insert(data);  // 중복이 아닐 때만 삽입
        }
    }
};

// 테스트 메인 함수
int main() {
    List l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(2);
    l.printall();  // 중복 허용

    Set s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(2);   // 중복 무시
    s.printall();  // 중복 제거 출력
}

