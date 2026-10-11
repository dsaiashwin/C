/*
Read the N name from the user
Sort it in alphabetical order
Use 1st dynamic and 2nd static. Char (*name)[20]
No.of names should be dynamic and no.of characters should be static.
Allocate the memory dynamically for no.of names.
Test Case 1:
user@emertxe] ./sort

Enter the size: 5

Enter the 5 names of length max 20 characters in each
[0] -> Delhi
[1] -> Agra
[2] -> Kolkata
[3] -> Bengaluru
[4] -> Chennai

The sorted names are:
Agra
Bengaluru
Chennai
Delhi
Kolkata

Name : Sai Ashwin D
Date : 07-05-2025
Description : Sort and print the names
Sample Input : 
Enter the size: 5

Enter the 5 names of length max 20 characters in each
[0] -> Delhi
[1] -> Agra
[2] -> Kolkata
[3] -> Bengaluru
[4] -> Chennai

Sample Output : 
The sorted names are:
Agra
Bengaluru
Chennai
Delhi
Kolkata
*/

#include <stdio.h>
#include <stdlib.h>

void sort_names(char (*)[20], int);                         //Function Declaration

int main()
{
    int n;
    
    printf("Enter the size: ");
    scanf("%d",&n);
    
    char (*name)[20];
    
    name = malloc(n*sizeof(char[20]));
    
    printf("Enter the %d names of length max 20 characters in each\n",n);
    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%s",name[i]);                                //Reading the names
    }
    sort_names( name,  n);                                  //calling the function
    
    printf("The sorted names are: \n");
    for ( int t = 0 ; t < n ; t++ )
    {
        printf("%s\n",name[t]);                             //printing the output
    }
    free(name);
    
}

void sort_names(char (*name)[20], int n)                    //function definition
{   char temp[20];
    
   for ( int i = 0 ; i <n ; i++)                            
   {int flag = 0;
       for ( int j = i+1 ; j < n ; j++)
       {    
           for ( int k = 0 ; k < 20 ; k++)
           {
               if ( name[i][k] > name[j][k] )
               {
                   flag=1;
                   break;
               }
               else if (name[i][k] < name[j][k])            //checking for smaller strings in alphabetical order
               {
                   break;
               }
           
            }
            if (flag == 1)
            {   
                for ( int t = 0 ; t < 20 ; t++ )            //Swapping the strings
                { 
                    temp[t] = name[i][t];
                   name[i][t] = name[j][t];
                   name[j][t] = temp[t];
                   flag =0;       
                }
           }
       }
   }    
}
