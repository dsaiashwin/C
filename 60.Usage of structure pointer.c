/*
Name : Sai Ashwin D
Date :
Description : Usage of structure pointer
Sample Input : 101,Hari
Sample Output : 101 Hari
*/
#include <stdio.h>

struct student
{
    int id;
    char name[20];
};

int main()
{
    struct student s1={101,"Hari"};
    struct student *ptr=&s1;
    
    printf("%d\n",ptr->id);
    printf("%s\n",(*ptr).name);
    
}
