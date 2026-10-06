#include <stdio.h>

void negative_fibonacci(int limit, int n1, int n2, int sub);

int main()
{
    int limit;
    
    printf("Enter the limit : ");
    scanf("%d", &limit);
    if (limit <= 0)
    negative_fibonacci(limit, 0, 1, 0);
    
    else
    printf("Invalid input");
}

void negative_fibonacci(int limit, int n1, int n2, int sub)
{
    while (sub >= limit && sub <= -limit)
    {
        printf("%d ",sub);
        
        n1=n2;
        n2=sub;
        sub=n1-n2;
        void negative_fibonacci(int limit, int n1, int n2, int sum);
    }
}
