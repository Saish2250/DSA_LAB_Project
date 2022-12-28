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

struct part{
    char partname;
    struct part *next2;
    struct part *prev2;
};

char temp3;
struct part *head3=NULL;
struct part *current_node2=NULL;

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
    printf("Enter Car Name: ");
    while((getchar())!='\n');
    scanf("%[^\n]%*c",temp2);

    struct car* car_node=(struct car*)malloc(sizeof(struct car));
    strcpy(car_node->carname,temp2);
    if(head3 == NULL){
        car_node->next1 = car_node->prev1=car_node;
        head3=current_node1=car_node;
        return;
    }
    struct car*last1 =head2->prev1;
    car_node->prev1=last1;
    last1->next1=car_node;
    car_node->next1=head3;
    head2->prev1=car_node;
}


void display(){
    if(head3==NULL){
        printf("No car visited\n");
        return;
    }
        struct owner*show=head;
        struct car*show1=head3;
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

void replace_part(){
    struct part* part_node = (struct part*)malloc(sizeof(struct part));
    printf("Engine\n");
    printf("Brakes\n");
    printf("Headlights\n");
    printf("Clerge\n");
    printf("Accelerator\n");
    printf("Battery\n");
    printf("Tires\n");
    printf("Rear Suspension\n");
    printf("Steering\n");
    printf("Choose part to replace: ");
    while((getchar())!='\n');
    scanf("%c",&temp3);

        strcpy(part_node->partname,temp3);
     if(partname=='Engine' || temp3=='Brakes' ||temp3=='Headlights' || temp3=='Clerge' ||temp3=='Accelerator' || temp3=='Battery'|| temp3=='Tires' || temp3=='Rear Suspension' || temp3=='Steering')
        {
        if(head3 == NULL){
            part_node->next2 = part_node->prev2=part_node;
            head3=current_node2=part_node;
            return;
        }
        struct part*last2 =head3->prev2;
        part_node->prev2=last2;
        last2->next2=part_node;
        part_node->next2=head3;
        head3->prev2=part_node;
        printf("Part replaced successfully");
       }else{
        printf("Chosen Service Not Available we are Extremely Sorry!");
       }
}
int main(){
int ch;


    do{
    printf("Car wash: Rs.1000\n");
    printf("Car Spray Rs.5000\n");
    printf("Replace part\n");
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
        replace_part();
   }else if(ch==4)
   {

   }else if(ch==5)
   {

   }
   else if(ch==6)
   {

   }
   else if(ch==7)
   {

   }
   else if(ch==8)
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
