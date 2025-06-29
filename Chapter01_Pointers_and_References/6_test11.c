#include <stdio.h>

void rswap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 0, b = 0;
    printf("a와 b의 값을 입력하시오: ");
    scanf("%d %d", &a, &b);
    
    rswap(&a, &b);  // 주소를 넘김

    printf("%d %d\n", a, b);
    return 0;
}
