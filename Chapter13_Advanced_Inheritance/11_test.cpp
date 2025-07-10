#include <iostream>
using namespace std;

class Link{
public:
    Link(){}
//private:
    int m_data;
    Link *next;
};
class Stack {
public:
    Stack() : m_first(0) {}
    void push(int data) {
        Link *t = new Link();
        t -> next = m_first;
        t -> m_data = data;
        m_first = t;
    }
    void printall() {
        Link *p;
        cout << "START:";
        for(p=m_first; p; p= p -> next) {
            cout << p -> m_data << "-->" ;
        }
        cout << "END" << endl;
    }
private:
    Link * m_first;
};

int main() {
    Stack I;
    I.push(1); 
    I.push(2); 
    I.push(3);
    I.printall(); 
}