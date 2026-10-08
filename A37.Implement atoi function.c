/*
Name : Sai Ashwin D
Date :28-03-2025
Description : Implement atoi function
Sample Input : Enter a numericstring: 12345
Sample Output : String to integer is 12345
*/
#include <stdio.h>

int my_atoi(const char []);//declaration of atoi function

int main()
{
    char str[20];
    
    printf("Enter a numeric string : ");
    scanf("%s", str);//getting input from user
    
    printf("String to integer is %d\n", my_atoi(str));//passing string to my_atoi function
}

int my_atoi(const char arr[])
{   int res=0;
    
    if (arr[0] >= '0' && arr[0] <= '9') //checking that is first character of string is a digit or operator
    {   int i = 0;
        while( arr[i] >= '0' && arr[i] <= '9' && arr[i] != '\0' )
        {
           res = (res*10)+ (arr[i] - '0') ;//converting string to int
           i++;
        }
        return res;
    }
    else if (arr[0] == '+' || arr[0] == '-') //if the first character is an operator
    {
        int i = 1;
        while( arr[i] >= '0' && arr[i] <= '9' && arr[i] != '\0' )
        {
           res = (res*10)+ (arr[i] - '0') ;
           i++;
        }
        if (arr[0] == '+')
        return res;
        
        else 
        return -res;
    }
    
    else //if the first character is any other
    return 0;
}
