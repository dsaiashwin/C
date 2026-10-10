/*
Name : Sai Ashwin D
Date :15 - 04 - 2025
Description :To implement Circular left shift
Sample Input : Enter num: 12 Enter n : 3
Sample Output : Result in Binary: 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1
*/

#include <stdio.h>

int circular_left(int, int);
int print_bits(int);

int main()
{
    int num, n, ret;
    
    printf("Enter the num:");
    scanf("%d", &num);
    
    //printf("Enter n:");
    scanf("%d", &n);
    
    ret = circular_left(num, n);
    
    print_bits(ret);
}

int circular_left(int num , int n)
{
    int res1=0,res2=0;
    
    res1 = ( num >> (32-n) ) & ((1 << n) -1);           //getting or storing the n number of MSB bits from num
    
    res2 = num  << n ;                                  //clearing the n number or LSB bits from num for replacing with MSB bits
    
    num = res1 | res2 ;                                 //combining the result of above two steps for getting circular Left shifted value
    
    return num;
}

int print_bits( int ret)                                //printing the bits
{   printf("\nResult in Binary: ");
    for (int i = 31 ; i >= 0 ; i-- )
    {
        if ( ret & (1 << i ) )
        printf("%d ",1);
        
        else
        printf("%d ",0);
    }
}
