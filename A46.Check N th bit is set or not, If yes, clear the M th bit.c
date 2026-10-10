/*
Name : Sai Ashwin D
Date : 06-04-2025
Description : to check N th bit is set or not, If yes, clear the M th bit
Sample Input : 
Enter the number: 19
Enter 'N': 1
Enter 'M': 4

Sample Output : Updated value of num is 19 
*/
#include <stdio.h>
int main()
{
    int num,n,m;
    
    printf("Enter the number: ");
    scanf("%d", &num);
    
    printf("Enter 'N': ");
    scanf("%d", &n);

    printf("Enter 'M': ");
    scanf("%d", &m);
    
    if ( num & ( 1 << n) )              // checking if the Nth bit is set or not 
    {
        num = num & ( ~(1 << (m))  );   //updating the valueby setting Mth bit to 0
    }
    
    printf("Updated value of num is %d",num);
    
    
}
