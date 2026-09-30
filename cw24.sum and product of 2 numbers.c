#include <stdio.h>
void sum_(int*n1,int*n2,int*sum);
void pro_(int*n1,int*n2,int*pro);
int main()
{
    int num1,num2,sum=0,pro=1;
    
    //printf("Enter the number1 : ");
    scanf("%d",&num1);
    
    //printf("Enter the number2 : ");
    scanf("%d",&num2);
    
    sum_(&num1,&num2,&sum);
    pro_(&num1,&num2,&pro);
    
    printf("Sum is %d\n",sum);
    printf("Product is %d",pro);
}

void sum_(int*n1,int*n2,int*sum)
{
    *sum=(*n1) + (*n2);
}

void pro_(int*n1,int*n2,int*pro)
{
    *pro=(*n1) * (*n2);
}
