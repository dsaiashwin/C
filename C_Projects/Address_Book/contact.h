#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100					//creating a macro

#include <stdio.h>
#include <string.h>

 typedef struct {						//Creating a structure for the addressbook columns
    char name[50];
    char phone[20];
    char email[50];
} Contact; 							//structure variable

typedef struct {						//creating an array of structures and contact count
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void populatecontact(AddressBook *addressBook);
void saveContact(AddressBook *addressBook);

#endif
