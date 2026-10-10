#include <stdio.h>

int main()
{
    int b,s,c,g;
    unsigned int num;
    printf("Enter the number in hexadecimal : ");
    scanf("%x",&num);
    
    printf("Enter the number of bits in decimal: ");
    scanf("%d",&b);
    
    s = ( num | (  ( 1 << b) - 1 ) );
    c = ( num &  ( ~( 1 << b) + 1 ) );
    g = (num  &  (  ( 1 << b) - 1 ) );
    
    printf("After setting %d bits from lsb : %x\n",b,s);
    
    printf("After clearing %d bits from lsb : %x\n",b,c);
    
    printf("After getting %d bits from lsb : %x\n",b,g);
    
}
