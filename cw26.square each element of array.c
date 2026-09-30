#include <stdio.h>
int square(int arr[], int size);

int main()
{
    int s;
    printf("Enter the size : ");
    scanf("%d",&s);
    int a[s];
    square(a,s);
}
int square(int arr[], int size)
{
    printf("Enter the array elements : ");
    for (int i = 0 ; i < size ; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("Square is ");
    for (int i = 0 ; i < size ; i++)
    {
        printf("%d ",(arr[i] * arr[i]));
    }
}
