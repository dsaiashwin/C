#include <stdio.h>
void pri_arr_ele(int*ptr, int s);
int main()
{
    int arr[5]={10,20,30,40,50};
    pri_arr_ele(arr, 5);
}
void pri_arr_ele(int*ptr, int s)
{   
    int i=0;
    while (i<s)
    {
        printf("%d, ",*(ptr+i));
        i++;
    }
}
