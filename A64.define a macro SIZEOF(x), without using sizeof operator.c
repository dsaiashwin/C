/*
Name : Sai Ashwin D
Date : 16-04-2025
Description : To define a macro SIZEOF(x), without using sizeof operator
Sample Input : None
Sample Output : 

Size of int : 4 bytes
Size of char : 1 byte
Size of float : 4 bytes
Size of double : 8 bytes
Size of unsigned int : 4 bytes
Size of long int : 8 bytes
*/
#include <stdio.h>
#define SIZEOF(X) (char*)(&X+1) - (char*)(&X) //MACRO is used to get the sizeof() variable with out using sizeof() operator

int main()
{
    int var1 = -8;
    printf("Size of int : %lu bytes\n",SIZEOF(var1));
    
    char var2 = 'a';
    printf("Size of char : %lu bytes\n",SIZEOF(var2));
    
    float var3 = 3.14;
    printf("Size of float : %lu bytes\n",SIZEOF(var3));
    
    double var4 = 7.32;
    printf("Size of double : %lu bytes\n",SIZEOF(var4));
    
    unsigned int var5 = 8;
    printf("Size of unsigned int : %lu bytes\n",SIZEOF(var5));
    
    signed int var6 = 10;
    printf("Size of signed int : %lu bytes\n",SIZEOF(var6));
        
    long int var7 = 10;
    printf("Size of long int : %lu bytes\n",SIZEOF(var7));
    
    long long int var8 = 2;
    printf("Size of long long int : %lu bytes\n",SIZEOF(var8));
    
    short var9 = 1024;
    printf("Size of short : %lu bytes\n",SIZEOF(var9));
    
    long double var10 = 4096;
    printf("Size of long double : %lu bytes\n",SIZEOF(var10));
    
    return 0;
}
