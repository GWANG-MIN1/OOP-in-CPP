#include <stdio.h>
#include <stdlib.h>
int main(){
        int *array;
        int index;
        int size;
        array = (int*)malloc(size*sizeof(int));
        printf("Size를 입력하세요: ");
        scanf("%d", &size);
        for(index = 0; index < size; index++){
                array[index] = index;
        }
        for(index = size-1; index >= 0; index--){
                printf("%d\n", array[index]);
        }
        return 0;
}