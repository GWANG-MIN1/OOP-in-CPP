 #include <stdio.h>  
int main(){
 char * str ="abcdefg";  
 printf("%c\n", *str);  
 printf("%s\n",str);
 
 str++;  
 printf("%c\n", *str);  
 printf("%s\n",str);
 
 str += 2;  
 printf("%c\n", *str);  
 printf("%s\n", str);  
 return 0;
 }