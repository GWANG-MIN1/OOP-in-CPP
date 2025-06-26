#include <stdio.h>
#include <stdlib.h> 


struct item {
    int score;
    struct item *next;
};


void insert(struct item **ppStack, int n) {
    
    struct item *pAlloc = (struct item*)malloc(sizeof(struct item));
    if (pAlloc == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        exit(1); 
    }
    pAlloc->score = n;          
    pAlloc->next = *ppStack;    
    *ppStack = pAlloc;          
}


void print_stack(struct item *pS) {
    printf("TOP: ");
    
    for ( ; pS ; pS = pS->next) {
        printf("%d-->", pS->score);
    }
    printf("END\n");
}


int main() {
    struct item *pStack = 0; 

    insert(&pStack, 1);
    insert(&pStack, 2);
    insert(&pStack, 3);

    print_stack(pStack); 

    
    struct item *pCurrent = pStack;
    struct item *pNext;
    while (pCurrent != 0) {
        pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }
    
    return 0;
}
