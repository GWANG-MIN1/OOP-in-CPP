#include <stdlib.h>
#include <stdio.h>

 int & makeInt(int val){  
 int*p;
 p = (int *)malloc(sizeof(int));
 *p =val;
 return *p;
 }
 int main(){
  int &a = makeInt(3);
  printf("%d\n",a);
 }
