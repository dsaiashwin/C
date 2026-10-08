/*
Name : Sai Ashwin D
Date :
Description : Implement my_strtok function
Sample Input : 
Enter the string  : Bangalore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
Enter the delimeter : ;./-:
Sample Output : 
Bangalore
Chennai
Kolkata
Delhi
Mumbai
*/
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

char *my_strtok(char str[], const char delim[]);

int main()
{
    char str[100], delim[50];
    
    printf("Enter the string  : ");  //Reading input string from user
    scanf("%s", str);
    
    __fpurge(stdout);
 
    printf("Enter the delimeter : ");  //Reading delimeters in string from user
    scanf("\n%s", delim);
    __fpurge(stdout);
    
    char *token = my_strtok(str, delim);  //calling my_strtok function for first time
    printf("Tokens :\n");
    
    while (token)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);  //calling my_strtok function for consecutive runs from 2nd time
    }
}

char *my_strtok(char*str, const char*delim)
{
    static int i ;
    static char*dup;
    if (str != NULL)  //if str is not null then assign the str to dup as backup
    {   
        dup=str;
        i = 0;
    }
    while (dup[i] != '\0' && strchr(delim, dup[i]) != NULL)  //to skip consecutive delimeters
    {
        i++;
    }
    int start = i;
    while (dup[i] != '\0')
    {
        int j = 0;
        
        while (delim[j] != '\0')
        {
            if ( dup[i] == delim[j] )
            {   dup[i] = '\0';
                if (start != i)     // returning  string after skiping consecutive delimeters
                {
                    i++;
                    
                    return (&dup[start]);
                }
                else               // to skip consecutive delimeters
                {
                    start++;
                    i++;
                }
            break;    
            }
            j++;
        }
        i++;
    }
    if ( dup[start] != '\0') //if last token in str then return it
    {
        return (&dup[start]);
    }
    
    else
    return NULL;
}
