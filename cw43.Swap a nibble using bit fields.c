#include <stdio.h>

struct swap_nibble
{
    unsigned int hex_dec : 8;
};

int main()
{
    unsigned int res,temp;
    struct swap_nibble sn;
    
    //printf("Enter the hexa-decimal value: ");
    scanf("%x",&temp);
    sn.hex_dec=temp;
    res = ( (sn.hex_dec & 0x0F) <<4 | (sn.hex_dec & 0xF0) >> 4);
    printf("After swap nibble : %X",res);
}
