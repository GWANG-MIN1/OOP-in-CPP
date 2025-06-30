#include <stdio.h>
#include <stdlib.h> //malloc 쓰려면 반드시 선언 

typedef struct complex {
    double re, im;
    void (*printfun)(struct complex *);
} Complex;

void print_c(struct complex *a) {
    printf("%3.1lf + %3.1lf i\n", a->re, a->im);
}

int main() {
    Complex *cp;
    cp = (Complex *)malloc(sizeof(Complex));
    cp->printfun = print_c;
    cp->re = 1.1;   
    cp->im = 2.2;

    cp->printfun(cp);

    free(cp); 
    return 0;
}
