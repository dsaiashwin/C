#include <stdio.h>
int main()
{
    int b,p,s,c,g;
    unsigned int num;
    
    //printf("Enter the number in hexadecimal : ");
    scanf("%x",&num);
    
    //printf("Enter the number of bits in decimal: ");
    scanf("%d",&b);
    
    //printf("Enter the position :");
    scanf("%d",&p);
    
    s = (num | ((( 1 << b)-1)  << (p-b+1) ) );
    
    c = num &  ~((( 1 << b) - 1)  << (p -b +1)) ;
    
    g = (num  >>  (  p - b +1 ) & ((1 << b) -1 ) );
    
    printf("After setting %d bits from %d pos : %x\n",b,p,s);
    
    printf("After clearing %d bits from %d pos : %x\n",b,p,c);
    
    printf("After getting %d bits from %d pos : %x\n",b,p,g);

}
