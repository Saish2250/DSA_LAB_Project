#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Vehicle Service Management System using linkedlist

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



//Insert function inserts the records of the customer into the system
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


//Update function allows the updation of records which are already stored
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
        printf("Choose Vehicle's Type\n");
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

//display function displays the records which are stored
void display(){
    if(head==NULL){
        printf("No car visited\n");
        return;
    }

        struct record*show=head;

        printf("\n");


        printf("Displaying Serviced Vehicles: \n");
         printf("|__Sr.no__|______Owner______|__Vehicle Type__|______Name______|____Service____|__Vehicle Number__|__Mobile No__|__Price__|\n");

        do{

         printf("\n|____%d____|____%s___|_____%s________|___%s___|___%s___|_______%s_______|__%d__|__%d__|\n",show->c,show->name,show->vtype,show->c_name,show->service,show->carn,show->phone,show->price);
            printf("\n");

            show=show->next;
        }while(show!=NULL);


        printf("\n\n\n");
}

//It will search records of a customer
void searching(){
    if(head==NULL){
        printf("No car visited\n");
        return;
    }

        struct record*show=head;

        printf("\n");
        char own[30];
      while ((getchar()) != '\n');
     printf("Enter owner name to search a record\n");
     scanf("%[^\n]%*c", own);
     printf("Press Enter to continue\n");

        printf("Displaying Serviced Vehicles: \n");
         printf("|__Sr.no__|______Owner______|__Vehicle Type__|______Name______|____Service____|__Vehicle Number__|__Mobile No__|__Price__|\n");

        do{
        if(strcmp(show->name,own)==0){
         printf("\n|____%d____|____%s___|_____%s________|___%s___|___%s___|_______%s_______|__%d__|__%d__|\n",show->c,show->name,show->vtype,show->c_name,show->service,show->carn,show->phone,show->price);
            printf("\n");
        }
            show=show->next;
        }while(show!=NULL);


        printf("\n\n\n");
}

//PRinting the data into a file

void printtofile(){
    if(head==NULL){
        printf("No car visited\n");
        return;
    }
    FILE *fptr1;
        struct record*show=head;

        printf("\n");

        if(fptr1==NULL){
            printf("Error\n");

        }
        fptr1=(fopen("./data.txt","a"));

         fprintf(fptr1,"Displaying Serviced Vehicles: \n");
         fprintf(fptr1,"|__Sr.no__|______Owner______|__Vehicle Type__|______Name______|____Service____|__Vehicle Number__|__Mobile No__|__Price__|\n");
        do{

         fprintf(fptr1,"\n|____%d____|____%s___|_____%s________|___%s___|___%s___|_______%s_______|__%d__|__%d__|\n",show->c,show->name,show->vtype,show->c_name,show->service,show->carn,show->phone,show->price);
            fprintf(fptr1,"\n");

            show=show->next;
        }while(show!=NULL);
        fclose(fptr1);
        printf("\n\n\n");
        printf("Output successfully written");
}



//Removal function is used to records which are already stored using delin() function
void removal(struct record **head, int value) {
  struct record *curr = *head;
  struct record *prev = NULL;

  // Traverse the list to find the node to delete
  while (curr != NULL && curr->c != value) {
    prev = curr;
    curr = curr->next;
  }


  if (curr == NULL)
    {
      printf("No record available with give input");
      printf("\n\n\n");
      return;
    }


  if (prev == NULL) {
    *head = curr->next;
  } else {
    prev->next = curr->next;
  }


  free(curr);
  printf("Record successfully deleted\n");
  printf("\n\n\n");
}
