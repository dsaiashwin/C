/*
In recreational mathematics, a magic square is an arrangement of distinct numbers (i.e. each number is used once), usually integers, in a square grid, where the numbers in each row, and in each column, and the numbers in the main and secondary diagonals, all add up to the same number
A magic square has the same number of rows as it has columns, and in conventional math notation, "n" stands for the number of rows (and columns) it has. Thus, a magic square always contains n2 numbers, and its size (the number of rows [and columns] it has) is described as being "of order n".
Example: if n = 3, the magic square
      8      
      1     
      6     
      3     
      5     
      7     
      4     
      9     
      2     
Read an odd number n from user.
Do error checking.
Check the number is odd or not.
If not, continue step a.
Create an n X n matrix.
Insert 1 to (n * n) numbers into matrix.
Arrange the numbers in such a way that, adding the numbers in any direction, either row wise column wise or diagonal wise, should result in same answer.
Allocate the memory dynamically using calloc.

Test Case 1:
user@emertxe] ./magic_square
Enter a number: 3
8      1      6
3      5      7
4      9      2

Test Case 2:
Enter a number: 6
Error : Please enter only positive values
*/
/*
Name : Sai Ashwin D
Date : 23-04-2025
Description : To generate a n*n magic square
Sample Input : Enter a number: 5
Sample Output : 
17 24 1 8 15                                                                    
23 5 7 14 16                                                                    
4 6 13 20 22                                                                    
10 12 19 21 3                                                                   
11 18 25 2 9 
*/

#include <stdio.h>
#include <stdlib.h>
void magic_square(int **, int);

int main()
{
    int n;
    
    //printf("Enter a number: ");
    scanf("%d",&n);
    
    if ( n % 2 != 0 )
    {
       int**ptr;
       
       ptr = calloc(n,sizeof(int*));
       
       for ( int i = 0 ; i < n ; i++ )
       {
           ptr[i]=calloc(n,sizeof(int));                                            //allocating DMA for array
           
       }
       
       magic_square(ptr, n);
       
       free(ptr);
       for (int i = 0 ; i < n ; i++)
       {
            free(ptr[i]);
       }
    }
    else
    {
        printf("Error : Please enter only positive odd numbers");
    }
}
void magic_square(int **ptr , int n)
{
    int row=0,col=0;
    for ( int i = 1 ; i <= (n*n) ; i++)
    {   
        if ( i == 1)                                                                //if it was the first Element
        {
            row = 0,col=n/2;
            ptr[row][col] = i;
        }
                                                                                    //go to before row of current element and next column of current element modify value if new position is 0 
        else if (( row-1 >= 0 && col+1 <= n-1 ) && ( ptr [row-1][col+1] == 0 ) )                
        {
            row -=1,col += 1;
            ptr[row][col] = i;
        }
                                                                                    //go to before row of current element and next column of current element modify value if new position is not 0
        else if ( ( row-1 >= 0 && col+1 <= n-1 ) && ( ptr [row-1][col+1] != 0 ) )               
        {   
            row += 1;
            ptr[row][col] = i;
        }
                                                                                    //if before row of current element is not present and next column of current element is present and new position is 0
        else if ( ( row-1 < 0 ) && (col+1 <= n-1) && ( ptr [n-1][col+1] == 0) )                 
        {
            row = n-1,col += 1;
            ptr[row][col] = i;
        }
                                                                                    //if there exists before row of current element but next column of current element not present and the new position is 0
        else if ( ( row-1 >= 0) &&  ( col+1 > n-1 ) && ( ptr [row-1][0] == 0) )                
        {   
            col = 0,row -= 1;
            ptr [row][col] = i;
        }
        
        else if ( ( row-1 < 0) && ( col+1 > n-1 ) && ( ptr [n-1][0] == 0) )        //if the above row of current element doesn't exist and nextcolumn of current element exits also new position is 0             
        {   
            col = 0,row =n-1;
            ptr [row][col] = i;
        }
                                                                                    //if  before row and next column of current element doesn't exist also and new position is not empty
        else if ( ( row-1 < 0) && ( col+1 > n-1 ) && ( ptr [n-1][0] != 0) && ( ptr [row+1][col] == 0))   
        {
            row += 1;
            ptr [row][col] = i;
        }
        
    }
    
    for ( int r = 0 ; r < n ; r++ )
    {
        for ( int c = 0 ; c < n ; c++ )
        {
            printf("%d ",ptr[r][c]);
        }
        printf("\n");
    }
} 
