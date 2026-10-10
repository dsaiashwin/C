/*
Name : Sai Ashwin D
Date :
Description : to get 'n' bits from given position of a number
Sample Input :

Enter the number: 12
Enter number of bits: 3
Enter the pos: 4

Sample Output : Result = 3
*/
#include <stdio.h>

int get_nbits_from_pos(int, int, int);

int main()
{
    int num, n, pos, res = 0;
    
    printf("Enter num, n and val:");
    scanf("%d%d%d", &num, &n, &pos);
    
    res = get_nbits_from_pos(num, n, pos);
    
    printf("Result = %d\n", res);
}
int get_nbits_from_pos(int num, int n, int pos)
{
    int mask,res;
    
    mask = ((( 1 << n ) -1) << (pos - n + 1)); // finding the mask to get nnumber of bits from pos
    
    res = num & mask;                          // doing bitwise and with Mask to get only that n bits in num
    
    res = res >> (pos - n + 1);                // right shifting the resultant value to get the required value 
    
    return res;
}
