#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact_struct {
    char myName[20]; //name of this Contact
    struct Contact_struct* next; //pointer to the next Contact
} Contact;

//Contact Constructor
void Contact_Create(Contact* thisContact, char thisName[], Contact* nextContact) {
    strcpy(thisContact->myName,thisName);
    thisContact->next = nextContact;
}

void Contact_PrintList(Contact* headContact){
    Contact* currContact = headContact;
    while (currContact != NULL){
        printf("%s\n",currContact->myName);
        currContact = currContact->next;
    }
    printf("\n");
}

void Contact_Add(Contact* headContact, char addName[]){
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    Contact_Create(newContact,addName,NULL);
    
    Contact* currContact = headContact;
    while (currContact->next != NULL){
        currContact = currContact->next;
    }
    currContact->next = newContact;
}

Contact* Contact_Drop(Contact* headContact){
    Contact* currContact = headContact->next;  //start currContact at the next for headContact
    Contact* prevContact = headContact; //so, prevContact starts with the headContact
    
    //CODE GOES HERE (traverse the list, find the last Contact, and unlink it)
   while(currContact->next != NULL) {
      prevContact = currContact; 
      currContact = currContact-> next; 
   }
   
   if (prevContact != NULL) {
      prevContact->next = NULL;
   }  
   
    return currContact; //return the dropped Contact
}

void AddThreeSpacesFromBack(Contact* headContact, char addName[]) {
   int count = 0;
   
   Contact* prevContact = headContact; 
   Contact* currContact = headContact;
   Contact* newContact = (Contact*)malloc(sizeof(Contact));
   Contact_Create(newContact, addName, NULL); 
   
   while(currContact != NULL && count < 3) {
      currContact = currContact->next; 
      
      ++count;
   }
   
   while(currContact != NULL) {
      prevContact = prevContact->next;
      currContact = currContact->next;
   }
   
   newContact->next = prevContact->next;
   prevContact->next = newContact;
}

int main() {
    Contact* headCoach = NULL;
    headCoach = (Contact*)malloc(sizeof(Contact));
    Contact_Create(headCoach,"Head Coach",NULL);
    
    Contact_Add(headCoach,"Remy");
    Contact_Add(headCoach,"Riley");
    Contact_Add(headCoach,"Armani");
    Contact_Add(headCoach,"Jessie");
    Contact_Add(headCoach,"Santana");
    
    //Traverse Linked List and Print Names
    printf("Printing Team List:\n");
    Contact_PrintList(headCoach);
    
    //Remove last Contact (Santana) from back
    //CODE GOES HERE
    printf("Removing Santana from the back:\n");
    Contact_Drop(headCoach);
    Contact_PrintList(headCoach);
    printf("\n");
    
    //Add Devyn to back
    //CODE GOES HERE
    Contact_Add(headCoach, "Devyn");
    printf("Adding Devyn to the back:\n");
    Contact_PrintList(headCoach);
    
    //Insert Casey three spots from back
    //CODE GOES HERE
    AddThreeSpacesFromBack(headCoach, "Casey");
    printf("Inserting Casey three spots from the back:\n");
    Contact_PrintList(headCoach);
    
    
    printf("\n");
    return 0;
}
