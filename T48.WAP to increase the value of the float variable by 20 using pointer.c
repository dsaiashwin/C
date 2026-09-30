#include <stdio.h>
int cng_vlu(float*num);

int main()
{
    float num;
    scanf("%f",&num);
    cng_vlu( &num);
    printf("Age after increasing by 20 is %g",num);
}

int cng_vlu(float*num)
{
    *num+=20;   
}
