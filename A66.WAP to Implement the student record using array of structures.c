/*
Name : Sai Ashwin D
Date :19 - 04 -2025
Description : To Implement the student record using array of structures

Sample INPUT & OUTPUT : 
Enter no.of students : 2
Enter no.of subjects : 2
Enter the name of subject 1 : Maths
Enter the name of subject 2 : Science
----------Enter the student datails-------------
Enter the student Roll no. : 1
Enter the student 1 name : Nandhu
Enter Maths mark : 99
Enter Science mark : 91
----------Enter the student datails-------------
Enter the student Roll no. : 2
Enter the student 2 name : Bindhu
Enter Maths mark : 88
Enter Science mark : 78
----Display Menu----
1. All student details
2. Particular student details
Enter your choice : 2

----Menu for Particular student----
1. Name.
2. Roll no.
Enter you choice : 1
Enter the name of the student : Nandhu
Roll No.   Name           Maths         Science       Average       Grade
1         Nandhu           99             91           95             A
Do you want to continue to display(Y/y) : n
*/
#include <stdio.h>
#include <string.h>
struct student
{
    char name[25];
    int roll_no;
    float average;
    char grade;
};

int main()
{
    int no_stud=0,no_sub=0;
    
    printf("Enter no.of students : ");                                      //Entry number of Students
    scanf("%d",&no_stud);
    
    struct student S[no_stud];
    
    printf("Enter no.of subjects : ");                                      //Entry number of Subjects
    scanf("%d",&no_sub);
    
    char subjects[no_sub][20];
    int marks[no_stud][no_sub];
    
    for ( int i = 0 ; i < no_sub ; i++)
    {
        printf("Enter the name of subject %d : ",i+1);                      //Enter names of Subjects 
        
        scanf("%s",subjects[i]);
    }   
    char grade[no_stud];   
    for (int i =  0 ; i < no_stud ; i++)                                    
    {
        printf("----------Enter the student details-------------\n");
        
        printf("Enter the student Roll no. : \n");
        scanf(" %d",&S[i].roll_no);
        getchar();
        printf("Enter the student %d name : \n",S[i].roll_no);              //Enter Roll no of Students
        scanf(" %[^\n]",S[i].name);

        int sum = 0;
        
        for (int j =  0 ; j < no_sub ; j++)
        {   
            
            printf("Enter %s mark : \n",subjects[j]);                       //Enter the marks of Students 
            scanf("%d",&marks[i][j]);
            
            sum+= marks[i][j] ;                                             //calculating the sum of marks of that particular student
        }
        S[i].average=sum/ (float)no_sub;                                    //calculating the Average of marks of that particular student

        if ( S[i].average >= 90)                                           //Getting appropriate grade of Student 
        S[i].grade='A';
        
        else if ( S[i].average >= 80)
        S[i].grade='B';
        
        else if ( S[i].average >= 70)
        S[i].grade='C';
        
        else if ( S[i].average >= 60)
        S[i].grade='D';
        
        else 
        S[i].grade='E';
    }
    
    char option='y';
    
    while(option == 'y' || option == 'Y')                               //Taking default Option to go into menu
    {   
        printf("----Display Menu----\n");
        printf("1. All student details\n");
        printf("2. Particular student details\n");
        int choice=0;
        printf("Enter your choice : ");                                 //Select how you want to get Info about Student(s)
        scanf("%d",&choice);
        getchar();
        switch (choice)
        {
            case 1:                                                     //Display all the Student records in database
            {
                printf("\nRoll No.   Name           Maths         Science       Average       Grade\n");    
                for (int i = 0 ; i < no_stud ; i++)
                {
                            printf("\n%d \t %s \t", S[i].roll_no, S[i].name);
                          
                            for (int j = 0 ; j < no_sub ; j++)
                            {
                                printf("%d \t\t ",marks[i][j]);
                            }
                            printf("%g \t\t %c\n", S[i].average, S[i].grade);
                    
                    
                }
                break;
                
            }            
            case 2:                                                     //Display the Student record based on searching with Roll no or Name
            {
                int n=0;
                char name[25];
                int rollno=0;
                printf("----Menu for Particular student----\n");
                printf("1. Name.\n");
                printf("2. Roll no.\n");
                printf("Enter your choice : ");
                scanf("%d",&n);
                getchar();
                if ( n == 1)                                            //Display the Student record based on searching with Name
                
                {   printf("Enter the name of the student : ");
                    scanf("%s",name);
                    getchar();
                    for (int i = 0 ; i < no_stud ; i++)
                    {
                        if ( ! strcmp(S[i].name,name))
                        {
                            printf("\nRoll No.   Name           Maths         Science       Average       Grade\n");
                        
                            printf("\n%d \t %s \t", S[i].roll_no, S[i].name);
                          
                            for (int j = 0 ; j < no_sub ; j++)
                            {
                                printf("%d \t\t ",marks[i][j]);
                            }
                            printf("%g \t\t %c\n", S[i].average, S[i].grade);
                            
                        }                      
                    }
                }    
                else if ( n == 2)                                       //Display the Student record based on searching with Roll no
                {   printf("Enter the Roll no of the student : ");
                    scanf("%d",&rollno);
                    getchar();
                    for (int i = 0 ; i < no_stud ; i++)
                    {
                        if ( S[i].roll_no == rollno)
                        {
                            printf("\nRoll No.   Name           Maths         Science       Average       Grade\n");
                        
                            printf("\n%d \t %s \t", S[i].roll_no, S[i].name);
                          
                            for (int j = 0 ; j < no_sub ; j++)
                            {
                                printf("%d \t\t ",marks[i][j]);
                            }
                            printf("%g \t\t %c\n", S[i].average, S[i].grade);
                            
                        }                                                    
                    }
                }    
            }                  
        }
    printf("Do you want to continue to display(Y/y) : ");
    scanf(" %c",&option);
    getchar();
    }
        
}
