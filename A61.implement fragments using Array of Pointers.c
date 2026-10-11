/*
Name : Sai Ashwin D
Date : 26-04-2025
Description : To implement fragments using Array of Pointers
Sample Input : 

Enter no.of rows : 3
Enter no of columns in row[0] : 4
Enter no of columns in row[1] : 3
Enter no of columns in row[2] : 5
Enter 4 values for row[0] : 1 2 3 4
Enter 3 values for row[1] : 2 5 9
Enter 5 values for row[2] : 1 3 2 4 1

Sample Output :

Before sorting output is:

1.000000 2.000000 3.000000 4.000000 2.500000

2.000000 5.000000 9.000000 5.333333

1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

After sorting output is:

1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

1.000000 2.000000 3.000000 4.000000 2.500000

2.000000 5.000000 9.000000 5.333333
*/
#include <stdio.h>
#include <stdlib.h>

int fragments(int, float *[] , int[]);

int main()
{
    int r;
    
    printf("Enter no.of rows : ");
    scanf("%d",&r);
    
    int col[r];
    for ( int i = 0 ; i < r ; i++)
    {
        printf("Enter no of columns in row[%d] :",i);
        scanf("%d",&col[i]);
    }
    
        float *ptr[r];                                          // Dynamic memory allocation for row pointers
    for ( int  i = 0 ; i < r ; i++ )
    {
        ptr[i]=malloc((col[i] + 1)*sizeof(float));
    }
                                                                //reading column elements

    for ( int i = 0 ; i < r ; i++ )
    {   
        printf("Enter %d values for row[%d] : ",col[i],i);
        for ( int j  = 0 ; j < col[i] ; j++)
        {
            scanf("%f", &ptr[i][j]);
        }
    }
    
                                                                // Calculating averages and storing in last index
    for (int i = 0 ; i < r ; i++)
    {   int j;
        float sum=0;
        for ( j = 0 ; j < (col[i]) ; j++ )
        {
            sum+=ptr[i][j];
        }
        ptr[i][j] = (sum/(col[i]));
    }
    
                                                                //before Sorting
    printf("Before sorting output is:\n");
    for ( int i = 0 ; i < r ; i++)
    {
        for ( int j  = 0 ; j <= col[i] ; j++)
        {
            printf("%f ", ptr[i][j]);
        }
        printf("\n");
    }

    float*temp=NULL;
                                                                // Sorting rows based on their last value (average)
    for ( int i = 0 ; i < (r-1) ; i++)
    {
        for (int j = 0; j < r - i - 1; j++) 
        {
            int l1 = col[j];
            int l2 = col[j+1];
                                                                // Compare averages
            if ( ptr[j][l1] > ptr[j+1][l2])                     
            {
                                                                // Swap row pointers
                temp = ptr[j+1];
                ptr[j+1] = ptr[j];
                ptr[j] = temp;
                                                                // Swap column sizes also
                int tempCol = col[j];
                col[j] = col[j+1];
                col[j+1] = tempCol;
            }
        }
    }
    fragments(r, ptr, col);
                                                                //Free the Dynamically Allocated memory 
    for ( int  i = 0 ; i < r ; i++ )
    {
        free(ptr[i]);
    }   
}

int fragments(int r, float *ptr[] ,int col[])
{
        //After Sorting
    printf("After sorting output is:\n");
    for ( int i = 0 ; i < r ; i++)
    {
        for ( int j = 0; j <= col[i] ; j++)
        {
            printf("%f ", ptr[i][j]);
        }
        printf("\n");
    }
}
