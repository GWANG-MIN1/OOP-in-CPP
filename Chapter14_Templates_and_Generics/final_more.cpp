#include <iostream> 
#include <string>   
using namespace std;

// 문제 1: 클래스 계층 설계 (템플릿 및 가상 상속)
// =================================================================

class Student {
protected:
    int num;          
    string name;      

public:
    // 생성자: 학번과 이름을 받아 초기화
    Student(int n, const string& s) : num(n), name(s) {}
    
    // 가상 소멸자: 파생 클래스의 객체가 소멸될 때 올바른 소멸자 호출을 보장
    virtual ~Student() {}

    // 외부(어댑터)에서 이름에 접근하기 위한 public 메서드
    string getName() const {
        return name;
    }
};

template <typename T>
class Lscore : public virtual Student { 
protected:
    T kor;  
    T eng;  

public:
    Lscore(int n, const string& s, T k, T e) : Student(n, s), kor(k), eng(e) {}
};

template <typename T>
class Nscore : public virtual Student { 
protected:
    T math; 
    T sci;  

public:
    Nscore(int n, const string& s, T m, T sc) : Student(n, s), math(m), sci(sc) {}
};

template <typename T>
class Totscore : public Lscore<T>, public Nscore<T> {
public:
    
    Totscore(int n, const string& s, T k, T e, T m, T sc)
        : Student(n, s), Lscore<T>(n, s, k, e), Nscore<T>(n, s, m, sc) {}

    // 문제 2-1: '+' 연산자 오버로딩 (멤버 함수)
    // 각 과목 점수에 k점을 더한 새로운 Totscore 객체를 반환
    Totscore<T> operator+(int k) const {
        return Totscore<T>(
            this->num, 
            this->name, 
            this->kor + k, 
            this->eng + k, 
            this->math + k, 
            this->sci + k
        );
    }

    // 어댑터 패턴에서 사용할 평균 점수 계산 메서드
    double getAverage() const {
        return (this->kor + this->eng + this->math + this->sci) / 4.0;
    }

    // 문제 2-2: '<<' 연산자 오버로딩을 위해 friend 선언
    // 외부 함수인 operator<<가 이 클래스의 protected 멤버에 접근할 수 있도록 허용
    template <typename U>
    friend ostream& operator<<(ostream& os, const Totscore<U>& st);
};

// 문제 2-2: '<<' 연산자 오버로딩 (friend 함수) 구현
template <typename U>
ostream& operator<<(ostream& os, const Totscore<U>& st) {
    os << "[학번: " << st.num << "] 이름: " << st.name << endl;
    os << "  - 국어: " << st.kor << ", 영어: " << st.eng 
       << ", 수학: " << st.math << ", 과학: " << st.sci;
    return os;
}


// 문제 3: 어댑터 패턴 적용
// =================================================================


class LegacyReporter {
public:
    void printReport(const string& data) const {
        cout << "\n--- Legacy System Report ---\n";
        cout << "  Data: " << data << "\n";
        cout << "--------------------------\n";
    }
};


template <typename T>
class StudentAdapter {
private:
    const Totscore<T>& student; // Totscore 객체에 대한 참조 (변환 대상)

public:
    // 생성자: 변환할 Totscore 객체를 참조로 받음
    StudentAdapter(const Totscore<T>& st) : student(st) {}

    // Totscore 정보를 특정 형식의 문자열로 변환하는 핵심 메서드
    string getReportString() const {
        // student 객체의 public 메서드를 호출하여 정보 가공
        string report_data = "[" + student.getName() + "] / Average: " + to_string(student.getAverage());
        return report_data;
    }
};


// 문제 4: main 함수 구현
// =================================================================

int main() {
    // 1. 상수 MAX 정의
    const int MAX = 5;

    // 2. Totscore<int> 타입의 객체 배열 선언 및 초기화
    Totscore<int> st[MAX] = {
        Totscore<int>(101, "Kim",  85, 90, 80, 77),
        Totscore<int>(102, "Lee",  90, 95, 89, 89),
        Totscore<int>(103, "Park", 80, 70, 70, 55),
        Totscore<int>(104, "Hong", 75, 80, 90, 85),
        Totscore<int>(105, "Kang", 85, 90, 85, 85)
    };

    // 3. 점수 변경 전 학생 정보 출력
    cout << "===== 초기 학생 정보 =====" << endl;
    for (int i = 0; i < MAX; ++i) {
        cout << st[i] << endl; // 오버로딩된 '<<' 연산자 사용
    }
    cout << "===========================\n" << endl;


    // 4. 모든 학생의 과목 점수를 5점씩 증가
    cout << "===== 모든 학생의 점수를 5점씩 올립니다... =====" << endl;
    for (int i = 0; i < MAX; ++i) {
        st[i] = st[i] + 5; // 오버로딩된 '+' 연산자 사용
    }

    // 5. 점수 변경 후 학생 정보 출력
    cout << "\n===== 5점 증가 후 학생 정보 =====" << endl;
    for (int i = 0; i < MAX; ++i) {
        cout << st[i] << endl;
    }
    cout << "===============================" << endl;


    // 6 & 7. 어댑터 패턴을 사용하여 레거시 시스템으로 리포트 출력
    cout << "\n===== 어댑터 패턴을 이용한 레거시 리포트 출력 =====" << endl;
    LegacyReporter legacy_reporter;          // 레거시 시스템 객체 생성
    StudentAdapter<int> adapter(st[0]);      // 첫 번째 학생(Kim)에 대한 어댑터 생성
    
    // 어댑터를 통해 얻은 문자열로 레거시 리포트 출력
    legacy_reporter.printReport(adapter.getReportString());

    return 0; // 프로그램 정상 종료
} 