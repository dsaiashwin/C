#include <stdio.h>
int my_swap(int*ptr1,int*ptr2)
{
    int temp=0;
    
    temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
int main()
{
    int num1,num2;
    
    //printf("Enter the number1 : ");
    scanf("%d",&num1);
    //printf("Enter the number2 : ");
    scanf("%d",&num2);
    
    printf("Before swap:\n");
    printf("num1 is %d\n",num1);
    printf("num2 is %d\n",num2);
    
    my_swap(&num1,&num2);
    
    printf("After swap:\n");
    printf("num1 is %d\n",num1);
    printf("num2 is %d",num2);
}
