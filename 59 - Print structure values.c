#include <stdio.h>

struct basic_struct
{
    char name[50];
    int id;
    char address[50];
};

int main()
{
    //struct basic_struct bs1;
    
    struct basic_struct bs1={"Emertxe" , 100 , "Bangalore"};
    
    printf(" Structure 1 has name = %s, id = %d, address = %s\n",bs1.name , bs1.id , bs1.address);
}
