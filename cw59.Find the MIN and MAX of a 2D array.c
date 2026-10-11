#include <stdio.h>

int main()
{
    int r,c,min=1000,max=-1;
    
    printf("Enter the row size : ");
    scanf("%d",&r);
    
    printf("Enter the column size : ");
    scanf("%d",&c);
    
    int arr[r][c];
    
    printf("Enter the array elements : ");
    
    for (int i = 0 ; i < r ; i++)
    {
        for ( int j = 0 ; j < c ; j++)
        {
            scanf("%d",&arr[i][j]);
        }
        
    }
    
    for (int i = 0 ; i < r ; i++)
    {
        for (int j = 0 ; j < c ; j++)
        {
            if ( min > arr[i][j] )
                min = arr[i][j];
            
            if ( max < arr[i][j] )
                max = arr[i][j];
        }
        
    }
    
    printf("Min is %d\n",min);
    printf("Max is %d",max);
}
