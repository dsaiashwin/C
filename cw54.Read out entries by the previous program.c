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
    FILE *fptr = fopen("tudent_record_entry.bin","rb");
    if (fptr == NULL )
    {
        printf("Error opening file");
        return 0;
    }
    int n = 2;
    struct Student_record student[n];
    float avg_math,avg_phy,avg_che;
    
    fread(student , sizeof(struct Student_record) ,n,fptr);
    fread(&avg_math , sizeof(float), 1,fptr);
    fread(&avg_phy , sizeof(float), 1,fptr);
    fread(&avg_che , sizeof(float), 1,fptr);
    fclose(fptr);
    
    printf("--------------------------------------------------\n");
    printf("Name\tMaths\tPhysics\tchemistry\n");
    printf("--------------------------------------------------\n");
    for (int i = 0 ; i < n; i++)
    {
        printf("%s %d %d %d\n",student[i].name,student[i].Maths_marks,student[i].Phy_marks,student[i].Chem_marks);
    }
    printf("\n--------------------------------------------------\n");
    printf("Average\t%f\t%f\t%f\n",avg_math,avg_phy,avg_che);
    printf("\n--------------------------------------------------\n");
    
}
