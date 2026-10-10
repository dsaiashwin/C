#include <stdio.h>
int main()
{
    int b,s,c,g;
    unsigned int num;
    
    printf("Enter the number in the hexadecimal format: ");
    scanf("%x",&num);
    
    printf("Enter n value: ");
    scanf("%d",&b);
    
    s = ( num | (  ( 1 << b)  ) );
    c = ( num &  ( ~( 1 << b) ) );
    
    
    printf("Result after setting nth bit is :  : %X\n",s);
    
    printf("Result after clearing nth bit is : %X\n",c);
    
    if(num  &  (  ( 1 << b) ))
    printf("Get bit at nth position is : 1");
    
    else
    printf("Get bit at nth position is : 0");
    
}
