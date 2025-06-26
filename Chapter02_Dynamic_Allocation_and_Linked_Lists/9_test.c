#include <stdio.h>
#include <stdlib.h>

struct item{
    int score;
    struct item *next;
};
struct item *pStack;

void insert(int n){
    struct item *pAlloc;
    pAlloc = (struct item*)malloc(sizeof(struct item));
    pAlloc -> score = n;
    pAlloc -> next = pStack;
    pStack = pAlloc;
}

void pop(){
    struct item *pFree;
    pFree = pStack;
    pStack = pStack -> next;
    free(pFree); 

}

int top(){
    return pStack -> score; 

}

int main(){
    pStack = 0;

    insert(1);
    insert(2);
    insert(3);
    printf("%d\n",top());
    pop();
    printf("%d\n",top());
    pop();
    printf("%d\n",top());
    

    return 0;
}