#include <iostream>
using namespace std;

// 함수 템플릿
template <typename T>
T maxi(T x, T y) {
    return (x > y) ? x : y;
}

// double에 대한 오버로드 (생략 가능, 템플릿이 처리 가능함)
double maxi(double x, double y) {
    return (x > y) ? x : y;
}

int main() {
    double a = 1.5, b = 2.5;
    int i = 1, j = 2;

    cout << "둘 중 큰 수는: " << maxi(a, b) << endl;  // double용 호출
    cout << "둘 중 큰 수는: " << maxi(i, j) << endl;  // 템플릿 호출
}
