#include <stdio.h>
#include <stdlib.h> 
#include <stddef.h> 

struct item {
    int data; // main 함수에서 data 변수를 사용하므로 통일성을 위해 data로 변경
    struct item *next;
};

// append 함수는 리스트의 맨 뒤에 붙이는 함수
void append(struct item **ppS, int num) {
    // 1. 새로운 노드를 만들고 데이터 저장
    struct item *pNew = (struct item*)malloc(sizeof(struct item));
    if (pNew == NULL) {
        printf("메모리 할당 오류\n");
        return;
    }
    pNew->data = num;
    pNew->next = NULL; // 새 노드는 마지막에 붙을 것이므로 next는 항상 NULL

    // 2. 리스트가 비어있는 경우 (맨 처음 추가하는 경우)
    if (*ppS == NULL) {
        *ppS = pNew; // 리스트의 시작을 새 노드로 지정
        return;
    }

    // 3. 리스트가 비어있지 않은 경우, 맨 마지막 노드를 찾아서 연결
    struct item *pTemp = *ppS;
    while (pTemp->next != NULL) {
        pTemp = pTemp->next; // 다음 노드가 없을 때까지 계속 이동
    }
    
    // while문이 끝나면 pTemp는 마지막 노드를 가리킴
    pTemp->next = pNew; // 마지막 노드의 next에 새 노드를 연결
}

// del_end 함수는 리스트의 맨 뒤에 있는 항목을 삭제하는 함수
void del_end(struct item **ppS) {
    // 1. 리스트가 비어있는 경우
    if (*ppS == NULL) {
        printf("삭제할 항목이 없습니다.\n");
        return;
    }
    
    // 2. 리스트에 항목이 하나만 있는 경우
    if ((*ppS)->next == NULL) {
        free(*ppS);      // 하나 있는 노드를 해제
        *ppS = NULL;     // 리스트를 비어있는 상태로 만듦
        return;
    }

    // 3. 리스트에 항목이 두 개 이상 있는 경우, 마지막 노드와 그 바로 앞 노드를 찾아야 함
    struct item *pPrev = NULL;   // 마지막 노드의 바로 앞 노드를 가리킬 포인터
    struct item *pCurr = *ppS; // 현재 노드를 가리킬 포인터
    
    while (pCurr->next != NULL) {
        pPrev = pCurr;           // pCurr을 pPrev에 저장해두고
        pCurr = pCurr->next;     // pCurr은 다음 칸으로 이동
    }

    // while문이 끝나면 pCurr은 마지막 노드, pPrev는 마지막의 바로 앞 노드를 가리킴
    pPrev->next = NULL; // 바로 앞 노드를 이제 마지막 노드로 만듦
    free(pCurr);        // 원래 마지막이었던 노드의 메모리 해제
}

// print_all 함수는 리스트의 끝까지 각 항목을 방문하며 항목의 값을 인쇄하는 함수
void print_all(struct item *p) {
    printf("현재 리스트: ");
    // p가 NULL이 아닐 동안(리스트의 끝에 도달할 때까지) 루프 실행
    for ( ; p != NULL ; p = p->next) {
        printf("%d --> ", p->data);
    }
    printf("END\n");
}
  
int main() {
    struct item *pStart = NULL; // 0 대신 NULL 사용 권장
    int data;

    printf("숫자를 입력하세요 (종료: Ctrl+D on Linux, Ctrl+Z on Windows):\n");
    // scanf의 반환값이 1이면 (성공적으로 숫자 하나를 읽었으면) 루프 계속
    while (scanf("%d", &data) == 1) {
        append(&pStart, data);
    }

    // --- 제공된 테스트 코드 ---
    print_all(pStart);
    del_end(&pStart);
    print_all(pStart);

    return 0;
}