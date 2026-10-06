#include <stdio.h>
int prnt_n(int n,int k);
int main()
{
    int n,k=0;
    //printf("Enter the number: ");
    scanf("%d",&n);
     prnt_n( n,k);
}
int prnt_n(int n, int k)
{
    
    if (k > n)
    return 0;
    else
    {
        printf("%d ",k);
        return prnt_n(n,k+=1);
    }
}
