#include <stdio.h>

int main()
{
    int num=0x12345678;
    char*ptr=&num;
    
    if (*ptr == 0x78)
    printf("It is little endian system");
    
    else
    printf("It is big endian system");
    
}
