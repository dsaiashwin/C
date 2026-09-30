#include <stdio.h>

void fun(int arr1[], int size, int arr2[], int *new_size);

int main()
{
    int size,new_size;
    printf("Enter the size: ");
    scanf("%d",&size);
    int arr1[size],arr2[size];
    
    printf("Enter elements into the array: ");
    for (int i = 0 ; i < size ; i++)
    {
        scanf("%d",(arr1+i));
    }
    
    fun(arr1,size,arr2, &new_size);
    
    printf("After removing duplicates: ");
    for (int i = 0 ; i < new_size ; i++)
    {
        printf("%d ",arr2[i]);
    }
}
void fun(int arr1[], int size, int arr2[], int*new_size)
{
    *new_size=0;
    
    
    for (int i = 0 ; i < size ; i++)
    {int flag=1;
        for (int j = 0 ; j < *new_size ; j ++)
        {
            if (arr1[i]==arr2[j])
            {
                flag=0;
            }
            
        }
        if (flag)
        {
            arr2[*new_size]=arr1[i];
            *new_size+=1;
        }
    }
}
