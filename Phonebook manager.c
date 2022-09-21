#include<stdlib.h>
#include<string.h>
#include<stdio.h>


struct node
{
    int initial;
    char name[100];
    char phone[100];
    struct node *next;

}* head;
void insert(int initial, char* name, char* phone)
{

    struct node * node = (struct node *) malloc(sizeof(struct node));
    node->initial = initial;
    strcpy(node->name, name);
    strcpy(node->phone, phone);
    node->next = NULL;

    if(head==NULL){
        // if head is NULL
        // set node as the new head
        head = node;
    }
    else{
        // if list is not empty
        // insert node in beginning of head
        node->next = head;
        head = node;
    }

}
void search(int initial)
{
  struct node * temp = head;
    while(temp!=NULL){

        if(temp->initial==initial)
        {
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("contact with unique number %d is not found .\n", initial);
}
void update(int initial)
{

    struct node * temp = head;
    while(temp!=NULL){

        if(temp->initial==initial){
            printf("Contact with unique number  %d Found .\n", temp->initial);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("Updated Successfully.\n");
            return;
        }
        temp = temp->next;

    }
    printf("contact with unique number %d is not found .\n", initial);

}
void Delete(int initial)
{
    struct node * temp1 = head;
    struct node * temp2 = head;
    while(temp1!=NULL){

        if(temp1->initial==initial){

            printf("Contact with unique value %d Found .\n", initial);

            if(temp1==temp2){
                head = head->next;
                free(temp1);
            }
            else{

                temp2->next = temp1->next;
                free(temp1);
            }

            printf("Record Successfully Deleted .\n");
            return;

        }
        temp2 = temp1;
        temp1 = temp1->next;

    }
    printf("contact with unique number %d is not found .\n", initial);

}
void display()
{
    struct node * temp = head;


    while(temp!=NULL){

        printf("Contact with unique number  : %d\n", temp->initial);
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        temp = temp->next;

    }
}
int main()
{
    system("Color 71");
    head = NULL;
    int choice;
    char name[100];
    char phone[100];
    int initial;
     char ch;
    printf("       \n\n\n\t\t\t\t\tWelcome to our Phonebook Manager\n\n\n");
    printf("       \n\n\t\t\t\t\tType 'Y' to start using the program \n\n\n");
     scanf("%s",&ch);

     if("ch == Y"){
    printf(" Press 1 to insert a contact details\n Press 2 to search for a contact\n Press 3 to delete a contact\n Press 4 to update a contact\n Press 5 to display all contacts ");
    do
    {
        printf("\n\n Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf(" \nEnter an unique value for the contact: ");
                scanf("%d", &initial);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                insert(initial, name, phone);
                break;
            case 2:
                printf(" \nEnter an unique value for the contact to search: ");
                scanf("%d", &initial);
                search(initial);
                break;
            case 3:
                printf(" \nEnter an unique value for the contact to delete: ");
                scanf("%d", &initial);
                Delete(initial);
                break;
            case 4:
                printf(" \nEnter an unique value for the contact to update: ");
                scanf("%d", &initial);
                update(initial);
                break;
            case 5:
                display();
                break;
        }

    } while (choice != 0);
}

}
