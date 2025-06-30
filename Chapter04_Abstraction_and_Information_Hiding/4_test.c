#include <stdio.h>
typedef struct function_pointer {
    int n;
    void(*f)(int n);
}Fp;
void print(int n)
{
    printf("Function Pointer Test %d\n",n);
}

int main()
{
    Fp a;
    Fp *p;
    p = &a;
    p ->f = print;
    p -> f(3);
    return 0;
}