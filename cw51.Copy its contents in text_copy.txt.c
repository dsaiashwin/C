#include <stdio.h>
int main()
{
    FILE *sfile = fopen("Text.txt","r");
    
    if ( sfile == NULL )
    {
        printf("Can't copy Source file\n");
        return 0;
    }
    
    FILE *dfile = fopen("text_copy.txt","w");
    
    if ( dfile == NULL )
    {
        printf("Can't copy Destination file\n");
        return 0;
    }
    
    char ch;
    
    while ((ch = (fgetc(sfile)) != EOF ))
    {
        putc(ch,dfile);
    }
    
    fclose(sfile);
    fclose(dfile);
    
    return 0;
    
}
