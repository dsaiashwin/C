#include <stdio.h>
int main()
{
    int n=0,c=0;
    unsigned int num;
    printf("Enter the number in Hexadecial format: ");
    scanf("%x",&num);
    
    for ( n = 31 ; n >= 0 ; n--)
    {
        if (num & ((1<<n)) )
        c+=1;
    }
    printf("Number of set bits : %d",c);
}
