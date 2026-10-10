/*
Name : Sai Ashwin D
Date :06-04-2025
Description : to print 'n' bits from LSB of a number
Sample Input :

Enter the number: 10
Enter number of bits: 12

Sample Output : Binary form of 10: 0 0 0 0 0 0 0 0 1 0 1 0 
*/
#include <stdio.h>

int print_bits(int, int);

int main()
{
    int num, n;
    
    printf("Enter num, n :\n");
    scanf("%d %d", &num, &n);
    
    printf("Binary form of %d:", num);
    print_bits(num, n);
}

int print_bits(int num, int n)   // function definition of printing bits
{
    for ( int i = (n-1) ; i >= 0 ;i--)
    {
        if ( num & (1 << i) )   // checking if that particular bit is 1 or not
        printf("%d ",1);
        
        else
        printf("%d ",0);
    }
}
