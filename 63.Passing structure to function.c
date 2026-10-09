#include <stdio.h>
#include <string.h>

struct func_stru
{
    int id;
    char name[20];
};
void func(struct func_stru*  , int );

int main()
{
    int k = 25;
    struct func_stru fs;
    fs.id=100;
    strcpy(fs.name,"Hello!");
    func(&fs,k);
}

void func(struct func_stru *fs , int k)
{
    printf("%s %d %d", fs->name ,(*fs).id, k);
}
