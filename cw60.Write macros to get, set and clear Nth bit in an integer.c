#include <stdio.h>
#define GET_BIT(num,n)  ((num >> n) & 1)
#define SET_BIT(num,n)  num | (1 << n)
#define CLEAR_BIT(num,n)  num & (~(1 << n))

int main()
{
    int num,n;
    /*
    printf("Enter the Number : ");
    scanf("%d",&num);
    
    printf("Enter n th bit : ");
    scanf("%d",&n);
    */
    
    printf("Getting the nth bit %d\n",GET_BIT(7,3));
    printf("Setting the nth bit %d\n",SET_BIT(7,3));
    printf("Clearing the nth bit %d\n",CLEAR_BIT(7,3));
}
