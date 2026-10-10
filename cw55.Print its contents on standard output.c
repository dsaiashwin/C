#include<stdio.h>
int main()
{
    FILE *fptr = fopen("text.txt","w");
    
    if (fptr == NULL)
    {
        printf("Can't open the file");
        return 0;
    }
        //writing to file
    fprintf(fptr,"Hi, welcome to C course in Emertxe");
    fclose(fptr);
    
        //reading the file
    fptr = fopen("text.txt","r");
    if (fptr == NULL)
    {
        printf("Can't open the file");
        return 0;
    }
    char ch;
    while ((ch = fgetc(fptr)) != EOF )
    {
        printf("%c",ch);
    }
    fclose(fptr);

}
