/*
Name : Sai Ashwin D
Date :
Description : find and print all the possible combinations of given string
Sample Input : Enter a string: abc
Sample Output : All possible combinations of given string :
abc
acb
bca
bac
cab
cba
*/

#include<stdio.h> 

void combination(char [],int ,int );
int my_strlen(char []);
int distinct(char *str ,int n );
void swap (char* i ,char* start );

int main()

{
        char str[100];
        int n;
        int res = 1;
        printf("Enter a string: ");
        scanf("%100[^\n]",str); 
        
        n = my_strlen(str);  //calling string length function
        
        res = distinct(str,n); //verifying if the characters are distinct or not
        
        if (res == 0)
        {
            printf("please enter distinct characters.");
            return 0;
        }
        
        combination(str,0,n-1); // calling combination function  
        
        return 0;
}

int my_strlen(char str[])
{
    int i = 0,l = 0;
    
    while ( str[i] !=0 )
    {
        l++;    
        i++;
    }
    return l;          //returning length 
    
}

int distinct(char * str ,int n)
{
    for ( int i = 0 ; i < n ; i++)
    {
        for (int j = i+1 ; j < n ; j++)
        {
            if (str[i] == str[j])
            {
                return 0;
            }
        }
    }
}

void combination(char str[],int start ,int end)
{
    char temp;
    
    if (start == end)
    printf("%s ",str);   //printing the resulting string if start == end
    
    else
    {
        for (int i = start ; i <= end ; i++)
        {
            swap(str+i , str+start);
            
            combination( str, start +1 , end );
            
            swap(str+i , str+start);
        }
    }
}

void swap(char* i, char *start)
{
    char temp;
    temp = *i;
    *i = *start;
    *start = temp;
}
