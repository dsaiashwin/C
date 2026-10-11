/*
Name : Sai Ashwin D
Date : 22-04-2025
Description : Variance calculation with dynamic arrays
Sample Input : 
Enter the 10 elements:
9
12
15
18
20
22
23
24
26
31
Sample Output : Variance is 40.000000
*/

#include <stdio.h>
#include <stdlib.h>
float variance(int *, int);

int main()
{
    int e=0;
    float res=0;
    printf("Enter the no.of elements : ");
    scanf("%d",&e);
    
    int* ptr = malloc(e*sizeof(int));
    
    printf("Enter the %d elements:",e);
    
    for (int i = 0 ; i < e ; i++)
    {
        scanf("%d",&ptr[i]);                    //Taking input of array Elements
    }
    
    res = variance(ptr, e);
    printf("Variance is %f",res);
}

float variance(int *p, int s)
{   
    int sum=0;
    float mean=0;
    
    for ( int i = 0 ; i < s ; i++)              //Calculating sum of array Elements and there by mean
    {
        sum+=p[i];  
    }
    mean = (float)sum / s;
    
    for ( int i = 0 ; i < s ; i++)              //calculating deviation and square of deviation
    {
        p[i] = p[i] - mean;
        
        p[i] = p[i] * p[i];
    }
    sum = 0 , mean = 0 ;                        //Calculating Varience of Array elements
    
    for ( int i = 0 ; i < s ; i++)
    {
        sum+=p[i];  
    }
    mean = (float)sum / s;
    
    return mean;
}
