#include <stdio.h>

void read_arr(int a[], int s);
void sq_ar(int*ptr,int s);

int main()
{
    int s;
    printf("Enter the array size : ");
    scanf("%d",&s);
    int arr[s];
    read_arr(arr,s);
    sq_ar(arr,s);
}

void read_arr(int a[],int s )
{   printf("Enter the array elements : ");
    for (int i=0; i<s;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array elements before squaring : ");
    for (int i=0; i<s;i++)
    {
        printf("%d ",a[i]);
    }
}

void sq_ar(int*ptr,int s)
{printf("\nArray elements after squaring : ");
    for (int i=0; i<s;i++)
    {
        *(ptr+i)=*(ptr+i) * *(ptr+i);
    }
    for (int i=0; i<s;i++)
    {
        printf("%d ",*(ptr+i));
    }
}
