#include <stdio.h>
#include <string.h>
int main()
{
    char s1[10],s2[10],c=32;
    int l1=0,l2=0,n;
    int flag = 1;
    //printf("Enter the string1 : ");
    scanf("%s",s1);
    
    //printf("Enter the string2 : ");
    scanf(" %s",s2);
    
    //printf("Enter the n : ");
    scanf("%d",&n);

    
    int i=0;
    for (i = 0 ; i < 10 ; i++)
    {
        if(s1[i] == '\0' || s1[i]==c)
        {   
            break;
        }
        l1++;
    }

    for ( int i = 0 ; i < 10 ; i++)
    {
        if(s2[i] == '\0' || s2[i]==c)
        {   
            break;
        }
        l2++;
    }
    
    if (l1 == l2)
    {int i;
        for (i = 0 ; i < n ; i++)
        {
            if(s1[i] !=s2[i])
            {
                flag=0;
                break;
            }

            
        }
        if (flag==1)
        printf("str1 is equal to str2.");
        
        else if (flag==0)
        {
            if (s1[i] > s2[i])
            printf("str2 is less than str1");
            
            else if (s2[i] > s1[i])
            printf("str1 is less than str2");
        }
        
    }
    else if (l1 < l2 )
    {
        printf("str1 is less than str2.");
    }
    else if (l2 < l1 )
    {
        printf("str2 is less than str1.");
    }
    
}
