#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "vehicle_management.h"

// Vehicle Service Management System using linkedlist

//input() function allows user to insert records of the customer who come to avail the services
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

//dewlin function is used to take input to delete record with a given number serial no using removal function
void delin(){
    int c1;
    printf("Enter serial no to delete\n");
    scanf("%d",&c1);
    removal(&head,c1);
}

int main(){
int ch;

    printf("------------------Welcome to Vehicle Service Management------------------------------------");
    do{
    printf("\n\n1.Insert records\n");
    printf("2.Display records\n");
    printf("3.Delete records\n");
    printf("4.Update records\n");
    printf("5.Print to file\n");
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
   }else if(ch==5)
   {
        printtofile();
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

