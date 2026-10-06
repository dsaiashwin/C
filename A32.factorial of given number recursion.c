#include <stdio.h>

int main()
{
    static int num;
    static unsigned long long int fact = 1;
    
    if (fact==1)
    {
        printf("Enter the value of N : ");
        scanf("%d",&num);
        
        if (num < 0)
        {
            printf("Invalid Input");
            return 0;
        }
    }
    
    if (num > 1)
    {
        fact*=num;
        num--;
        return main();
         
    }
    else if (num == 0 ||num == 1)
    {
        printf("Factorial of the given number is %llu",fact);
        return 0;
    }
    else
    printf("Invalid Input");

}
