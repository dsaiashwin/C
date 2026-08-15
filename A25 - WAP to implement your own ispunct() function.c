#include <stdio.h>

int my_ispunct(int);

int my_ispunct(int ch)
{
    if (('a' <= ch && 'z' >= ch ) || ('A' <= ch && 'Z' >= ch  ) || ('0' <= ch && '9' >=ch))
    return 0;
    
    else 
    return 1;
}

int main()
{
    char ch;
    int ret;
    
    printf("Enter the character:");
    scanf("%c", &ch);
    
    ret = my_ispunct(ch);
    /*
        Based on return value, print whether ch is lower case alphabet or not
    */
    if (ret == 1)
    printf("Entered character is punctuation character");
    else if (ret==0)
    printf("Entered character is not punctuation character");
}
