#include <stdio.h>
int fib(int n,int n1,int n2);

int main()
{
    int n;
    //printf("Enter the limit : ");
    scanf("%d",&n);
    printf("Fibonacci series are : ");
    fib(n,0,1);
}
int fib(int n,int n1,int n2)
{
    
    if (n1 <=n)
    {
        printf("%d, ",n1);
        
        fib(n,n2,n1+n2);
    }
    
}
