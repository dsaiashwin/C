#include <stdio.h>
int expone(int n, int m);

int main()
{
    int n,m,res;
    printf("Enter n and m : ");
    scanf("%d %d",&n,&m);
    
    res=expone( n, m);
    printf("%d to the power of %d is %d",n,m,res);
    
}

int expone(int n, int m)
{
    if (m ==0 )
    return 1;
    
    else
    return n*expone(n,m-1);
}
