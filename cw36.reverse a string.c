#include <stdio.h>
int main()
{
    char s[20],ms[20];
    int l=0;
    printf("Enter the string : ");
    scanf("%[^\n]",s);
    
    for (int i = 0 ; i < 20 ; i++)
    {
        if (s[i]=='\0')
            break;
        
            l++;
    
    }
    for (int i = 0 ; i < l ; i++)
    {
        ms[i]=s[l-i-1];
    }
    ms[l]='\0';
    printf("Reversed string is %s",ms);   
}
