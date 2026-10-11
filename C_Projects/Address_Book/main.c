/*
Name : Sai Ashwin D
Date of Submission : 01-05-2025
Description :  Creates a Database (File) to store and make operations on the Address Book
Sample Input:

Hello! Displaying you Address book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save contacts
7. Exit

Enter your choice: 1
Selected create contact
Enter the name: Sai Ashwin D
Enter the Phone number: 8885511656
Enter the Email: saiashwin2000@gmail.com
<<<Yay!! you have done with creating a new Contact into the addressbook>>>

Hello! Displaying you Address book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save contacts
7. Exit
Enter your choice: 7

Saving your changes! and Exiting the process...
Thank you user

*/
#include "contact.h"

int main()
{
	int choice;
	AddressBook A1;
	AddressBook *ptr=&A1;
	initialize(ptr);
   do
   {

    printf("+=========================================================================+");	//Menu displaying all operations that can be done on Address book
	printf("\n|	  <:::::: Hello! Displaying you Address book Menu ::::::> 	  |\n");
	printf("|                                                 			  |\n");
    printf("|   1 -> Create contact							  |\n");
	printf("|                                                 			  |\n");
    printf("|   2 -> Search contact							  |\n");
	printf("|                                                 			  |\n");
    printf("|   3 -> Edit contact						     	  |\n");
	printf("|                                                 			  |\n");
    printf("|   4 -> Delete contact							  |\n");
	printf("|                                                 			  |\n");
    printf("|   5 -> List all contacts						  |\n");
	printf("|                                                 			  |\n");
    printf("|   6 -> Save contacts							  |\n");
	printf("|                                                 			  |\n");
    printf("|   7 -> Exit							    	  |\n");
	printf("|                                                 			  |\n");
    printf("+=========================================================================+\n");
	printf("\n");
   //user input
   printf("Enter your choice: ");
   scanf("%d", &choice);
   
   switch(choice)
   {
      case 1:														//create contact
        printf("\nSelected an option to create a contact\n");
		createContact(ptr);
        break;
        
      case 2:														//search contact
        printf("\nSelected an option to search a contact\n");
		searchContact(ptr);
        break;
        
       case 3:														//Edit contact
		printf("\nSelected an option to Edit a contact\n");
		editContact(ptr);
        break;
        
       case 4:														//Delete contact
        	printf("\nSelected an option to Delete a contact\n");
		deleteContact(ptr);
        break;
        
       case 5:														//List all contacts
       		printf("\nSelected an option to list all Contacts in Address Book\n");
       		listContacts(ptr);
       break;
       
       case 6:														//save contacts
       		printf("\nSaving your changes!\n");
       		saveContact(ptr);
       break;
       
       default:														//waiting for a valid Input
       	if (choice != 7 )
	
       	printf("\nEnter Valid option\n");
	
       	else if (choice == 7)												//if the user want to Exit
		{
			
			printf("\nSaving your changes! and ");
			printf("Exiting the process...\n");
			saveContact(ptr);
			printf("\n				Thank you user\n");
		}
   }
   }while(choice != 7);
   return 0;
}

