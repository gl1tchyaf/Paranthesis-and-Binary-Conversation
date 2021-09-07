#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print();
void push(char* num);
void pop();
void checkParanthesis();
void push2(char* num);


struct node{
    char* num;
    struct node *next;
}*head;

int main(){
    while(1){
        char no[10]={'\0'};
        int n;
        printf("1. Insert data/ push stack \n");
        printf("2. Print stack \n");
        printf("3. Pop stack \n");
        printf("4. Check Parenthesis \n");
        printf("5. Decimal to binary convert \n");
        printf("6. Clear Stack \n");
        printf("7. Exit \n");

        printf("\n Enter your Choice: \n");
        scanf("%d",&n);
        if(n==1){
            printf("Enter data : ");
            scanf("\n\n%s", &no);
            push(no);
            }
        else if(n==2){
            print();
            }
        else if(n==3){
            pop();
            }
        else if(n==4){
            checkParanthesis();
            }
        else if(n==5){
                clear();
            int decimal,pf;
            printf("Enter a decimal number: ");
            scanf("%d",&decimal);
            while(decimal!=0){
                char sd[5]={'\0'};
                pf=decimal%2;
                sprintf(sd,"%d",pf);
                decimal=decimal/2;
                if(strcmp(sd,"0")==0){
                push2("0");
                }
                if(strcmp(sd,"1")==0){
                push2("1");
                }
            }
            printf("\n");
            reverseLinkedList();
        }
        else if(n==6){
            clear();
            printf("Stack Cleared \n");
            }
        else if(n==7){
            exit(0);
            }
        }
    }


void print(){
    struct node *temp;
    if(head == NULL){
        printf(" List is empty \n");
        }
    else{
        temp=head;
        while(temp!=NULL){
            printf(" => %s ", temp->num);
            temp = temp->next;
        }
    }
        printf("\n");
        main();
}
void push(char* num){

struct node* temp;
temp = (struct node*)malloc(sizeof(struct node));
temp->next = NULL;
temp->num=num;
if(head == NULL){
    head = temp;
}else{
    struct node* temp1;
    temp1 = head;
    while(temp1->next!=NULL){
        temp1 = temp1->next;

    }

    temp1->next = temp;
}
    printf("\n");

    main();


}

void push2(char* num){

struct node* temp;
temp = (struct node*)malloc(sizeof(struct node));
temp->next = NULL;
temp->num=num;
if(head == NULL){
    head = temp;
}else{
    struct node* temp1;
    temp1 = head;
    while(temp1->next!=NULL){
        temp1 = temp1->next;

    }

    temp1->next = temp;
}
    printf("\n");



}

void pop()
{
struct node *temp, *temp1;
    if(head == NULL)
    {
        printf(" The Linked list is empty \n");
    }
    else
    {
        temp = head;
        temp1 = head;
        while(temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        if(temp == head)
        {
            head = NULL;
        }
        else
        {
            temp1->next = NULL;
        }
        free(temp);
    }
   // main();
}
void checkParanthesis(){
    struct node *temp;
    int check=0;
    if(head == NULL){
        printf(" List is empty \n");
        return;
        }
    else{
        temp=head;
        while(temp!=NULL){


                if(strcmp(temp->num,"(")==0 ){
                    check++;

                   }
                   else if(strcmp(temp->num,")")==0 ){
                    check--;
                   }

            temp = temp->next;
        }
    }

        if(check==0){
            printf("Parenthesis Matched ");
        }
        if(check>0){
            printf("Opening parentheses not end");
        }
        if(check<0){
            printf("Closing parentheses not end");
        }

        printf("\n");
        main();
}
void reverseLinkedList()
{
    struct node *temp, *temp1;

    if(head != NULL)
    {
        temp = head;
        temp1 = head->next;
        head = head->next;

        temp->next = NULL;

        while(head != NULL)
        {
            head = head->next;
            temp1->next = temp;

            temp = temp1;
            temp1 = head;
        }
        head = temp;
    }
    print();
    main();
}
void clear(){
        struct node *temp;
        int i=0,j;
    if(head == NULL){
        //printf(" List is empty \n");
        return;
        }
    else{
        temp=head;
        while(temp!=NULL){

            temp = temp->next;
            i++;
        }
    }
        for(j=0;j<i;j++){
            pop();
        }
        printf("\n");
}
