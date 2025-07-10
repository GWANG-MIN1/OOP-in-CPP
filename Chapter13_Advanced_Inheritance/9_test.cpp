    #include <iostream>
    using namespace std;

    class A {
    public:
        int a;
        A() {a = 1;}
        class B {
        public: 
            int b; 
            B() {b=3;}
        };
    };

    class C : public A {
    public:
        void show() {
            B d;
            cout << d.b << endl;
        }
    };

    int main() {
        C cc;
        cc.show();
    }


    