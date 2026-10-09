/*
user@user:~]./students_record.out
Enter the number of students : 2 
Enter name of the student : Tingu 
Enter P, C and M marks : 23 22 12   
Enter name of the student : Pingu 
Enter P, C and M marks : 98 87 87 
------------------------------------------------------------- 
Name Maths Physics Chemistry        
-------------------------------------------------------------- 
Tingu 12 23 22          
Pingu 87 98 87          
-------------------------------------------------------------- 
Average          49.50            60.50            54.50       
-------------------------------------------------------------- 
user@user:~]
*/
#include <stdio.h>
#include <string.h>
struct student
{
    char name[10];
    int p;
    int c;
    int m;
};

int main()
{
    int n;
    
    
    printf("Enter the number of students :");
    scanf("%d",&n);
    
    struct student s[n];
    
    for ( int j = 0 ; j < n ; j++)
    {
        printf("Enter name of the Student :");
        scanf("%s",s[j].name);
        
        printf("Enter P,C and M marks : ");
        scanf("%d %d %d",&s[j].p,&s[j].c,&s[j].m);
    }
    
    printf("\n---------------------------------------------------------------\n");
    printf("\nName\tMaths\tPhysics\tChemistry\n");
    printf("\n---------------------------------------------------------------\n");
        for ( int j = 0 ; j < n ; j++)
    {
        printf("\n%s\t%d\t%d\t%d\n",s[j].name,s[j].m,s[j].p,s[j].c);
    }
    
    printf("\n---------------------------------------------------------------\n");
    float avg_p = 0, avg_c = 0 , avg_m=0;
    for (int j = 0 ; j < n; j++)
    {
        avg_p+=s[j].p;
        avg_m+=s[j].m;
        avg_c+=s[j].c;
        
    }
    avg_p/=n;
    avg_c/=n;
    avg_m/=n;
    printf("\nAverage\t%.2f\t%.2f\t%.2f\n",avg_m,avg_p,avg_c);
    printf("\n---------------------------------------------------------------\n");
}
