/*
Name : Sai Ashwin D
Date : 15-04-2025
Description : Implement Circular right shift
Sample Input : Enter num: 12 Enter n : 3
Sample Output : Result : 10000000 00000000 00000000 00000001
*/
#include <stdio.h>

int circular_right(int, int);
int print_bits(int);

int main()
{
    int num, n, ret;
    
    printf("Enter the num:");
    scanf("%d", &num);
    
    //printf("Enter n:");
    scanf("%d", &n);
    
    ret = circular_right(num, n);
    
    print_bits(ret);
}
int circular_right(int num, int n)
{
    int res1,res2;
    
    res1 = num  & ((1 << n)-1);                     //getting or storing the n number of LSB bits
    
    res2 = (num >> n) & ( ( 1 << (32 - n))-1 );     //Right Shifting the num by n times and clearing the n MSB bits
    
    num = (res1 << 32-n) | res2;                    //Right shifting LSB to make it MSB and combining the result to get circular right shifted value
    
    return num;
    
}

int print_bits(int ret)
{   printf("Result in Binary: ");
    for (int i = 31 ; i >= 0 ; i-- )
    {
        if (ret & (1 << i) )
        printf("%d ",1);
        
        else
        printf("%d ",0);
    }
}
