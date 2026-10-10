/*
Name : Sai Ashwin D
Date : 10 - 04 - 2025
Description : to toggle 'n' bits from given position of a number
Sample Input : 

Enter the number: 10
Enter number of bits: 3
Enter the pos: 5

Sample Output : Result = 50
*/

#include <stdio.h>

int toggle_nbits_from_pos(int, int, int);

int main()
{
    int num, n, pos, res = 0;
    
    printf("Enter num, n and val:");
    scanf("%d%d%d", &num, &n, &pos);
    
    res = toggle_nbits_from_pos(num, n, pos);
    
    printf("Result = %d\n", res);
}

int toggle_nbits_from_pos(int num, int n, int pos)
{
    
    int mask,res;
    
    mask = ((( 1 << n ) -1) << (pos - n + 1)); // finding the mask to get nnumber of bits from pos
    
    res = num ^ mask;                          // doing bitwise XOR with Mask to get only that n bits toggled in num
    
    
    return res;
}
