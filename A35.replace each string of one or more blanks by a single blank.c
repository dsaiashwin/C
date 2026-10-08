#include <stdio.h>

void replace_blank(char []);

int main()
{
    char str[500];
    
    printf("Enter the string with more spaces in between two words\n");
    scanf("%[^\n]", str);
    
    replace_blank(str);
    
    printf("%s\n", str);
}

void replace_blank(char*str)
{
    for (int i = 0 ; str[i+1] != '\0' ; i++)
    {
        int c = 0;
    
        if( (str[i] == ' ' && str[i+1] == ' ' ) || (str[i] == '\t' && str[i+1] == '\t') )
        {int r=i;
            while ( (str[i+c] == ' ' ) || (str[i+c] == '\t' ) )
            c+=1;
            
            while (str[i+c] != '\0')
            {
                str[i+1]=str[i+c];
                i++;
            }
        str[i+1]='\0';
        i=r;
        }
    }
}
