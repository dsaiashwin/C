#include <stdio.h>

int avg_arr(int a[],int s);
void read_arr(int*ptr, int s);

int main()
{
    int size,sum;
    float avrg;
    printf("Enter array size : ");
    scanf("%d",&size);
    int arr[size];
    read_arr(arr,size);
    sum=avg_arr(arr,size);
    avrg=((float)sum/size);
    printf("Average of array elements : %g",avrg);
}

void read_arr(int a[],int s)
{
    printf("Enter array elements : ");
    for (int i=0;i<s;i++)
    {
        scanf("%d",&a[i]);
    }
}

int avg_arr (int*ptr,int s)
{int sum=0;
    for (int i = 0 ; i < s ; i++ )
    {
        sum+=*(ptr+i);
    }
    return sum;
}
