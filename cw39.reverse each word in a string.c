#include <stdio.h>
char rev_word(char*str);

int main()
{
    char s[30];
    printf("Enter the string: ");
    scanf("%[^\n]",s);
    rev_word(s);
}
char rev_word(char*str)
{   int l=0,i=0,j=0;
    while (str[l] != '\0')
    {
        l++;
    }
    printf("Reversed string: ");
    for (i = l ; i >= 0 ; i--)
    {
        if (str[i] == ' ' || i == 0 )
        {
            if (i==0)
            printf("%s ",str+i );
            
            else
            printf("%s ", str+i+1 );
            
            str[i]='\0';
        }
        
    }
    
}
