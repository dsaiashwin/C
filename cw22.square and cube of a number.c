#include <stdio.h>
void sq_cu(int*num);

int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    sq_cu(&n);
}
void sq_cu(int*num)
{
    printf("Square is %d\n",(*num * *num));
    printf("Cube is %d",(*num * *num * *num));
}
