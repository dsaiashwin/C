#include <stdio.h>
int main()
{
    char c;
    char*ptr;
    
    scanf("%c",&c);
    ptr=&c;
    
    printf("Character entered is %c",*ptr);
}
