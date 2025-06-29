#include <stdio.h>

int isOdd(int value)
{
    if(value % 2 == 1)
        return 1;
    return 0;
}

int isEven(int value)
{
    if(value % 2 == 0)
        return 1;
    return 0;
}

void showif(int *arr, int size, int(*Pred)(int))
{
    int i;
    for(i=0; i<size; i++)
        if(Pred(arr[i]))
            printf("%d", arr[i]);
    puts(" ");
}

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    showif(a,10,isOdd);
    showif(a,10,isEven);
    return 0;
}