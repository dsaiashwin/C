#include <stdio.h>
#include <string.h>
struct student
{
    int id;
    char name[20];
};

int main()
{
    struct student stud_list[2];
    stud_list[0].id=100;
    strcpy(stud_list[0].name,"Bhaskar");
    

    printf("Enter student 2 details\n");
    scanf("%d %s",&stud_list[1].id,stud_list[1].name);
    
    printf("Student 1 elements :\n");
    printf("Id :%d name: %s\n",stud_list[0].id,stud_list[0].name);
    
    printf("Student 2 elements :\n");
    printf("Id :%d name: %s\n",stud_list[1].id,stud_list[1].name);
}
