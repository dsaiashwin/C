/*
Name : Sai Ashwin D
Date : 10-04-2025
Description : to get 'n' bits of a given number
Sample Input : 

Enter the number: 10
Enter number of bits: 3

Sample Output : Result = 3
*/

#include <stdio.h>

int get_nbits(int, int);

int main()
{
    int num, n, res = 0;
    
    printf("Enter num and n:");
    scanf("%d%d", &num, &n);
    
    res = get_nbits(num, n);   //function call
    
    printf("Result = %d\n", res);
}

int get_nbits(int num, int n)
{
    int req=0;
    req=num & ((1<< n) -1);  //applying bitwise and for the mask value to get n bits
    
    return req;
}
