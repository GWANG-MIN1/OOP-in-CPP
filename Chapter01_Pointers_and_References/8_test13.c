#include <stdio.h>

void stringcopy(char *dest, const char *src) {
    for (; *src; src++, dest++) {
        *dest = *src;
    }
    *dest = '\0';  // 문자열 끝 표시
}

int main() {
    char array1[20];
    char array2[20];

    printf("문자열 입력: ");
    scanf("%19s", array1);  // 안전하게 입력 받기

    stringcopy(array2, array1);

    printf("복사된 문자열: %s\n", array2);

    // 콘솔 꺼짐 방지용
    printf("엔터를 누르면 종료됩니다...");
    getchar(); // 버퍼 정리용
    getchar(); // 진짜 대기

    return 0;
}

void stringcopy(char* dest, char*src){
     char *p = src;
     //printf("src = %u, dest = %u", src, dest);
     for(p; *p; p++){ //prnitf("p=%u\n",p);
         }
    p--;
    for(p;src != p ;  p--, dest++){
        *dest = *p;
        printf("p = %u, dest = %u", p, dest);
    }
    *(dest++) = *p;
    *(dest) = 0;
}
//챕터1 53페이지 