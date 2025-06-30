#include <stdio.h>
#include <stdlib.h>

typedef struct shape {
    float width, height;
    float (*area)(struct shape *);
} shape;


float rect_area(struct shape *s) {
    return s->width * s->height; 
}


float tri_area(struct shape *s) {
    return 0.5 * s->width * s->height; 
}


shape* new_rectangle(float w, float h) {
    shape* r = (shape*)malloc(sizeof(shape));
    r->width = w;
    r->height = h;
    r->area = rect_area;
    return r;
}

shape* new_triangle(float w, float h) {
    shape* t = (shape*)malloc(sizeof(shape));
    t->width = w;
    t->height = h;
    t->area = tri_area;
    return t;
}


int main() {
    // 사각형과 삼각형 객체 생성
    shape* rectangle = new_rectangle(5, 6);
    shape* triangle = new_triangle(5, 6);

    // 면적 계산 및 출력
    printf("사각형의 넓이 : %.2f\n", rectangle->area(rectangle));
    printf("삼각형의 넓이 : %.2f\n", triangle->area(triangle));

    // 동적 할당 메모리 해제
    free(rectangle);
    free(triangle);

    return 0;
}