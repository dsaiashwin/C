#include <stdio.h>

void print_sort(int a[], int s);

int main()
{
    int size, iter;
    
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter %d elements\n",size);
    for (iter = 0; iter < size; iter++)
    {
        scanf("%d", &arr[iter]);
    }
    
    print_sort(arr, size);
    printf("\nOriginal array values ");
    for (int i = 0 ; i < size ; i++)
    {
        printf("%d ",arr[i]);
    }
}
void print_sort(int*a, int size)
{
    int min = 1000;
    int max = 0;
    
    for (int i = 0 ; i < size ; i++)
    {
        if (min > a[i])
        min=a[i];
        
        if (max < a[i])
        max = a[i];
    }
    printf("After sorting : %d ",min);
    
    for (int i = 0 ; i < size-1 ; i++)
    {   int n_small=max;
        for (int j = 0 ; j < size; j++)
        {
            if (min < a[j] && n_small > a[j])
                n_small=a[j];
            
        }
        printf("%d ",n_small);
        min=n_small;
    }
}
