#include<stdio.h>
int main()
{
    int num, *ptr;
    scanf("%d",&num);
    ptr=&num;
    printf("Value is %d",*ptr); 
}
