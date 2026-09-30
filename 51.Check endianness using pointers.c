 #include <stdio.h>
 int main()
 {
    int num=0x12345678;
    char*c= (char *) &num;
    
    if (*c==0x78)
    printf("ours is a little endian");
    
    else
    printf("ours is a big endian");
 }
