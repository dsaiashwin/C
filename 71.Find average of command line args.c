#include <stdio.h>
#include <stdlib.h>
int main( int argc , char* argv[] )
{
    float sum = 0, avg = 0;
    int i = 1;
    
    while(argv[i])
    {
        sum += atoi(argv[i]);
        i++;
    }
    
    avg = sum / (argc-1);
    
    printf("Average: %f",avg);
}
