#include <stdio.h>

void arr_ptr(int c, int (*ptr)[c], int r);

int main()
{
    int r,c;
    
    //printf("Enter the number of rows and cols : ");
    scanf("%d %d",&r,&c);
    
    int arr[r][c];
    
    //printf("Enter the elements : ");
    
    for (int i = 0 ; i < r ; i++)
    {
        for ( int j = 0 ; j < c ; j++)
        {
            scanf("%d",&arr[i][j]);
        }
        
    }
    arr_ptr(c, arr, r);
}

void arr_ptr(int c, int (*ptr)[c], int r)
{
    for (int i = 0 ; i < r ; i++)
    {
        for ( int j = 0 ; j < c ; j++)
        {
            printf("%d ",ptr[i][j]);
        }

    }
}
