#include <stdio.h>
struct item {
int score;
struct item *next;
};
int main(){
    struct item A,B,C,D;
    struct item *pFirst;
    struct item *p;
    A.score = 1; B.score = 2; C.score = 3; D.score = 4;
    pFirst = &A; A.next = &B; B.next = &C; C.next = &D; D.next = 0;
    p = pFirst;
    printf("%d--> ", p -> score);
    p = p ->next;
    printf("%d--> ", p -> score);
    p = p ->next;
    printf("%d--> ", p -> score);
    p = p ->next;
    printf("%d--> ", p -> score);
    
    printf("END\n");
    return 0;
}