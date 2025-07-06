#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#define N 5  // 등호 제거

using namespace std;

class Student {
public:
    Student() {
        strcpy(name, "NONE");
        kor = 0; eng = 0; math = 0;
        tot = 0; avg = 0.0;
    }

    Student(const char* na, int k, int e, int m) {
        strcpy(name, na);
        kor = k;
        eng = e;
        math = m;
        tot = 0;
        avg = 0.0;
    }

    int get_kor() { return kor; }
    int get_eng() { return eng; }
    int get_math() { return math; }
    int get_tot() { return tot; }
    double get_avg() { return avg; }

    void Compute_Total() {
        tot = kor + eng + math;
    }

    void Compute_Average() {
        avg = tot / 3.0;
    }

    void showStudent() {
        cout << name << "\t총점: " << tot << "\t평균: " << avg << endl;
    }

private:
    char name[15];
    int kor, eng, math;
    int tot;
    double avg;
};

int main() {
    Student stu[N] = {
        Student("Kim", 80, 90, 85),
        Student("Park", 75, 80, 78),
        Student("Lee", 90, 85, 88),
        Student("Hong", 60, 70, 65),
        Student("Oh", 88, 92, 91)
    };

    for (int i = 0; i < N; i++) {
        stu[i].Compute_Total();
        stu[i].Compute_Average();
    }

    for (int i = 0; i < N; i++) {
        stu[i].showStudent();
    }

    return 0;
}
