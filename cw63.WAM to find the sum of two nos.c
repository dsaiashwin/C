#include <stdio.h>
#define SUM(a,b) a+b

int main()
{
    int a,b;
    
    printf("Enter the num1 : ");
    scanf("%d",&a);
    
    printf("Enter the num2 : ");
    scanf("%d",&b);
    
    printf("The Sum is %d",SUM(a,b));
    
}
