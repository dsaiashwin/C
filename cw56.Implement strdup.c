#include <stdio.h>
#include <stdlib.h> //for dynamic allocation functions
#include <string.h> //for string functions

char* my_strdup(char*);

int main()
{
    char str[30];
    
    printf("Enter the string : ");
    scanf("%[^\n]",str);
    
    char*cptr=my_strdup(str);
    
    printf("The dupliicated string is : %s ",cptr);
    
    free(cptr);
}
char* my_strdup(char*string)
{
    int size=0;
    size=strlen(string)+1;
    
    char * dup_str = malloc(size);
    
    if (dup_str == NULL)
    {
        printf("Failed to allocate memory dynamically");
        return NULL;
    }
    
    else
    {
        strcpy(dup_str,string);
    }
}
