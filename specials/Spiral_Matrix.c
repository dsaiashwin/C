#include <stdio.h>

int main()
{
    
    int r=0,c=0;

    printf("Enter no.of Rows");
    scanf("%d",&r);
    printf("Enter no.of Cols");
    scanf("%d",&c);
    int top=0,bottom=r-1,left=0,right=c-1;
    int arr[r][c];
    for(int i = 0; i < r ; i++)
    {
        for (int j = 0 ; j < c ; j++)
        {
            printf("Enter array elements for %d row and %d column",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    
    for(int i = 0; i < r ; i++)
    {
        for (int j = 0 ; j < c ; j++)
        {
            printf(" %d ",arr[i][j]);
        }
        printf("\n");
    }
    
    while((left <= right)&&(top <= bottom))
    {
        for(int i = left ; i <= right ; i++)
        {
            printf("%d ",arr[top][i]);
        }
        top++;
        for(int i = top ; i <= bottom ; i++)
        {
            printf("%d ",arr[i][right]);
        }
        right--;
        if (top <= bottom)
        {   for(int i = right ; i >= left ; i--)
            {
                printf("%d ",arr[bottom][i]);
            }
        }
        bottom--;
        if(left <= right)
        {
            for(int i = bottom  ; i >= top ; i--)
            {
                printf("%d ",arr[i][left]);
            }
        }
        left++;
        
    }
}
