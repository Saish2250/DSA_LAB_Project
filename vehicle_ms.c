#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "vehicle_management.h"

int main(){
int ch;


    do{
    printf("\n\n1.Insert records\n");
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

