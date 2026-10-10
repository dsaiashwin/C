#include <stdio.h>
int main()
{
    int n=0,s=0;
    printf("Enter the number:\n");
    scanf("%d",&n);
    printf("Enter the number of shifts to perform: ");
    scanf("%d",&s);
    
    printf("After shifting to the right,the output is : %d\n", n>>s);
    printf("After shifting to the left,the output is : %d", n<<s);
}
