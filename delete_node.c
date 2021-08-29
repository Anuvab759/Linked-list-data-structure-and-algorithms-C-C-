#include<stdio.h>
#include<stdlib.h>

struct node{
struct node *prev;
int data;
struct node *next;
};

struct node *head;

void generate_head(){
int num;
if(head){
printf("\t\tHead node already exists!\n\n");
} else {
struct node *temp = (struct node *)malloc(sizeof(struct node));
temp -> prev = NULL;
temp -> next = NULL;
printf("\t\t Provide the value of the head node:\n\n");
scanf("%d",&num);
temp -> data = num;
head = temp;
}
}

void add_beg(){
int num;
char ch;
if(!head){
printf("\t\t Head node does not exist! create head first...\n\n");
} else {

printf("\t\t Insert at the beginning? Are you sure? \n");
printf("\t\t This will modify the head node... \n");
scanf("%c",&ch);

while((ch = getchar()) != 'n'){
struct node *temp = (struct node *)malloc(sizeof(struct node));
printf("\t\t Provide the node you want to insert a the beginning:\n\n");
scanf("%d",&num);
temp -> data = num;
temp -> next = head;
temp -> prev = NULL;
head = temp;
printf("\t\t Want to insert another at the beginning (y/N)?\n\n");
scanf("%c",&ch);
}
}
}

void append(){
struct node *iter, *temp;
int num;
if(!head){
printf("\t\t Head node does not exist! create head first...\n\n");
} else {

iter = head;
while(iter -> next != NULL){
iter = iter -> next;
}
temp = (struct node *)malloc(sizeof(struct node));
printf("\t\t Provide the node you want to append:\n\n");
scanf("%d",&num);
iter -> next = temp;
temp -> data = num;
temp -> next = NULL;
temp -> prev = iter;
}
}

void delete(){
struct node *iter, *temp, *newNode, *nextNode;
int pos;
if(!head){
printf("\t\t Head node does not exist! create head first...\n\n");
} else {
temp = head;
printf("\t\t Provide which node you would like to delete\n");
scanf("%d",&pos);
if(pos == 1){
head = head -> next;
head -> prev = NULL;
temp -> next = NULL;
} else {
iter = head;
for(int i = 0; i < pos - 1; i++){
iter = iter -> next;
}
newNode = iter -> next;
iter -> next = newNode -> next;
newNode -> next = NULL;
}
}
}

void show(){
struct node *iter;
int count = 1;
if(!head){
printf("\t\t ******* Nothing to display! Create nodes first ********* \n\n");
} else {
iter = head;
while(iter){
printf("Data field at node %d is: %d\n",count, iter -> data);
iter = iter -> next;
count++;
}
}
}

void main(){
int flag = 0, choice;
while(flag == 0){
printf("\t\t OPTION 1: Create the head.\n");
printf("\t\t OPTION 2: Insert at the beginning.\n");
printf("\t\t OPTION 3: Display all the nodes.\n");
printf("\t\t OPTION 4: Append a node.\n");
printf("\t\t OPTION 5: Delete a node.\n");
printf("\t\t ANY OTHER KEY: EXIT...\n\n");
printf("\t\t Please enter your choice.. \n\n");
scanf("%d",&choice);
switch(choice){
 case 1:
	 generate_head();
	 break;
 case 2:
	 add_beg();
	 break;
 case 3:
	 show();
	 break;
 case 4:
	 append();
	 break;
 case 5:
         delete();
         break;

 default:
	 flag = 1;
	 printf("\t\t Exiting ..... \n");
	 break;
}
}

}
