#include <math.h>
#include <stdio.h>
#define PI 3.142

void draw_graph(double (*fun)(double), double from, double to) {
    double x;
    int i;
    printf("+----------+----------+\n");
    from = from * PI / 180;
    to = to * PI / 180;
    for (x = from; x <= to; x += 0.2) {
        int position;
        double y;
        y = fun(x);
        position = (int)(20.0 * y + 21.5);
        for (i = 0; i < 42; i++) {
            if (i == position) putchar('*');
            else if (i == 21)  putchar('|');
            else putchar(' ');
        }
        putchar('\n'); 
    }
}

int main() {
    printf("sin 함수그래프입니다.\n");
    draw_graph(sin, 0, 360);
    printf("cos함수그래프입니다.\n");
    draw_graph(cos, 0, 360);
}