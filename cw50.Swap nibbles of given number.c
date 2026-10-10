#include <stdio.h>
int main()
{
    unsigned int num,res=0;
    
    printf("Enter the hexa decimal value : ");
    scanf("%X",&num);
    
    res = ((num & 0X0F) << 4 ) | ((num & 0XF0) >> 4);
    
    printf("After swap : %X",res);
}
