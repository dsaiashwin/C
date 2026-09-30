#include <stdio.h>

int third_largest(int a[], int s);

int main()
{
    int size, ret;
    
    //Read size from the user
    printf("Enter the size of the array :");
    scanf("%d", &size);
    
    int arr[size];
    
    //Read elements into the array
    printf("Enter the elements into the array: ");
    for (int i = 0 ; i < size ; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    //funtion call
    ret = third_largest(arr, size);
    
    printf("Third largest element of the array is %d\n", ret);
}
int third_largest(int a[], int s)
{
    int fl=0,sl=0,tl=0;
    
    for (int i = 0 ; i < s ; i++)
    {
        if ( fl <= a[i] )
        {   tl=sl;
            sl=fl;
            fl=a[i];
        }
        else if ( fl > a[i] && sl < a[i])
        {   tl=sl;
            sl=a[i];
        }
        else if (sl > a[i] && tl < a[i])
        tl=a[i];
    }
    return tl;
}
