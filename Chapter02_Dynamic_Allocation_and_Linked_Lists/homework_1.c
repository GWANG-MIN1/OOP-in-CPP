#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    // 1. name_a 와 name_b 포인터 선언
    char *name_a, *name_b;
    // 2. 입력을 임시로 받을 정적 배열 buffer 선언
    char buffer[20];

    // --- 첫 번째 이름(name_a) 처리 ---
    printf("첫 번째 이름을 입력하세요 : ");
    scanf("%s", buffer);  //2. scanf를 통해 buffer에 이름 읽기

    // 3. buffer에 저장된 이름의 길이에 딱 맞게 동적 메모리 할당
    //    (+1은 문자열의 끝을 알리는 널 문자 '\0'를 위한 공간)

    name_a = (char*)malloc(strlen(buffer) + 1);
    if(name_a == NULL){  // 메모리 할당에 실패했는지 확인
        printf("메모리 할당 오류!");
        return 1;
    }
    // 3. buffer의 내용을 name_a로 복사
    strcpy(name_a, buffer);

    // --- 두 번째 이름(name_b) 처리 (4. name_a와 동일한 방식) ---
    printf("두 번째 이름을 입력하세요 : ");
    scanf("%s", buffer);

    name_b = (char *)malloc(strlen(buffer)+1);
    if(name_b == NULL){
        printf("메모리 할당 오류!");
        free(name_a); // 이미 할당된 메모리는 해제해줘야 함
        return 1;
    }
    strcpy(name_b, buffer);

     //두 이름 출력 테스트 ---

    printf("\n입력된 이름은 다음과 같습니다.\n");
    printf("첫 번째 이름: %s\n", name_a);
    printf("두 번째 이름: %s\n", name_b);

    //동적으로 할당받은 메모리는 반드시 해제해줘야 합니다.
    free(name_a);
    free(name_b);
    return 0;


}
