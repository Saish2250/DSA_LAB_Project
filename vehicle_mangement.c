#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "vehicle_management.h"

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
    int price;
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
int price;
//struct owner*current_node=NULL;



void input(){
 printf("\n\n");
    int ch;

    while ((getchar()) != '\n');
        c++;
        printf("\n");
        printf("Enter Owner's Name\n");
        scanf("%[^\n]%*c", name);
        printf("\n");
        printf("Choose vehicle type\n");
        //scanf("%[^\n]%*c", vtype);
        printf("1. Car\n");
        printf("2. Bike\n");
        scanf("%d",&ch);
        if(ch==1){
            strcpy(vtype, "Car");
        }else if(ch==2){
            strcpy(vtype, "Bike");
        }else{
            strcpy(vtype, "Car");
        }
        while ((getchar()) != '\n');
        printf("\n");
        printf("Enter Vehicle's Name\n");
        scanf("%[^\n]%*c", c_name);
        printf("\n");
        printf("Enter Vehicle Number\n");
        scanf("%[^\n]%*c", carn);
        printf("\n");
        //scanf("%[^\n]%*c", service);
        printf("1. Spray\n");
        printf("2. Wash\n");
        printf("3. Repair\n");
        printf("Choose Vehicle Service\n");
        scanf("%d",&ch);
        if(ch==1){
            strcpy(service, "Spray");
        }else if(ch==2){
            strcpy(service, "Wash");
        }else if(ch==3){
            strcpy(service, "Repair");
        }
        else{
            strcpy(service, "Repair");
        }
        printf("\n");
        printf("Enter phone number\n");
        scanf("%d",&phone);
        printf("\n");
        if(strcmp(vtype,"Car")==0 && strcmp(service,"Spray")==0){
            price=1000;
        }else if(strcmp(vtype,"Car")==0 && strcmp(service,"Wash")==0){
            price=700;
        }else if(strcmp(vtype,"Bike")==0 && strcmp(service,"Wash")==0){
            price=600;
        }else if(strcmp(vtype,"Bike")==0 && strcmp(service,"Spray")==0){
            price=500;
        }else{
            printf("Enter price for repair\n");
            scanf("%d",&price);
        }
        Insert(c,name,vtype,c_name,service,carn,phone,price);
}


void Insert(int c,char name[],char vtype[],char c_name[],char service[],char carn[],int phone,int price)
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
    ptr->price = price;

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
     int ch,ch1;
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
        int p;
        while ((getchar()) != '\n');

        printf("\n");
        printf("Enter Owner's Name\n");
        scanf("%[^\n]%*c", o);
         printf("\n");
        printf("Enter Car's Name\n");
        scanf("%[^\n]%*c", c);
        printf("\n");
        printf("Enter Vehicle's Type\n");
        //scanf("%[^\n]%*c", v);
        printf("\n");
        printf("1. Car\n");
        printf("2. Bike\n");
        scanf("%d",&ch1);
        if(ch1==1){
            strcpy(v, "Car");
        }else if(ch1==2){
            strcpy(v, "Bike");
        }else{
            strcpy(v, "Car");
        }
        while ((getchar()) != '\n');
        printf("\n");
        printf("Enter Vehicle Number\n");
        scanf("%[^\n]%*c", cn);
        printf("\n");
        printf("Choose a Service\n");
        //scanf("%[^\n]%*c", s);
         printf("1. Spray\n");
         printf("2. Wash\n");
         printf("3. Repair\n");
        scanf("%d",&ch);
        if(ch==1){
            strcpy(s, "Spray");
        }else if(ch==2){
            strcpy(s, "Wash");
        }else if(ch==3){
            strcpy(s, "Repair");
        }
        else{
            strcpy(s, "Repair");
        }
        printf("\n");
        printf("Enter phone number\n");
        scanf("%d",&ph);
        if(strcmp(v,"Car")==0 && strcmp(s,"Spray")==0){
            p=1000;
        }else if(strcmp(v,"Car")==0 && strcmp(s,"Wash")==0){
            p=700;
        }else if(strcmp(v,"Bike")==0 && strcmp(s,"Wash")==0){
            p=600;
        }else if(strcmp(v,"Bike")==0 && strcmp(s,"Spray")==0){
            p=500;
        }else{
            printf("Enter price for repair\n");
            scanf("%d",&p);
        }
        strcpy(check->name,o);
        strcpy(check->vtype,v);
        strcpy(check->c_name,c);
        strcpy(check->service,s);
        strcpy(check->carn,cn);
        check->phone = ph;
        check->price = p;
         printf("\n");
        printf("Record updated successfully\n");
        printf("\n");
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
         printf("| Sr.no |\tOwner    |    Vehicle Type   |\tName\t|\tService\t|\tVehicle Number\t|\tMobile No\t|\tPrice\t|\n");
        do{

         printf("|  %d   |\t%s       |    %s             |\t%s\t|\t%s\t|\t%s\t|\t%d\t|\t%d\t|\n",show->c,show->name,show->vtype,show->c_name,show->service,show->carn,show->phone,show->price);
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
