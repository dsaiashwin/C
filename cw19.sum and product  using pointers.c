#include <stdio.h>
void su_pr(int * ptr1, int*ptr2);

void su_pr(int * ptr1, int*ptr2)
{
    int sum= (*ptr1) + (*ptr2) ;
    int pro= (*ptr1) * (*ptr2);
    printf("sum = %d,",sum);
    printf("product = %d",pro);
    
}

int main()
{
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    su_pr(&n1, &n2 );
}
