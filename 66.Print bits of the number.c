#include <stdio.h>
int main()
{
    int num,n=0;

    printf("Enter the number : ");
    scanf("%d",&num);
    
    for (n=31 ; n >=0 ; n--)
    {
        if(num & (1 << n))
        {
            printf("%d",1);
        }
        else
        {
            printf("%d",0);
        }
    }
}
