#include <stdio.h>

int main()
{
    char str[30];
    int l=0;
    //printf("Enter the string: ");
    scanf("%[^\n]",str);
    
    for (int i = 0 ; str[i] != '\0' ; i++)
    {
       l++; 
    }
    int i=0,ns=0;
    printf("Reversed string: ");
    while (i <= l)
    {
        if ( str[i] == ' ' || str[i] == '\0')
        {
            for (int j = i-1 ; j >= ns ; j--)
            {
                printf("%c", str[j]);
            }
            
            if (str[i] == ' ')
            {
                printf("%c",str[i]);
            }
            ns=i+1;
        }
        i++;
    }
    
}
