#include<stdio.h>
char prstr(char*s);

int main()
{
    char c[20];
    printf("Enter the string : ");
    scanf("%[^\n]",c);
    prstr(c);   
}
char prstr(char*s)
{
    while (*s != '\0')
    {
        printf("%c",*s);
        s++;
    }
    
}
