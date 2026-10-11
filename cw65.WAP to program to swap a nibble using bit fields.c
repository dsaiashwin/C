#include <stdio.h>
struct swap
{
    unsigned char lower_nibble : 4;
    unsigned char upper_nibble : 4;
}s;

int main()
{
    unsigned char num;
    unsigned char temp;
    printf("Enter the hexa-decimal value : ");
    scanf("%hhx",&num);
    s.lower_nibble = (num & 0x0F);
    s.upper_nibble = (num & 0xF0 ) >> 4;
    //swapping nibbles
    num = (s.lower_nibble << 4 ) | s.upper_nibble;    
    printf("After swap nibble : %X",num);
}
