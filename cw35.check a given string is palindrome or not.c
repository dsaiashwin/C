#include <stdio.h>
 int main()
{
    char s[20];
    int length=0,f=1;
    printf("Enter the string : ");
    scanf("%[^\n]",s);
    
    for(int i = 0 ; i < 20 ; i++)
    {
        if (s[i])
        length++;
        
        else 
        break;
    }
    for (int i = 0 ; i < length ; i++)
    {
        if ((s[i])  != (s[length-i-1])) 
        {
            printf("No, Entered string is not palindrome");
            f=0;
            break;
        }
    }
    if (f)
    printf("Yes, Entered string is palindrome.");
 }
