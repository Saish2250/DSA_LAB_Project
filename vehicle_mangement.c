#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "vehicle_management.h"

struct record{
    int c;
    char name[100];
    char c_name[100];
    char service[100];
    struct record *ptr;
    struct record *next;
    char carn[100];
    char vtype[100];
    int phone;

};
char name[100];
char c_name[100];
char service[100];
char carn[100];
int phone;
char temp[100];
char vtype[100];
struct record*head;
int num=0;
int c;
//struct owner*current_node=NULL;


void input(){
 printf("\n\n");

    while ((getchar()) != '\n');
        c++;
        printf("\n");
        printf("Enter Owner's Name\n");
        scanf("%[^\n]%*c", name);
        printf("Enter vehicle type\n");
        scanf("%[^\n]%*c", vtype);
        printf("Enter Vehicle's Name\n");
        scanf("%[^\n]%*c", c_name);
        printf("Enter the Service\n");
        scanf("%[^\n]%*c", service);
        printf("Enter Vehicle Number\n");
        scanf("%[^\n]%*c", carn);
        printf("Enter phone number\n");
        scanf("%d",&phone);
        printf("\n");
        Insert(c,name,vtype,c_name,service,carn,phone);
}


void Insert(int c,char name[],char vtype[],char c_name[],char service[],char carn[],int phone)
{
    struct record *ptr = (struct record*)malloc(sizeof(struct record));
    struct record *temp;
    ptr->c=c;
    strcpy(ptr->name,name);
    strcpy(ptr->vtype,vtype);
    strcpy(ptr->c_name,c_name);
    strcpy(ptr->service,service);
    strcpy(ptr->carn,carn);
    ptr->phone = phone;


    if(head == NULL)
    {
        ptr -> next = NULL;
        head = ptr;
    }
    else
    {
        temp = head;
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = ptr;
        ptr->next = NULL;

    }
    num = num + 1;
}

void update(){
    if(head==NULL){
        printf("No data added");
        printf("\n");
        return;
    }
    struct record *ptr1 = (struct record*)malloc(sizeof(struct record));
     char vn[30];
      while ((getchar()) != '\n');
     printf("Enter Vehicle Number to Update a record\n");
     scanf("%[^\n]%*c", vn);
     printf("Press Enter to continue\n");
     struct record*check=head;
    do{
    if(strcmp(check->carn,vn)==0){
        char c[100];
        char o[100];
        char v[100];
        char s[100];
        char cn[100];
        int ph;
        while ((getchar()) != '\n');

        printf("\n");
        printf("Enter Owner's Name\n");
        scanf("%[^\n]%*c", o);
        printf("Enter Vehicle's Type\n");
        scanf("%[^\n]%*c", v);
        printf("Enter Car's Name\n");
        scanf("%[^\n]%*c", c);
        printf("Enter the Service\n");
        scanf("%[^\n]%*c", s);
        printf("Enter Car Number = \n");
        scanf("%[^\n]%*c", cn);
        printf("Enter phone number\n");
        scanf("%d",&ph);
        strcpy(check->name,o);
        strcpy(check->vtype,v);
        strcpy(check->c_name,c);
        strcpy(check->service,s);
        strcpy(check->carn,cn);
        check->phone = ph;
        printf("Record updated successfully\n");
        return;
     }
     check=check->next;
    }while(check!=NULL);
    printf("No data available");
    printf("\n\n\n");
}

void display(){
    if(head==NULL){
        printf("No car visited\n");
        return;
    }
        struct record*show=head;

        printf("\n");

        printf("Displaying Serviced Vehicles: \n");
         printf("|\tSr.no\tOwner\t|\tVehicle Type\t|\tName\t|\tService\t|\tCar_Number\t|\tMobile No\t\n");
        do{

            printf("|\t%d\t%s\t%s\t%s\t%s\t%s\t%d\n",show->c,show->name,show->vtype,show->c_name,show->service,show->carn,show->phone);
            printf("\n");

            show=show->next;
        }while(show!=NULL);

        printf("\n\n\n");
}

void delin(){
    int c1;
    printf("Enter serial no to delete\n");
    scanf("%d",&c1);
    removal(&head,c1);
}
void removal(struct record **head, int value) {
  struct record *curr = *head;
  struct record *prev = NULL;

  // Traverse the list to find the node to delete
  while (curr != NULL && curr->c != value) {
    prev = curr;
    curr = curr->next;
  }

  // If the node was not found, do nothing
  if (curr == NULL)
    {
      printf("No record available with give input");
      printf("\n\n\n");
      return;
    }

  // Adjust the pointers to skip over the node to be deleted
  if (prev == NULL) {
    *head = curr->next;
  } else {
    prev->next = curr->next;
  }

  // Free the memory allocated for the node
  free(curr);
  printf("Record successfully deleted\n");
  printf("\n\n\n");
}


int main(){
int ch;


    do{
    printf("/n/n1.Insert records\n");
    printf("2.Display records\n");
    printf("3.Delete records\n");
    printf("4.Update records\n");
    printf("0. Exit\n");
    printf("What service you want to choose\n");
    printf("Enter your option\n");
    scanf("%d",&ch);

   if(ch ==1)
   {
        input();
   }else if(ch ==2){
        display();
   }else if(ch ==3){
        delin();
   }else if(ch==4)
   {
        update();
   }
   else if ( ch == 0){
    printf("Exited");
   }else
   {

    printf("Invalid Input");
   }

} while(ch!=0);
return 0;
}
