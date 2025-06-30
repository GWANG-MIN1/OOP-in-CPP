#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mystring {
    char *p;
    void (*show)(struct mystring *s);
} mystring;

void print(mystring *s) {
    if(s -> p == 0)
        printf("String is not initialized. \n");
    else 
        printf("%s\n",s -> p);//스트링을 printf로 출력 
}
mystring *new_string (char *s) {
    mystring *temp;
    temp = (mystring*)malloc(sizeof(mystring));//메모리 할당
    temp -> p = strdup(s); //스트링을 초기화 
    temp -> show = print;//함수 포인터 할당 
    return temp;//반환
}

int main() {
    mystring *str;
    str = new_string("Hello");
    str -> show(str);
    free(str);
    free(str -> p);
    return 0;
}