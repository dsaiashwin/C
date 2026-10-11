#include <stdio.h>
int main(int argc, char* argv[] )
{
    printf("List of command line arguments are:\n");
    
    int i = 0;
    
    while( argv[i] != NULL )
    {
        printf("%s\n",argv[i]);
        i++;
    }
    return 0;
}
