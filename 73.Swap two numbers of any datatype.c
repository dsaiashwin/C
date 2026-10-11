#include <stdio.h>

void swap ( void* ptr1 , void* ptr2 ,int dsize);

int main()
{
    int n1=10,n2=20;
    printf("Before swapping num1 = %d, num2 = %d\n",n1,n2);
    swap( &n1,&n2,sizeof(int));
    printf("After swapping num1 = %d, num2 = %d\n",n1,n2);
    float f1=10.5,f2=20.5;
    printf("Before swapping n1 = %g, n2 = %g\n",f1,f2);
    swap( &f1,&f2,sizeof(float));
    printf("After swapping n1 = %g, n2 = %g\n",f1,f2);
}
void swap ( void* ptr1 , void* ptr2 ,int dsize)
{
    char temp;                                  //type casting pointers to char to access bytes
    char* p1 = (char*)ptr1;
    char* p2 = (char*)ptr2;
    
    for (int i = 0 ; i < dsize ; i++)           //making byte level swapping 
    {
        temp=p1[i];
        p1[i]=p2[i];
        p2[i]=temp;
    }
}
