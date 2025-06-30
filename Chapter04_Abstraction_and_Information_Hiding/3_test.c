#include <stdio.h>

typedef struct complex {
    double re,im;
    void (*f)(struct complex);
} Complex;

void print_c (Complex a) {
    printf("%.2lf + %.2lf i ", a.re,a.im);
}

int main(){
    Complex x = {1.1, 2.2}, y = {3.3, 4.4};
    Complex *p ;
    p = &x;
    p -> f = print_c;
    p -> f(x);
    return 0;
}