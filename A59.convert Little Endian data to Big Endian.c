/*
Name : Sai Ashwin D
Date : 22 -04 - 2025
Description : to Convert data from Little Endian  to Big Endian
Sample Input :
Enter any number in Hexadecimal: ABCD
Sample Output : After conversion CDAB
*/

#include <stdio.h>
int main()
{
    int size,num;
    
    printf("Enter the size: ");
    scanf("%d",&size);
    
    if ( size == 2)                                         //Receiving input according to Size given by user
    {
        printf("Enter any number in Hexadecimal: ");
        scanf("%X",&num);
        
    }
    
    else if ( size == 4)
    {
        printf("Enter any number in Hexadecimal: ");
        scanf("%X",&num);
    }
    
        char temp;
        char* ptr = (char*)&num;                            //Type casting the address of Integer to char data type
        
        for (int i = 0 ; i < (size/2) ; i++)            //Swapping the bits to convert from Little Endian to Big Endian
        {
            temp = ptr[i];
            ptr[i] = ptr[(size-1)-i];
            ptr[(size-1)-i] = temp;
        }
            printf("After conversion %X",num);
}
