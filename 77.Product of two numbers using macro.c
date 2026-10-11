/*
Instructions : Take two integers, 10 and 20
Product is 200
Take two double values 15.6 and 13.9
Product is 216.839996
*/
#include <stdio.h>
#define MUL(x,y) x*y

int main()
{
    int a,b;
    double s,t;
    
    //printf("Enter two integers : ");
    scanf("%d %d",&a,&b);
    printf("Product of %d and %d is %d",a,b,MUL(a,b));
    
    //printf("Enter two Double : ");
    scanf("%lf %lf",&s,&t);
    printf("\nProduct of %lg and %lg is %lg",s,t,MUL(s,t));
    
}
