/*
result = sum(4, 10, 20, 30, 40);
    result = sum(5, 10, 20, 30, 40, 50);
    result = sum(3, 15, 12, 13);
    Print the results of above function call
Output : 
 

Result = 100
Result = 150
Result = 40
  */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
int sum(int count, ...);

int main(int argc , char* argv[])
{
    int result;
    
    result = sum(4, 10, 20, 30, 40);
    printf("Result = %d\n",result);
    
    result = sum(5, 10, 20, 30, 40, 50);
    printf("Result = %d\n",result);
    
    result = sum(3, 15, 12, 13);
    printf("Result = %d\n",result);
}

int sum(int count, ...)
{
    va_list ap;                                     //initializing Argument pointer with list
    va_start( ap , count);                          //making the pointer to point at starting i.e last known argument
    int total=0;
    for (int i = 0 ; i < count ; i++ )
    {
        total += va_arg( ap , int );                //getting present unknown argument value and moving to next argument
    }
    va_end( ap );                                   //Deallocating the space
    return total;
}
