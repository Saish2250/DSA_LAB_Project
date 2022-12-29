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

void update(){
    if(head==NULL){
        printf("No data added");
        printf("\n");
        return;
    }
    struct record *ptr1 = (struct record*)malloc(sizeof(struct record));
     char own[30];
      while ((getchar()) != '\n');
     printf("Enter Owner Name to Update a record\n");
     scanf("%[^\n]%*c", own);
     struct record*check=head;
     while(strcmp(check->name,own)==0){
        char c[100];
        char o[100];
        char s[100];
        char cn[100];
        int ph;
        while ((getchar()) != '\n');

        printf("\n");
        printf("Enter Owner's Name\n");
        scanf("%[^\n]%*c", o);
        printf("Enter Car's Name\n");
        scanf("%[^\n]%*c", c);
        printf("Enter the Service\n");
        scanf("%[^\n]%*c", s);
        printf("Enter Car Number = \n");
        scanf("%[^\n]%*c", cn);
        printf("Enter phone number\n");
        scanf("%d",&ph);
        strcpy(check->name,o);
        strcpy(check->c_name,c);
        strcpy(check->service,s);
        strcpy(check->carn,cn);
        check->phone = ph;
        break;
     }
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
        printf("No record with entered input\n");
        printf("\n\n\n")
}
void removal(){
if(head==NULL){
    printf("No vehicle data available");
    return;
    }
    char in[100];
    printf("Enter owner name to remove\n");
    while((getchar())!='\n');
     scanf("%[^\n]%*c",in);
     printf("\n");
     struct record*ptr=head;
     do{
        if(ptr->name==ptr && strcmp(ptr->name,in)==0){
            printf("Music removed successfully");
            head=NULL;
            free(ptr);
            return;
        }else if(strcmp(ptr->data,temp)==0){
            struct record*next=ptr->next;
            head=next;
            free(ptr);
            printf("Music deleted\n",ptr);
            return;
        }
        ptr=ptr->next;
     }
     while(ptr!=head);
     printf("No music found");
}
