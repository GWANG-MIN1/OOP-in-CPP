#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str1[] = "Hello world";
    char *s;
    s = str1;
    //s=(char*)malloc(strlen(str)+1);
    //strcppy(s, str1);
    printf("%s\n",s);
    strcpy(str1, "Howdy!");
    printf("%s\n",s);
    printf("%s\n",str1);
    return 0;
}