/*
Name : Sai Ashwin D
Date :06-04-2025
Description : to count number of set bits in a given number and print parity
Sample Input : Enter the number : 7
Sample Output : 
Number of set bits = 3

Bit parity is Odd
*/

#include <stdio.h>

int main()
{
    int num,s,c=0;
    
    printf("Enter the number : ");
    scanf("%d",&num);
    for ( int i = 0 ; i < 31 ; i++ )
    {
        if ( num & (1 << i) )
        {
            c++;                        //count number of set bits
        }
    } 
    printf("Number of set bits = %d\n",c);    
    if ( c & 1)                         //deciding the parity 
    {
        printf("Bit parity is Odd\n");
    }
    else
    printf("Bit parity is Even\n");
    
}
