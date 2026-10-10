/*
Name : Sai Ashwin D
Date : 10-04-2025
Description : Implement atoi function
Sample Input : 

Enter the number: 10
Enter number of bits: 3
Enter the value: 12

Sample Output : Result = 12
*/

#include <stdio.h>

int replace_nbits(int, int, int);

int main()
{
    int num, n, val, res = 0;
    
    printf("Enter num, n and val:");
    scanf("%d%d%d", &num, &n, &val);
    
    res = replace_nbits(num, n, val);
    
    printf("Result = %d\n", res);
}

int replace_nbits(int num, int n, int val)
{
    int res1,res2,res3;
    
    res1 = val & ((1 << n) -1 );            // getting N bits from val
    
    res2 = num & (~((1 << n) -1 )) ;       // clearing n bits from num
    
    res3 = res2 | res1;                    // replacing in the last n bits of num
    
    return res3;
}
