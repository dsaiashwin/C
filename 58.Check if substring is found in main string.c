#include <stdio.h>
int substr(char*s,char*sb);

int main()
{
    char s[30],sb[10];
    
    //printf("Enter the main string : ");
    scanf("%[^\n]",s);
    
    //printf("Enter the sub string : ");
    scanf(" %[^\n]",sb);
    substr(s,sb);
    
}

int substr(char*s,char*sb)
{

    for (int i = 0 ; i < 30 ; i++)
    {   int j=0;
        while(j < 10 && s[i+j] == sb[j])
        {
           j++;
        }
            if (sb[j]=='\0')
            {
                printf("%s",s+i);
                return 0;
            }
    }

    printf("sub string is not found");
}
