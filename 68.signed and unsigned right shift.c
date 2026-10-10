#include <stdio.h>
int main()
{
    int num1,shift1,res_sign=0;
    unsigned int num2,shift2,res_unsign=0;
    
    printf("Enter the number for signed variable : ");
    scanf("%d",&num1);
    
    printf("Enter the umber of shifts to be performed : ");
    scanf("%d",&shift1);
    
    
    res_sign=num1 >> shift1;
    
    
    printf("After performing signed right shift : %d\n",res_sign );
    
    
    printf("Enter the number for signed variable : ");
    scanf("%u",&num2);
    
    printf("Enter the umber of shifts to be performed : ");
    scanf("%u",&shift2);
    
    
    res_unsign=num2 >> shift2;
    
    printf("After performing signed right shift : %ul",res_unsign );
    
}
