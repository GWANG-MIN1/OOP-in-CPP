#include <stdio.h>
#include <stdlib.h>
int main(){
    double *pDegree = 0;
    pDegree = (double*)malloc(sizeof(double)); 
    *pDegree = 12.345;
    printf("%lf\n",*pDegree);
    return 0;
}
