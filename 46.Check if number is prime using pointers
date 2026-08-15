#include <stdio.h>

int is_prime(int*ptr,int*ptr1);
int main()
{
    int num,res;
    scanf("%d",&num);
    is_prime(&num,&res);
    printf("res=%d\n",res);
    if (res==1)
    printf("%d is a prime number",num);
    
    else if (res ==0)
    printf("%d is not a prime number",num);
}

int is_prime(int*ptr,int*ptr1)
{
    int i,c=0;
    for (i = 2 ; i < ((*ptr/2)+1); i++)
    {
        if ( *ptr%i == 0)
        {   c+=1;
        }
    }
    if (c >= 1)
    *ptr1=0;
    
    else
    *ptr1=1;
    
}
