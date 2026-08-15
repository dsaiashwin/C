#include <stdio.h>

int is_xdigit(int);

int is_xdigit(int ch)
{
    if (('a' <= ch && 'f' >= ch ) || ('A' <= ch && 'F' >= ch) || ('0' <= ch && '9' >= ch))
    return 1;
    else 
    return 0;
}

int main()
{
    char ch;
    short ret;
    
    printf("Enter a character: ");
    scanf("%c", &ch);
    
    ret = is_xdigit(ch);
    
    /* Based on the return value of the function print the message */
    
    
    if (ret == 1)
    printf("Entered character is an hexadecimal digit");
    else if (ret == 0)
    printf("Entered character is not an hexadecimal digit");
}

