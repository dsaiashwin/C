#include <stdio.h>

void reverse_recursive(char str[], int ind, int len);

int main()
{
    char str[30];
    
    
    //printf("Enter any string : ");
    scanf("%[^\n]", str);
    
    int l = 0;
    
    while (str[l] != '\0')
    l++;
    
    reverse_recursive(str, 0, l);
    
    printf("Reversed string is %s\n", str);
}

void reverse_recursive(char str[], int ind, int len)
{
    char temp;
    if (ind <= len/2-1)
    {
        temp = str[ind];
        str[ind]= str[len-ind-1];
        str[len-ind-1] = temp;
        reverse_recursive(str, ind+1, len);
    }

}
