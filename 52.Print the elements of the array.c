#include <stdio.h>

int main()
{
    int arr[5]={10,20,30,40,50},i=0;
    int*ptr=arr;
    printf("Array's elements are\n");
    while (i<5)
    {
        printf("%d\n",*(ptr+i));
        i++;
    }
}
