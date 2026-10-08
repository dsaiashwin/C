/*
Name : Sai Ashwin D
Date :28-03-2025
Description : Implement itoa function
Sample Input : Enter a numericstring: 12345
Sample Output : Integer to String is 12345
*/
#include <stdio.h>

void itoa(int num, char str[]);//declaring the itoa function

int main()
{
    int num;
    char str[10];
    //taking integer input from user
    printf("Enter the number:");
    if (scanf("%d", &num) != 1 ) //validating if it is a valid numeric input or not
    {
        printf("Integer to string is 0");
        return 0;
    }
    
    
    itoa(num, str); // passing number and string to itoa function
    
    printf("Integer to string is %s", str);
}

void itoa(int num, char str[])//defining itoa function

{int i = 0;
    char temp;
    if ( num < 0 || num > 0) // checking that num isnot equal to 0
    {
        int neg = 0,l = 0;
            if (num < 0 ) //checking if the num is 0
            {   neg=1;
                num=-num;
            }
            while (num != 0) //converting number to string format
            {   
                str[i]= (num%10 + '0');
                num=num/10;
                i++;
            }
            
            if (neg == 1) // ensuring if the number is negative and adding "-" sign
            {             // and modifying the string length accordingly
                str[i] = '-';
                str[i+1] = '\0';
                l = i+1;
            }
            
            else //if not negative then modifying the string length
            {
                str[i] = '\0';
                l = i;
            }
            for (int i = 0 ; i < l/2 ; i++) // reversing the string
            {
                temp = str[i];
                str[i] = str[l-i-1] ;
                str[l-i-1] = temp;
            }
        
    }
    
    
}
