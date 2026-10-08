#include <stdio.h>

int pangram(char []);

int main()
{
    char str[100];
    
    printf("Enter the string: ");
    scanf("%[^\n]",str);
    
    if ( pangram(str) )
    printf("The Entered String is a Pangram String");
    
    else 
    printf("The Entered String is not a Pangram String");
}

int pangram(char str[])
{
    int i=0,c=0;
    int arr[26]={0};
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            arr[ str[i] - 'A']=1;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            arr[str[i] - 'a']=1;
        }
        i++;
    }

    for ( i = 0 ; i <= 25 ; i++)
    {
        if (arr[i] == 1)
        c+=1;
    }
    if (c==26)
    return 1;
    
    else 
    return 0;
}
