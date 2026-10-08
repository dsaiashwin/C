/*
Name : Sai Ashwin D
Date :
Description : Implement consecutive NRPS of length n using k distinct character
Sample Input : 
Enter the number characters C : 3
Enter the number characters N : 6
Enter 3 distinct characters : a b c
Sample Output : Possible NRPS is abcbca
*/
#include <stdio.h>

void nrps(char [], int, int);

int main()
{
    int c=0,n=0;
    
    //read the input from the user
    printf("Enter the number characters C : ");
    scanf("%d",&c);                                 //taking user input for c
    
    printf("Enter the number characters N : ");
    scanf("%d",&n);                                 //taking user input for n
    
    char a[c];
    
    printf("Enter 3 distinct characters : ");
    for (int i = 0 ; i < c ; i++)
    {
        scanf(" %c", &a[i]);
    }
    
    for (int i = 0 ; i < c ; i++)
    {
        for (int j = i+1 ; j < c ; j++)
        {
            if (a[i] == a[j])
            {
                printf("Enter distinct characters");
                return 0;
            }
        }
    }
    //function call to pass input to the function
    nrps(a, c, n);
    
}

void nrps(char*a, int c, int n) //defining NRPS function
{   int j = 0;
    char temp;
    
    while ( j < n)          //for printing the NRPS characters
    {
        for (int i = 0 ; i < c ; i++)
        {
            printf("%c",a[i]);
            j++;
        }
        //swapping logic to change the order of characters
        temp = a[0];
        a[0] = a[1];
        a[1] = temp;
    }
}
