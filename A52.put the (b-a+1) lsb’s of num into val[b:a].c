/*
Name : Sai Ashwin D
Date : 11-04-2025
Description : Program to put the (b-a+1) lsb’s of num into val[b:a]
Sample Input : 

Enter the value of 'num' : 11
Enter the value of 'a' : 3
Enter the value of 'b' : 5
Enter the value of 'val': 174

Sample Output :

Result : 158
*/
#include <stdio.h>

int replace_nbits_from_pos(int, int, int, int);

int main()
{
    int num, a, b, val, res = 0;
    
    printf("Enter num, a, b, and val:");
    scanf("%d%d%d%d", &num, &a, &b, &val);
    
    res = replace_nbits_from_pos(num, a, b, val);
    
    printf("Result = %d\n", res);
}

int replace_nbits_from_pos(int num, int a, int b, int val)
{
    int nb = 0,res = 0 ;
    
    nb = b - a + 1;                                 // number of bits to be cleared
    
    num = (num & (( 1 << nb) -1)) ;                 //getting (b-a+1) number of bits in num
    
    val = val & ( ~( ( (1 << nb) -1) << (nb)) ) ;   // clearing  (a-b+1) number of bits from bth position
    
    num = num << (nb);                              // shifting num to position b
    
    res = val | num ;                               // Replacing the bits extracted from num to val
    
    return res;
}
