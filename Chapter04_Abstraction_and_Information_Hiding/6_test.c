#include <stdio.h>
#include <stdlib.h>

typedef struct complex {
    double re, im; 
    void (*f)(struct complex*); //함수 포인터 변수 선언 
}Complex;

void print_c(Complex *p) {
    printf("%3.1lf + %3.1lfi", p -> re, p -> im);
}


Complex * new_complex (double r, double i) {
    Complex* t;
    t = (Complex *)malloc(sizeof(Complex));//메모리 할당 
    t -> re = r; t -> im = i;//r, i  값 초기화 
    t -> f =  print_c;//함수 포인터 변수에 함수 할당 
    return t;
}



int main(){
    Complex *c;
    c = new_complex(1.1 , 2.2);
    c -> f(c);
    return 0;
}