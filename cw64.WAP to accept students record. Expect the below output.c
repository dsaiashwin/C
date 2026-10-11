/*
Description : 
user@user:~]./students_record.out
Enter the number of students : 2 
Enter name of the student : Tingu 
Enter P, C and M marks : 23 22 12   
Enter name of the student : Pingu 
Enter P, C and M marks : 98 87 87 
-------------------------------------------------------------- 
Name Maths Physics Chemistry        
-------------------------------------------------------------- 
Tingu 12 23 22          
Pingu 87 98 87          
-------------------------------------------------------------- 
Average          49.50            60.50            54.50       
-------------------------------------------------------------- 
*/
#include <stdio.h>

struct Students
{
    char name[25];
    int physics;
    int chemistry;
    int maths;
};

int main()
{
    int n;
    float m_avg,p_avg,c_avg;
    
    printf("Enter the number of students : ");
    scanf("%d",&n);
    
    struct Students s[n];
    
    for ( int i = 0 ; i < n ; i++ )
    {
        printf("Enter name of the student : ");
        scanf("%s",s[i].name);
        
        printf("Enter P,C and M marks : ");
        scanf("%d %d %d",&s[i].physics,&s[i].chemistry,&s[i].maths);
        
        m_avg += s[i].maths;
        p_avg += s[i].physics;
        c_avg += s[i].chemistry;
    }
        m_avg /= n;
        p_avg /= n;
        c_avg /= n;
    
    
    printf("\n-----------------------------------------------------\n");
    printf("Name \t Maths \t Physics \t Chemistry\n");
    
    for ( int i = 0 ; i < n ; i++ )
    {
        printf("%s \t",s[i].name);
        
        printf(" %d \t %d \t %d\n",s[i].maths,
        s[i].physics,s[i].chemistry);
    }
    printf("\n-----------------------------------------------------\n");
    printf("Average \t ");
    printf("%.2f \t %.2f \t %.2f \t",m_avg,p_avg,c_avg);
    printf("\n-----------------------------------------------------\n");
}
 
