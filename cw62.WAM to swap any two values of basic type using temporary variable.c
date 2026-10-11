/*
Test case 1 : 
Enter the num1 : 10
Enter the num2 : 20
After swapping :
num1 is 20
num2 is 10

Test case 2 :
Enter the num1 : -1
Enter the num2 : -2
After swapping :
num1 is -2
num2 is -1
*/
#include <stdio.h>
#define Swap(n1,n2) \
{   int temp = n1;  \
    n1 = n2;        \
    n2 = temp;      \
}                 

int main()
{
    int n1,n2;
    
    printf("Enter the num1 : ");
    scanf("%d",&n1);
    
    printf("Enter the num2 : ");
    scanf("%d",&n2);
    
    printf("After swapping : \n");
    
    Swap(n1,n2)
    
    printf("num1 is %d\n",n1);
    printf("num2 is %d",n2);
}
