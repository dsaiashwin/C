#include <stdio.h>

int is_prime(int*n);

int main()
{
    int n;
    //printf("Enter a number: ");
    scanf("%d",&n);
    is_prime(&n);
    return 0;
}
int is_prime(int*n)
{   
    if (*n <= 0)
    printf("Invalid input");
    
    else
    {
        for (int i = 2; i <= ((*n)/2) ; i++)
        {
            if ((*n)%i==0)
            {
                printf("%d is not a prime number",*n);
                return 0;
            }
        }
       printf("%d is a prime number",*n);
    }
}
