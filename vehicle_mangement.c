#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct record{
    char name[100];
    char c_name[100];
    char service[100];
    struct record *ptr;
    struct record *next;
    char carn[100];
    int phone;
};
char name[100];
char c_name[100];
char service[100];
char carn[100];
int phone;
char temp[100];
struct record*head=NULL;
int num=0;
//struct owner*current_node=NULL;


void input(){
 printf("\n\n");

    while ((getchar()) != '\n');

        printf("\n");
        printf("Enter Owner's Name\n");
        scanf("%[^\n]%*c", name);
        printf("Enter Car's Name\n");
        scanf("%[^\n]%*c", c_name);
        printf("Enter the Service\n");
        scanf("%[^\n]%*c", service);
        printf("Enter Car Number = \n");
        scanf("%[^\n]%*c", carn);
        printf("Enter phone number\n");
        scanf("%d",&phone);
        printf("\n");
        Insert(name,c_name,service,carn,phone);
    }


void Insert(char name[],char c_name[],char service[],char carn[],int phone)
{
    struct record *ptr = (struct record*)malloc(sizeof(struct record));
    struct record *temp;
    strcpy(ptr->name,name);
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

void display(){
    if(head==NULL){
        printf("No car visited\n");
        return;
    }
        struct record*show=head;

        printf("\n");
        int i=1;
        printf("Displaying Serviced Vehicles: \n");
         printf("|\tSr.no\tOwner\t|\tName\t|\tService\t|\tCar_Number\t|\tMobile No\t\n");
        do{

            printf("|\t%d\t%s\t%s\t%s\t%s\t%d\n",i,show->name,show->c_name,show->service,show->carn,show->phone);
            printf("\n");

            i++;
            show=show->next;
        }while(show!=NULL);

}


int main(){
int ch;


    do{
    printf("1.Insert records\n");
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

   }else if(ch==4)
   {

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
