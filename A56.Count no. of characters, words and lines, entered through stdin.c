/*
Name : Sai Ashwin D
Date : 19-04-2025
Description : To count no. of characters, words and lines, entered through stdin
Sample Input : 
Hello world
Dennis Ritchie
Linux
Sample Output : 
Character count : 39
Line count : 3
Word count : 5
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char ch;
    int char_count = 0 ,word_count = 0 ,line_count = 0 ;
    int flag = 0;
    while ( (ch = getchar()) != EOF )
    {                                                       /*Incrementing the character count if entered or encountered in not EOF */
        char_count+=1;                                      
        
        if ( ch == ' ' || ch == '\n' || ch == '\t')         /*Incrementing the word count if entered/encountered is space or */
        {                                                   /*new line or tabspace and checking that they are not repeated in next character */
            if (flag == 0)
            {
                word_count += 1;
            }
        }
        
        else
        {
            flag = 0;
        }
        
            
        if (ch == '\n' )
        {
          line_count += 1;                                  /*Incrementing the Line count if entered is new line character */
        }
    }
    printf("\nCharacter count : %d\n",char_count);
    printf("Line count : %d\n",line_count);
    printf("Word count : %d\n",word_count);
}
