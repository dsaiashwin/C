#include <stdio.h>

void positive_fibonacci(int limit, int n1, int n2, int sum);

int main()
{
    int limit;
    
    printf("Enter the limit : ");
    scanf("%d", &limit);
    if (limit >= 0)
    positive_fibonacci(limit, 0, 1, 0);
    
    else 
    printf("Invalid input");
}

void positive_fibonacci(int limit, int n1, int n2, int sum)
{
    
    
    while (sum <= limit)
    {   
        printf("%d ",sum);
        
        n1=n2;
        n2=sum;
        sum= n1+n2;
        void positive_fibonacci(int limit, int n1, int n2, int sum);
       
    }
    
}
