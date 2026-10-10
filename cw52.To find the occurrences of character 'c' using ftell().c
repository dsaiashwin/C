#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr;
    char ch;
    int count = 0;
    
    fptr = fopen("text.txt","r");
    if (fptr == NULL )
    {
        printf("Error: Can't open the file\n");
        return 1;
    }
    
    while ( ch = fgetc(fptr) != EOF )
    {
        int pos = ftell(fptr);
        if ( ch == 'c')
        {
            count++;
            printf("C is found at %d\n",pos-1);
        }
    }
    
    fclose(fptr);
    return 0;
}
