#include <stdio.h>

char my_strcat(char*s1,char*s2);

int main()
{
    char s1[20],s2[10];
    
    //printf("Enter the string1 : ");
    scanf("%s",s1);
    
    //printf("Enter the string2 : ");
    scanf("%s",s2);
    
    my_strcat(s1,s2);
    
}
char my_strcat(char*s1,char*s2)
{int l1=0,l2=0;
    for (int i = 0 ; i < 10 ; i++)
    {
        if (*(s1+i)== '\0')
        break;
        
        l1++;
    }
    for (int i = 0 ; i < 10 ; i++)
    {
        if (*(s2+i)== '\0')
        break;
        
        l2++;
    }
    for (int i = 0 ; i < l2 ; i++)
    {
        *(s1+l1+i)=*(s2+i);
    }
    *(s1+l1+l2)='\0';
    printf("concatenate string is %s",s1);
}
