#include <stdio.h>
int main()
{
    int num,c=0;
    
    printf("Enter the number : ");
    scanf("%d",&num);
    
    for (int i = 0 ; i < 32 ; i++)
    {
        if (num & (1<<i) )
        {
            c+=1;
        }
    }
    printf("The count of set bits is %d",c);
}
