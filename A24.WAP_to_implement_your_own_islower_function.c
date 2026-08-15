#include <stdio.h>

int my_islower(int);

int my_islower(int ch)
{
  if ('a' <= ch  && 'z' >= ch)
  return 1;
  
  else
  return 0;
}

int main()
{
    char ch;
    int ret;
    
    printf("Enter the character:");
    scanf("%c", &ch);
    
    ret = my_islower(ch);
    /*
        Based on return value, print whether ch is lower case alphabet or not
    */
    if (ret==1)
    printf("Entered character is lower case alphabet");
    else if (ret==0)
    printf("Entered character is not lower case alphabet");
    
}
