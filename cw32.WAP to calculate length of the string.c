#include<stdio.h>
int main()
{
    char s[20],c=0;
    printf("Enterthe string: ");
    scanf("%[^\n]",s);
    
    for (int i = 0; i < 20 ; i++)
    {
        if (s[i] != '\0')
        c+=1;
        
        else
        break;
    }
    printf("String length is %d",c);
}
