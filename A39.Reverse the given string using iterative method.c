#include <stdio.h>

void reverse_iterative(char str[]);

int main()
{
    char str[30];
    
    printf("Enter any string : ");
    scanf("%[^\n]", str);
    
    reverse_iterative(str);
    
    printf("Reversed string is %s\n", str);
}
void reverse_iterative(char*str)
{
    //Swaping
    int l=0;
    char temp;
    while (str[l] !='\0')
    {
        l++;
    }
    
    for ( int i = 0 ; i < (l/2) ; i++ )
    {
        temp=str[i];
        str[i]=str[l-i-1];
        str[l-i-1]=temp;
    }
}
