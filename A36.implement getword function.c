#include <stdio.h>

int getword(char str[]);

int main()
{
        int len = 0;
	    char str[100];

		printf("Enter the string : \n");
		scanf(" %[^\n]", str);

		len = getword(str);

        printf("You entered %s and the length is %d\n", str, len);
}
int getword(char*s)
{int l=0;
    for ( int i = 0 ; s[i] != ' ' && s[i] != '\0' ; i++)
    {
        l++;
    }
    s[l]='\0';
    return l;
}
