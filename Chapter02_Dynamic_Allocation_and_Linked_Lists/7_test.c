#include <stdio.h>

int main()
{
    int score[8] = {55, 22, 11, 66, 33, 88, 44, 77};
    int next[8] = {3, 4, 1, 7, 6, -1, 0, 5};
    int start = 2;
    int i;

    printf("출력 결과: ");
    for(i = start; i != -1; i = next[i]) {
        // 1. 숫자 뒤에 공백을 추가하여 결과를 보기 쉽게 만듭니다.
        printf("%d ", score[i]); 
    }
    printf("\n"); // 마지막에 줄바꿈을 추가합니다.

    // 2. 프로그램이 바로 종료되지 않도록 사용자의 키 입력을 기다립니다.
    printf("\n프로그램을 종료하려면 아무 키나 누르세요...");

    return 0;
}