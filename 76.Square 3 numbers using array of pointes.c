#include <stdio.h>
void sq_arr( int ** ptr);

int main()
{
    int arr[3] = {10,20,30};   //Take 3 numbers in main functio
    
    int*ptr[1]={arr};       //ptr is array of pointers and storing address in array of pointers in ptr
    
    sq_arr(ptr);            //calling the function and passing ptr 
}
void sq_arr( int ** ptr)
{
    for ( int i = 0 ; i < 3 ; i++)
    {
        ptr[0][i] = ( ptr[0][i] * ptr[0][i] );
    }
    
    for ( int i = 0 ; i < 3 ; i++)
    {
        printf("%d ",ptr[0][i] );
    }
}
