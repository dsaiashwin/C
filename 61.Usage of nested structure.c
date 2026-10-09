#include <stdio.h>

struct Address
{
    char state[20];
    int zip_code;
};

struct Student
{
    int id;
    char name[20];
    struct Address addr;
};

int main()
{
    struct Student stud1 = {101,"Sai Ashwin", {"Andhra",530001}};
    
    struct Student stud2;
    
    printf("Enter Id, name, State, zip_code for student 2 \n");
    scanf("%d %s %s %d", &stud2.id, stud2.name, stud2.addr.state, &stud2.addr.zip_code);
    
    printf("Student 1 details are: \n");
    printf("Id:%d, Name:%s, State:%s, zip code:%d\n", stud1.id, stud1.name, stud1.addr.state, stud1.addr.zip_code);
    
    printf("Student 2 details are: \n");
    printf("Id:%d, Name:%s, State:%s, zip code:%d", stud2.id, stud2.name, stud2.addr.state, stud2.addr.zip_code);
}
