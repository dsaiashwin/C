#include <stdio.h>
int first_n(int num);

int main()
{
    int num,res;
    printf("Enter the number : ");
    scanf("%d",&num);
    res=first_n( num);
    printf("Sum of 1st %d numbers is %d",num,res);
}

int first_n(int num)
{
    if (num == 0)
    return 0;
    else
    return (num+(first_n(num-1)));
}
