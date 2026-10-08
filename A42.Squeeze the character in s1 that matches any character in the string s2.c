#include <stdio.h>

void squeeze(char [], char []);

int main()
{
    char str1[30], str2[30];
    
    printf("Enter string1:");
    scanf("%[^\n]", str1);
    
    getchar();
    printf("Enter string2:");
    scanf("%[^\n]", str2);
    
    squeeze(str1, str2);
    
    printf("After squeeze s1 : %s\n", str1);
    
}
void squeeze(char*s1, char*s2)
{
    int s=0,t=0;
    while (s1[s] != '\0')
    s++;
    
    while (s2[t] != '\0')
    t++;
    
    for (int j = 0 ; j < t ; j++)
    {
        for(int i = 0 ; i < s ; i++)
        {
            if ( s2[j] == s1[i] && s1[i+1] =='\0')
            s1[i]='\0';
            
            else if (s2[j]==s1[i])
            {
                for(int f = i ; f < s ; f++)
                {   s1[f]=s1[f+1];
                    i-=1;
                }
            }
           
            
        }
        
    }
}
