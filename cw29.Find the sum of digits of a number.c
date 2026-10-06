#include <stdio.h>
int num_sum(int num);

int main()
{
    int num,res;
    //printf("Enterthe number : ");
    scanf("%d",&num);
    res=num_sum(num);
    printf("Sum of the digits is %d",res);
}

int num_sum(int num)
{
    if (num == 0)
    return 0;
    
    else
    return ((num%10)+num_sum(num/10));
    
}
