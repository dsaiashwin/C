#include <stdio.h>

char cpstr(char*s);

int main()
{
    char s[20];
    printf("Enter the string : ");
    scanf("%[^\n]",s);
    cpstr(s);
}
char cpstr(char*s)
{
    char cst[20];
    printf("Copied string is ");
    int i;
    for (i = 0; i < 20 ; i++)
    {
        if (*(s+i) != '\0')
        {
            *(cst+i)=*(s+i);
        }
        else
        break;
        
    }
    *(cst+i)='\0';
    printf("%s",cst);
}
