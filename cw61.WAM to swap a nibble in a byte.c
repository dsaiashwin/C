/*
Test case 1 : 
Enter the hexa-decimal value : AB
After swap nibble : BA

Test case 2 :
Enter the hexa-decimal value : cd
After swap nibble : dc
*/
#include <stdio.h>
#define swap(h)                 \
{                               \
    h= ( (h & 0x0F) << 4 )      \
    |  ( (h & 0xF0) >> 4 );     \
}
int main()
{
    unsigned int n;
    printf("Enter the Hexa-decimal value : ");
    scanf("%X",&n);
    swap(n);
    printf("After swap nibble : %X",n);
}
