#include <stdio.h>
int main()
{
    char s1[20],s2[20];
    int flag=1;
    printf("Enter the string1 : ");
    scanf("%[^\n]",s1);
    
    printf("Enter the string2 : ");
    scanf(" %[^\n]",s2);
    

    
    for (int i = 0 ; s1[i] != '\0' || s2[i] != '\0' ; i++)
    {
        
        if (s1[i] != s2[i])
        {
            flag = 0;
            break;
        }
            
    }
    if (flag)
    printf("Entered Strings are equal");
    
    else if (flag==0)
    printf("Entered Strings are not equal");
}
