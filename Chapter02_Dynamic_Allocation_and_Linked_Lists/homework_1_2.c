#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>  

int main() {
    char buf[80];        // 2. 임시로 사용할 버퍼
    char *strptr[3];     // 1. 3개의 문자열 포인터 배열
    int i;

    // --- 1, 2번 조건: 3개의 스트링을 buffer를 거쳐 동적 메모리에 저장 ---
    printf("세 개의 이름을 한 줄에 하나씩 입력하세요.\n");
    for (i = 0; i < 3; i++) {
        // 버퍼 오버플로우를 방지하기 위해 최대 79글자만 받도록 수정
        scanf("%79s", buf);
        
        // 입력받은 문자열 길이만큼 메모리 할당 (+1은 널 문자 공간)
        strptr[i] = (char *)malloc(strlen(buf) + 1);
        if (strptr[i] == NULL) { // 메모리 할당 실패 확인
            printf("메모리 할당 오류!");
            // 이전에 할당된 메모리가 있다면 해제
            for (int j = 0; j < i; j++) {
                free(strptr[j]);
            }
            return 1;
        }

        // buffer의 내용을 동적 메모리 공간으로 복사
        strcpy(strptr[i], buf);
    }

    printf("\n--- 입력받은 이름을 역순으로 출력 ---\n");
    // --- 3번 조건: 포인터 배열을 이용해 역순으로 출력 ---
    // 루프를 2부터 0까지 감소시키며 실행
    for (i = 2; i >= 0; i--) {
        printf("%s\n", strptr[i]);
    }
    
    // --- 좋은 습관: 할당받았던 메모리 해제하기 ---
    for (i = 0; i < 3; i++) {
        free(strptr[i]);
    }

    return 0;
}