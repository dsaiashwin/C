#include <stdio.h>

struct Student_record
{
    char name[20];
    int Maths_marks;
    int Phy_marks;
    int Chem_marks;
};

int main()
{
    int n;
    printf("Enter the number of students : ");
    scanf("%d",&n);
    
    struct Student_record s[n];
    int avg_marks[3];
    int m=0,p=0,c=0;
    for ( int i = 0 ; i < n ; i++)
    {
        printf("Enter name of the student :");
        scanf("%s",s[i].name);
        
        printf("Enter P,C and M marks :");
        scanf("%d %d %d",&s[i].Phy_marks,&s[i].Chem_marks,&s[i].Maths_marks);
        
        m += s[i].Maths_marks;
        p += s[i].Phy_marks;
        c += s[i].Chem_marks;
    }
    
    float avg_math = (float) m/n;
    float avg_phy = (float) p/n;
    float avg_che =(float) c/n;
    
    FILE *fptr = fopen("student_record_entry.bin","wb");
    if (fptr == NULL)
    {
        printf("cant open file");
    }
    fwrite(s,sizeof(struct Student_record), n ,fptr);
    fwrite(&avg_math,sizeof(float),1,fptr);
    fwrite(&avg_phy,sizeof(float),1,fptr);
    fwrite(&avg_che,sizeof(float),1,fptr);
    fclose(fptr);
    
    printf("Student records with averages are saved successfully in Binary file\n");  
}
