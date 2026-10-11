/*
Name : Sai Ashwin D
Date : 23-04-2025
Description : To find the product of given matrix
Sample Input : 

Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :
1      2      3
1      2      3
1      2      3
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :

1      1     1
2      2     2
3      3     3

Sample Output : 

Product of two matrix :
14      14      14
14      14      14
14      14      14

*/
#include <stdio.h>
#include <stdlib.h>

int matrix_mul(int **, int, int, int **, int, int, int **);

int main()
{
    int **mat_a, **mat_b, **result;
    
    int r1,r2,c1,c2;
    
    //For 1st Matrix
    //printf("Enter number of rows : ");
    scanf("%d",&r1);
    
    //printf("Enter number of columns : ");
    scanf("%d",&c1);
    
    mat_a = calloc(r1,sizeof(int*));
   
    for ( int i = 0 ; i < r1 ; i++ )
    {
       mat_a[i]=calloc(c1,sizeof(int));                                             //allocating Dynamic Memory for Matrix_B
       
    }
    //printf("Enter values for %d x %d matrix :",r1,c1);                              //get the sizes of row,column
    
    for ( int i = 0 ; i < r1 ; i++)
    {
        for (int j = 0 ; j < c1 ; j++)
        {
            scanf("%d",&mat_a[i][j]);                                               //Enter the Elements of Matrix_A
        }
    }
    
    //For 2nd Matrix
    //printf("Enter number of rows : ");
    scanf("%d",&r2);
    
    //printf("Enter number of columns : ");
    scanf("%d",&c2);
    
    if ( c1 == r2)
    {
        mat_b = calloc(r2,sizeof(int*));
       
        for ( int i = 0 ; i < r2 ; i++ )
        {
           mat_b[i]=calloc(c2,sizeof(int));                                         //allocating Dynamic Memory for Matrix_B
           
        }
        //printf("Enter values for %d x %d matrix :",r2,c2);                          //get the sizes of row,column
        
        for ( int i = 0 ; i < r2 ; i++)
        {
            for (int j = 0 ; j < c2 ; j++)
            {
                scanf("%d",&mat_b[i][j]);                                           //Enter the Elements of Matrix_B
            }
        }
        result = calloc(r1, sizeof(int*));
            for (int i = 0; i < r1; i++)
            {    
                result[i] = calloc(c2, sizeof(int));                                //allocating Dynamic memory for Result
            }
            
            
            matrix_mul(mat_a, r1, c1, mat_b, r2, c2, result);                       //Calling the Multiplication Function

            // Print result
            printf("Product of two matrix:\n");
            for (int i = 0; i < r1; i++) 
            {
                for (int j = 0; j < c2; j++)
                {
                    printf("%d ", result[i][j]);
                }
                
                printf("\n");
            }
                
            
                                                                                    // Freeing memory
            for (int i = 0; i < r1; i++) 
            {
                free(mat_a[i]);
            }
            free(mat_a);
            
            for (int i = 0; i < r2; i++) 
            {
                free(mat_b[i]);
            }
            free(mat_b);
            for (int i = 0; i < r1; i++) 
            {
                free(result[i]);
            }
            free(result);
    }
    else
    {
        printf("Matrix multiplication is not possible");
    }
}

int matrix_mul(int **mat_a, int r1, int c1, int **mat_b, int r2, int c2,int **result)
{
    for (int i = 0 ; i < r1 ; i++ )
    {
        for (int j = 0 ; j < c2 ; j++ )
        {
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += mat_a[i][k] * mat_b[k][j];                          //Multiplicating the Matrix_A and Transpose of Matrix_B andstoring the result
            }
        }
    }
}
