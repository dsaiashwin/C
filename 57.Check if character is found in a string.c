#include <stdio.h>
int char_str(char*s,char c);

int main()
{
    char c,s[30];
    
    printf("Enterthe string : ");
    scanf("%[^\n]",s);
    printf("Enter a character : ");
    scanf(" %c",&c);
    char_str(s,c);
}

int char_str(char*s,char c)
{
    for (int i = 0; i < 30 ; i++)
    {
        if (s[i] == c)
        {
            printf("%s",s+i);
            return 0;
        }
        
    }
    printf("Character is not found in the string");
}
