#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* ptr=malloc(15);
    
    scanf("%[^\n]",ptr);
    
    printf("%s",ptr);
    
    free(ptr);
}
