#include <stdio.h>
int sum_num(int n,int k,int sum);

int main()
{
    int n,k=0,sum=0,res;
    //printf("Enter the N value : ");
    scanf("%d",&n);
    res=sum_num( n,k,sum);
    printf("Sum is %d",res);
}
int sum_num(int n,int k,int sum)
{
    if (n<=k)
    return sum;
    
    else
    {
        k+=1;
        return sum_num(n,k,sum+k);
    }
}
