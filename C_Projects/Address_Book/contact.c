#include "contact.h"

void listContacts(AddressBook *addressBook) 													//List all contacts present
{	
	if ( addressBook->contactCount == 0)
	{printf("\n --=> There are no contacts to List\n");}
	
	else {
	printf("\n|==========================================================================|\n");
	printf("|S.no \tName \t\t\t Mobie Number \t   Email Id                |");
	printf("\n|__________________________________________________________________________|");
	printf("\n|                                                                          |\n");
	
    for (int i = 0 ; i < addressBook->contactCount ; i++)
	{
		printf(" %3d.  \t %-20s \t %-13s \t %-13s \t \n",i+1,addressBook->contacts[i].name, addressBook->contacts[i].phone,addressBook->contacts[i].email);
	}
	printf("\n|____________________________________***___________________________________|\n");
	printf("\n");
	}
}

void initialize(AddressBook *addressBook) 													//Initializing the contacts
{
	FILE* fptr = fopen("Contacts.csv","r");
	if (fptr == NULL)
	{
		printf("Error opening the file to read the contacts");
		return;
	}
	fscanf(fptr,"%d\n",&(addressBook->contactCount));

	for (int i = 0 ; i < addressBook->contactCount ; i++)
	{
		fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
	}
	fclose(fptr);
}

void createContact(AddressBook *addressBook) 													//creating a new contact
{
	char ph[20],em[30];
	
	printf("\n --=> Enter the name:\n");
	getchar();
	scanf("%[^\n]",addressBook->contacts[addressBook->contactCount].name);
	printf("\n --=> Enter the Phone number:\n");
	getchar();
	scanf("%[^\n]",ph);
																		//Validating then entered Phone number
	for (int i = 0 ; i <= addressBook->contactCount ; i++)
	{
		if ( (strcmp(ph, addressBook->contacts[i].phone)==0 ) || strlen(ph) > 10 || strlen(ph) < 10)
		{	while(  (!(strcmp(ph, addressBook->contacts[i].phone) )) || strlen(ph) > 10 || strlen(ph) < 10 )
			{		

				if ((!(strcmp(ph, addressBook->contacts[i].phone) )))
				{	printf("\n----------------------------------------------------------------------------------\n");
					printf("\nError : This Phone number already exits \n");
					printf("please try with giving different one\n");
					printf("\n --=> new Phone number:\n");
					getchar();
					scanf("%[^\n]",ph);
					printf("\n----------------------------------------------------------------------------------\n");
				}
				else if ( strlen(ph) > 10 || strlen(ph) < 10 )
				{	printf("\n----------------------------------------------------------------------------------\n");
					printf("\nError : The Phone number entered is not of having length 10\n");
					printf("please try with giving different one\n");
					printf("\n --=> new Phone number:\n");
					getchar();
					scanf("%[^\n]",ph);
					printf("\n----------------------------------------------------------------------------------\n");
				}
			}
		}		
	}
	strcpy(addressBook->contacts[addressBook->contactCount].phone, ph);
	printf("\n=>Enter the Email:\n");
	getchar();
	scanf("%[^\n]",em);
	for (int i = 0 ; i < addressBook->contactCount+1 ; i++)
	{																	//validating the Entered Email
		if ( (!(strcmp(em, addressBook->contacts[i].email))) || strcmp( em+(strlen(em)-4), ".com") !=0 || strchr(em,'@') == NULL )
		{	while( (!(strcmp(em, addressBook->contacts[i].email))) || strcmp( em+(strlen(em)-4), ".com") !=0 )
			{	

				if (!(strcmp(em, addressBook->contacts[i].email)))
				{	printf("\n----------------------------------------------------------------------------------\n");
					printf("\nError : The entered Email id already exits in Address book \n");
					printf("please ensure entering a valid one with '@' and '.com' \n");
					printf("\n --=> new Email ID : \n");
					getchar();
					scanf("%[^\n]",em);
					printf("\n----------------------------------------------------------------------------------\n");
				}
				else if ( strcmp( em+(strlen(em)-4), ".com") !=0 )
				{	printf("\n----------------------------------------------------------------------------------\n");
					printf("\nError : The Email id entered is not ending with \".com\" \n");
					printf("\nplease enter a valid one\n");
					printf("\n --=> new Email ID : \n");
					getchar();
					scanf("%[^\n]",em);
					printf("\n----------------------------------------------------------------------------------\n");
				}
				
				if (strchr(em,'@') == NULL )
				{	printf("\n----------------------------------------------------------------------------------\n");
					printf("\nError : The Email id entered is not having '@'\n");
					printf("\nplease enter a valid one :\n");
					printf("\n --=> new Email ID : \n");
					getchar();
					scanf("%[^\n]",em);
					printf("\n----------------------------------------------------------------------------------\n");
				}
			}
		}

	}
	strcpy(addressBook->contacts[addressBook->contactCount].email,em);
	addressBook->contactCount++;	
	printf("\n----> Yeah !! you have done with creating a new Contact in Addressbook\n");
}

void searchContact(AddressBook *addressBook) 													//Searching for a contact
{//char n[5]="Name",m[15]="Mobile Number",e[9]="Email ID";	
	int r;
	int flag=0;
	if ( addressBook->contactCount == 0)
	{printf("\nThere are no contacts to Search as the contactlist is empty\n");}

	else{
	printf("\n----------------------------------------------------------------------------------\n");
	printf("\nplease enter by what category you want to search:\n");
	printf("\n1.Name \n2.Mobile Number \n3.Email id \n4.Back to main menu\n");
	printf("\n --=> Enter the option:\n");
	getchar();
	scanf("%d",&r);
	getchar();
	printf("\n----------------------------------------------------------------------------------\n");
	if (r == 1)
	{	char name[20];

		printf("\n --=> Enter the Name you are searching for:\n");
		scanf("%[^\n]",name);
		for (int i = 0 ; i < addressBook->contactCount ; i++)
		{
			
			if( !(strcmp(name, addressBook->contacts[i].name)))
			{	
				printf("Got it !\n");
				printf(" The contact you are searching for is :\n");
				printf("\n+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n");
				printf("|S.no \tName \t\t\t Mobie Number \t   Email Id                     |");
				printf("\n+-------------------------------------------------------------------------------+\n");
				printf("%3d.  \t %-20s \t %-13s \t %-13s \t\n",i+1,addressBook->contacts[i].name, addressBook->contacts[i].phone,addressBook->contacts[i].email);
				printf("+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n");
				printf("\n\n");
				flag=1;
			}
			
		}
		if (flag==0)
		{
			printf("\nContact Not Found\n");
		}
	}

	else if (r == 2)
	{	char mobile[20];
		int flag = 0;
		printf("\n --=> Enter the Mobile number you are searching for:\n");
		scanf("%[^\n]",mobile);
		for (int i = 0 ; i < addressBook->contactCount ; i++)
		{
			
			if( !(strcmp(mobile, addressBook->contacts[i].phone)))
			{	
				printf("Got it !\n");
				printf("The contact you are searching for is :\n");
				printf("\n+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n");
				printf("|S.no \tName \t\t\t Mobie Number \t   Email Id                     |");
				printf("\n+-------------------------------------------------------------------------------+\n");
				printf("%3d.  \t %-20s \t %-13s \t %-13s \t\n",i+1,addressBook->contacts[i].name, addressBook->contacts[i].phone,addressBook->contacts[i].email);
				printf("+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n");
				printf("\n\n");
				flag=1;
			}
			
			
		}
		if (flag == 0)
			{
				printf("\nContact Not Found\n");
			}
	}

	else if (r == 3)
	{	char email[30];
		int flag=0;
		printf("\n --=> Enter the Email id you are searching for:\n");
		scanf("%[^\n]",email);
		for (int i = 0 ; i < addressBook->contactCount ; i++)
		{
			
			if( !(strcmp(email, addressBook->contacts[i].email)))
			{	
				printf("Got it !\n");
				printf("The contact you are searching for is :\n");
				printf("\n+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n");
				printf("|S.no \tName \t\t\t Mobie Number \t   Email Id                     |");
				printf("\n+-------------------------------------------------------------------------------+\n");
				printf("%3d.  \t %-20s \t %-13s \t %-13s \t\n",i+1,addressBook->contacts[i].name, addressBook->contacts[i].phone,addressBook->contacts[i].email);
				printf("+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n");
				printf("\n\n");
				flag=1;
			}	
		}
		if (flag == 0 )
			{
				printf("\nContact Not Found\n");
			}
	}
	}
}

void editContact(AddressBook *addressBook) 												//Editing a contact
{
	if ( addressBook->contactCount == 0)
	{printf("\nThere are no contacts found to Edit as the contact list is Empty\n");}
	else{
	int r;
	int flag=0;
	printf("\n----------------------------------------------------------------------------------\n");
	printf("\nplease enter by what detail you want to edit:\n");
	printf("\n1.Name \n2.Mobile Number \n3.Email id \n4.Back to menu");
	printf("\n --=> Enter the option:\n");
	getchar();
	scanf("%d",&r);
	getchar();
	printf("\n----------------------------------------------------------------------------------\n");
	if (r == 1)
	{	char name[20];

		printf("\n --=> Enter the Original Name you want to edit:\n");
		scanf("%[^\n]",name);
		for (int i = 0 ; i < addressBook->contactCount ; i++)
		{
			
			if( !(strcmp(name, addressBook->contacts[i].name)))
			{	char new_name[20];
				printf("\n----------------------------------------------------------------------------------\n");
				printf("\n --=> Enter the edited name:\n");
				getchar();
				scanf("%[^\n]\n",new_name);
				strcpy(addressBook->contacts[i].name, new_name);
				printf("***You are done with Editing the name of the contact***\n");
				flag=1;
				printf("\n----------------------------------------------------------------------------------\n");
			}
		}
		if(flag==0)
			{
				printf("\nError : Enter valid Original name to edit\n");
			}
	}
	
	else if (r == 2)
	{	char mobile[20];
		int flag=0;
		printf("\n --=> Enter the Original Mobile number you want to edit:\n");
		scanf("%[^\n]",mobile);
		for (int i = 0 ; i < addressBook->contactCount ; i++)
		{
			
			if( !(strcmp(mobile, addressBook->contacts[i].phone)))
			{	char new_number[20];
				printf("\n --=> Enter the edited mobile number:\n");
				getchar();
				scanf("%[^\n]\n",new_number);
																			//validating the entered phone number
				for (int i = 0 ; i <= addressBook->contactCount ; i++)
				{
					if ( (strcmp(new_number, addressBook->contacts[i].phone)==0 ) || strlen(new_number) > 10 || strlen(new_number) < 10)
					{	while(  (!(strcmp(new_number, addressBook->contacts[i].phone) )) || strlen(new_number) > 10 || strlen(new_number) < 10 )
						{	

							if (!(strcmp(new_number, addressBook->contacts[i].phone) ))	
							{	printf("\n----------------------------------------------------------------------------------\n");
								printf("\nThis Phone number already exits so invalid\n");
								printf("please try with giving different one\n");
								printf("\n --=> Enter a new Phone number:\n");
								getchar();
								scanf("%[^\n]",new_number);
								printf("\n----------------------------------------------------------------------------------\n");
							}
							
							else if (strlen(new_number) > 10 || strlen(new_number) < 10 )
							{	printf("\n----------------------------------------------------------------------------------\n");
								printf("\nThis Phone number didn't reach the length of 10 digits so invalid\n");
								printf("please try with giving different one\n");
								printf("\n --=> Enter a new Phone number:\n");
								getchar();
								scanf("%[^\n]",new_number);
								printf("\n----------------------------------------------------------------------------------\n");
							}
						}
					}		
				}
			strcpy(addressBook->contacts[i].phone, new_number);
			printf("\n***You are done with Editing the mobile number of the contact***\n");
			printf("\n");
			flag=1;
			}
		}
		if (flag == 0)
			{
				printf("\nEnter valid Original Mobile Number to edit\n");
			}
	}

	else if (r == 3)
	{	char email[30];
		int flag=0;
		printf("\n --=> Enter the Original email id you want to edit:\n");
		scanf("%[^\n]",email);
		for (int i = 0 ; i < addressBook->contactCount ; i++)
		{
			
			if( !(strcmp(email, addressBook->contacts[i].email)))
			{	char new_email[20];
				printf("\n --=> Enter the edited email :\n");
				getchar();
				scanf("%[^\n]",new_email);
																		//validating the entered Email
				for (int i = 0 ; i < addressBook->contactCount+1 ; i++)
				{
					if ( (!(strcmp(new_email, addressBook->contacts[i].email))) || (strcmp( new_email+(strlen(new_email)-4), ".com") !=0 )|| (strchr(new_email,'@') == NULL ))
					{	while( (!(strcmp(new_email, addressBook->contacts[i].email))) || (strcmp( new_email+(strlen(new_email)-4), ".com") !=0) || (strchr(new_email,'@') == NULL ) )
						{	

							if (!(strcmp(new_email, addressBook->contacts[i].email)))
							{	printf("\n----------------------------------------------------------------------------------\n");
								printf("\nError : The entered Email id already exits\n");
								printf("please ensure entering a valid one with '@' and '.com' \n");
								printf("\n --=>  Enter a new Email :\n");
								getchar();
								scanf("%[^\n]",new_email);
								printf("\n----------------------------------------------------------------------------------\n");
							}
							else if ( strcmp( new_email+(strlen(new_email)-4), ".com") !=0 )
							{	printf("\n----------------------------------------------------------------------------------\n");
								printf("\nError : The Email id entered is not ending with \".com\" \n");
								printf("please enter a valid one\n");
								printf("\n --=> Enter a new Email :\n");
								getchar();
								scanf("%[^\n]",new_email);
								printf("\n----------------------------------------------------------------------------------\n");
							}
							
							if (strchr(new_email,'@') == NULL )
							{
								printf("\n----------------------------------------------------------------------------------\n");
								printf("\nError : The Email id entered is not having '@' \n");
								printf("please enter a valid one\n");
								printf("\n --=> Enter a new Email :\n");
								getchar();
								scanf("%[^\n]",new_email);
								printf("\n----------------------------------------------------------------------------------\n");
							}
						}
					}

				}

				strcpy(addressBook->contacts[i].email, new_email);
				printf("\n***You are done with Editing the email id of the contact***\n");
				printf("\n");
				flag=1;
			}	
		}
		if (flag == 0)
			{
				printf("\nError : Enter valid Original Email Id to edit\n");
			}
	}
	}
}

void deleteContact(AddressBook *addressBook) 															//Deleting the contact
{
	int r;
	int flag=0;
	printf("\n----------------------------------------------------------------------------------\n");
	printf("\nplease enter by what category you want to delete the contact:\n");
	printf("\n1.Name \n2.Mobile Number \n3.Email id \n4.Back to menu\n");
	printf("\n --=> Enter the option:\n");
	getchar();
	scanf("%d",&r);
	getchar();
	printf("\n----------------------------------------------------------------------------------\n");
	if (r == 1)
	{	char name[20];

		printf("\n --=> Enter the Name you are searching for:\n");
		scanf("%[^\n]",name);
		
		for (int i = 0 ; i < addressBook->contactCount ; i++)
		{
			
			if( !(strcmp(name, addressBook->contacts[i].name)))
			{	
				for (int k = i ; k < addressBook->contactCount  ; k++)
				{	
					strcpy(addressBook->contacts[k].name, addressBook->contacts[k+1].name);
					strcpy(addressBook->contacts[k].phone, addressBook->contacts[k+1].phone);
					strcpy(addressBook->contacts[k].email, addressBook->contacts[k+1].email);
				}
			 addressBook->contactCount--;
			printf("\n***You are done with Deleting the Contact Information***\n");
			printf("\n");
			flag=1;
			}
					
		}
		if (flag==0)
			{
				printf("\nEnter valid input name to Delete\n");
			}
	}

	else if (r == 2)
	{	char mobile[20];
		int flag=0;
		printf("\n --=> Enter the Mobile number you are searching for:\n");
		scanf("%[^\n]",mobile);
		for (int i = 0 ; i < addressBook->contactCount ; i++)
		{
			
			if( !(strcmp(mobile, addressBook->contacts[i].phone)))
			{
				for (int k = i ; k < addressBook->contactCount ; k++)
				{	
					strcpy(addressBook->contacts[k].name, addressBook->contacts[k+1].name);
					strcpy(addressBook->contacts[k].phone, addressBook->contacts[k+1].phone);
					strcpy(addressBook->contacts[k].email, addressBook->contacts[k+1].email);
				}
				flag=1;
			 addressBook->contactCount--;
			 printf("\n***You are done with Deleting the Contact Information***\n");
			printf("\n");
			}	
		}
		if(flag==0)
			{
				printf("\nEnter valid input Mobile Number to Delete\n");
			}
	}

	else if (r == 3)
	{	char email[30];
		int flag = 0;
		printf("\n --=> Enter the Email id you are searching for:\n");
		scanf("%[^\n]",email);
		for (int i = 0 ; i < addressBook->contactCount ; i++)
		{
			
			if( !(strcmp(email, addressBook->contacts[i].email)))
			{	
				for (int k = i ; k < addressBook->contactCount ; k++)
				{	
					strcpy(addressBook->contacts[k].name, addressBook->contacts[k+1].name);
					strcpy(addressBook->contacts[k].phone, addressBook->contacts[k+1].phone);
					strcpy(addressBook->contacts[k].email, addressBook->contacts[k+1].email);
				}
			 addressBook->contactCount--;
			 printf("\n***You are done with Deleting the Contact Information***\n");
			 printf("\n");
			flag=1;
			}	
		}
		if (flag== 0)
			{
				printf("\nEnter valid input Email Id to Delete\n");
			}
	}
	
}
void saveContact(AddressBook *addressBook)															//saving the contact in file
{
	FILE* fptr = fopen("Contacts.csv","w");
	if (fptr == NULL)
	{
		printf("Error opening the file to write the contacts");
		return;
	}
	fprintf(fptr,"%d\n",addressBook->contactCount);
	
	for (int i = 0 ; i < addressBook->contactCount ; i++)
	{
		fprintf(fptr,"%s,",addressBook->contacts[i].name);
		fprintf(fptr,"%s,",addressBook->contacts[i].phone);
		fprintf(fptr,"%s\n",addressBook->contacts[i].email);
	}
	fclose(fptr);
	printf("\n::::::::::Modified Address Book contact details are stored in Contact.csv file::::::::::\n");
}
