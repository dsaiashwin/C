#include <stdio.h>

struct acc_mem
{
    char c;
    int n;
    float f;
    char name[20];
};

int main()
{
    struct acc_mem sma;
    
    //printf("Enter the details of c, n, f, name:\n");
    scanf("%c %d %f %s\n",&sma.c,&sma.n,&sma.f,sma.name);
    
    //printf("The details are: \n");
    printf("%c %d %g %s",sma.c,sma.n,sma.f,sma.name);
}
