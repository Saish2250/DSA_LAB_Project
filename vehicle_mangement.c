#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct car{
    char carname[100];
    struct car *next1;
    struct car *prev1;
};

char temp2[100];
struct car*head2=NULL;
struct car*current_node1=NULL;

struct owner{
    char ownname[100];
    struct owner *next;
    struct owner *prev;
};

char temp[100];
struct owner*head=NULL;
struct owner*current_node=NULL;



void owner_name(){
    printf("Enter Owner Name: ");
    while((getchar())!='\n');
    scanf("%[^\n]%*c",temp);

    struct owner* own_node=(struct owner*)malloc(sizeof(struct owner));
    strcpy(own_node->ownname,temp);
    if(head == NULL){
        own_node->next = own_node->prev=own_node;
        head=current_node=own_node;
        return;
    }
    struct owner*last =head->prev;
    own_node->prev=last;
    last->next=own_node;
    own_node->next=head;
    head->prev=own_node;
}
void car_name(){
    printf("Enter Car Name: \n");
    while((getchar())!='\n');
    scanf("%[\n]%*c",temp2);

    struct car* car_node=(struct car*)malloc(sizeof(struct car));
    strcpy(car_node->carname,temp2);
    if(head2 == NULL){
        car_node->next1 = car_node->prev1=car_node;
        head2=current_node1=car_node;
        return;
    }
    struct car*last1 =head2->prev1;
    car_node->prev1=last1;
    last1->next1=car_node;
    car_node->next1=head2;
    head2->prev1=car_node;
}


void display(){
    if(head2==NULL){
        printf("No car visited\n");
        return;
    }
        struct owner*show=head;
        struct car*show1=head2;
        printf("\n");
        int i=1;
        printf("Displaying Serviced Vehicles: \n");
        do{
            printf("Sr.no\tOwner\t|\tName\t|\tService\t\n");
            printf("%d\t%s\t%s\t\n",i,show->ownname,show1->carname);
            printf("\n");
            printf("%s\n",show1->carname);
            i++;
            show=show->next;
            show1=show1->next1;
        }while(show!=head);

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
       owner_name();
       car_name();


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
