/*
Enter the number of rows and cols : 2 3
Enter the elements : 10 20 30 40 50 60
Elements of the array are : 
10 20 30
40 50 60
*/
#include <stdio.h>
int main()
{
    int r,c; 
    printf("Enter the number of rows and cols :");
    scanf("%d%d",&r,&c);   
    int arr[r][c];
    printf("Enter the elements : ");
    for (int i = 0 ; i < r ; i++ )
    {
        for (int j = 0 ; j < c ; j++ )
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Elements of the array are :");
    for (int i = 0 ; i < r ; i++ )
    {
        for (int j = 0 ; j < c ; j++ )
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
