/*
Name : Sai Ashwin D
Date : 16-04-2025
Description : To define a macro swap (t, x, y) that swaps 2 arguments of type t
Sample Input : 
Enter you choice : 1

Enter the str1 : How are you!
Enter the str2 : Hi Hello


Sample Output : 

str1 : Hi Hello
num2 : How are you!
*/
#include <stdio.h>
#include <stdlib.h>
                                                //Defining Macro
#define SWAP(t,x,y) \
{                   \
    t temp = x;     \
    x = y;          \
    y = temp;       \
}                   

int main()
{
    int choice;                                     //Asking for User choiceof Datatype
    
    printf("\n1. Int\n");
    
    printf("2. char\n");
    
    printf("3. short\n");
    
    printf("4. float\n");
    
    printf("5. double\n");
    
    printf("6. string\n");
    
    printf("\nEnter you choice : ");
    scanf("%d",&choice);
    
    switch (choice)
    {
       
    
        case 1:                                         //for Integer
        {
            int var1,var2;
            
            printf("\nEnter the num1 : ");
            scanf("%d", &var1);
            printf("\nEnter the num2 : ");
            scanf("%d", &var2);
            
            SWAP(int,var1,var2);                        //using MACRO
            
            printf("\nAfter Swapping : \n");
            printf("num1 : %d\n", var1);
            printf("num2 : %d\n", var2);
            break;
        }
        
        case 2:                                         //for Character
        {
            char var1,var2;
            
            printf("\nEnter the char1 : ");
            getchar();
            scanf("%c", &var1);
            printf("\nEnter the char2 : ");
            getchar();
            scanf("%c", &var2);
            
            SWAP(char,var1,var2);                       //using Macro
            
            printf("\nAfter Swapping : \n");
            printf("char1 : %c\n", var1);
            printf("char2 : %c\n", var2);
            break;
        }
        
        case 3:                                         //for Short Integer
        {
            short int var1,var2;
            
            printf("\nEnter the short num1 : ");
            scanf("%hd", &var1);
            
            printf("\nEnter the short num2 : ");
            scanf("%hd", &var2);
            
            SWAP(short int,var1,var2);                  //using Macro
            
            printf("\nAfter Swapping : \n");
            printf("short num1 : %hd\n", var1);
            printf("short num2 : %hd\n", var2);
            break;
        }
        
        case 4:                                         //for Float
        {
            float var1,var2;
            
            printf("\nEnter the float num1 : ");
            scanf("%f", &var1);
            
            printf("\nEnter the float num2 : ");
            scanf("%f", &var2);
            
            SWAP(float,var1,var2);                      //using Macro
            
            printf("\nAfter Swapping : \n");
            printf("float num1 : %f\n", var1);
            printf("float num2 : %f\n", var2);
            break;
        }
        
        case 5:                                         //for Double
        {
            double  var1,var2;
            
            printf("\nEnter the double1 : ");
            scanf("%lf", &var1);
            
            printf("\nEnter the double2 : ");
            scanf("%lf", &var2);
            
            SWAP(double,var1,var2);                     //using Macro
            
            printf("\nAfter Swapping : \n");
            printf("double1 : %lf\n", var1);
            printf("double2 : %lf\n", var2);
            break;
        }
        
        case 6:                                         // for String
        {
            char* str1 = malloc(20);
            char* str2 = malloc(20);
            
            printf("\nEnter the str1 : ");
            getchar();
            scanf("%[^\n]", str1);
            
            printf("\nEnter the str2 : ");
            getchar();
            scanf("%[^\n]", str2);
            
            SWAP(char*,str1,str2);                      //using Macro
            
            printf("\nAfter Swapping : \n");
            printf("str1 : %s\n", str1);
            printf("str2 : %s\n", str2);
            break;
        }
        
        
        
    }
}
