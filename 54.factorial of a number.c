#include <stdio.h>
int facto(int n);
int main()
{
    int n,res;
    printf("Enter the number: ");
    scanf("%d",&n);
    res=facto(n);
    printf("Factorial of %d is %d",n,res);
}
int facto(int n)
{
    if (n==1)
    return 1;
    
    else
    return n * (facto(n-1));
}
