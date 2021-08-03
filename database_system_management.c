/* This program can manage student databsed system in an interactive fashion */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
 char name[20];
 int roll;
 struct student *next;
};

struct student *head;

/* This function creates the nodes, along with the head node. Rest of the nodes 
 * are included based on user input */

void generate(){
int i,n,r;
struct student *curr, *iter;
char ch;

curr = (struct student *)malloc(sizeof(struct student));
printf("\t\t Enter the value of the head node: \n");
printf("\t\t Please enter student name:\n");
scanf("%s",curr -> name);
printf("\t\t Please enter student roll:\n");
scanf("%d",&r);

curr -> roll = r;
curr -> next = NULL;
head = curr;
iter = head;

n = 1;
printf("\t\t Include entries after 1st student (y/N)? \n");
scanf("%c",&ch);
if((ch = getchar()) == 'y'){

while((ch = getchar()) != 'n'){
n++;
printf("\t\t Enter the name of the student %d: \n",n);

curr = (struct student *)malloc(sizeof(struct student));
printf("\t\t Please enter student name:\n");
scanf("%s",curr -> name);
printf("\t\t Please enter student roll:\n");
scanf("%d",&r);

curr -> roll = r;
curr -> next = NULL;

iter -> next = curr;
iter = curr;
printf("\t\t Add one more node (y/N)?  ");
scanf("%c",&ch);
}
}
}

/* Displays the nodes */

void show(){
struct student *iter;
if(!head){
printf("\t\t No entry exists! Nothing to show!\n");
}
iter = head;
while(iter){
printf("Name = %s\n",iter -> name);
printf("Roll = %d\n",iter -> roll);
iter = iter -> next;
}
}

/* Search an entry from the linked list based on the roll number of the student */

void search(){
struct student *iter;
int num;
char *n;

if(!head){
printf("\t\t ***** No node exists! Enter another choice *****\n\n");
} else {
printf("\t\t Please enter the roll you want to find:\n");
scanf("%d",&num);
iter = head;
while(iter){
if(iter -> roll == num){
n = iter -> name;
printf("\t\t The name of the student is: %s\n\n",iter -> name);
return;
}
iter = iter -> next;
}
printf("\t\t This roll no. does not exist in the database! Try again... \n\n");
}
}

/* Updates the entries of a node based on user input */

void update(){
struct student *iter;
int num;
char *newname;

if(!head){
printf("\t\t **** No node exists! Enter another choice **** \n\n");
} else {
printf("\t\t Please enter the roll you want to update:\n");
scanf("%d",&num);
iter = head;
while(iter){
if(iter -> roll == num){
printf("\t\t Please enter the new name:\n");
scanf("%s",iter -> name);

printf("\t\t The modified name of the student is: %s\n\n",iter -> name);
return;
}
iter = iter -> next;
}
printf("\t\t This roll no. does not exist in the database! Try again... \n\n");
}

}

/* Appends an entry at the tail. If head does not exist, it flashes an error message */

void append(){
struct student *new, *iter;
int num;

if(!head){
printf("\t\t ***** All nodes absent! Provide head node first **** \n\n");
} else {

iter = head;
while(iter -> next != NULL){
iter = iter -> next;
}

new = (struct student *)malloc(sizeof(struct student));
printf("\t\t Please provide the entries you want to append\n");
printf("\t\t Name of the student:\n");
scanf("%s",new -> name);
printf("\t\t Roll no. of the student: \n");
scanf("%d",&num);
new -> roll = num;
new -> next = NULL;
iter -> next = new;
}
}

/* This function replaces the head node based on user input */

void insert_head(){
struct student *new, *temp;
int num;
if(!head){
printf("\t\t ***** All nodes absent! Provide head node first **** \n\n");
} else {
new = (struct student *)malloc(sizeof(struct student));
printf("\t\t Please provide the entries you want to append\n");
printf("\t\t Name of the student:\n");
scanf("%s",new -> name);
printf("\t\t Roll no. of the student: \n");
scanf("%d",&num);
new -> roll = num;
new -> next = NULL;
temp = new;
temp -> next = head;
temp = temp -> next;
head = new;
}
}

/* Inserts a node in the middle */

void push(){
struct student *new, *iter, *temp;
int num, pos, i;
if(!head){
printf("\t\t ***** All nodes absent! Provide head node first **** \n\n");
} else {
printf("\t\t  ----- Provide where you want to insert ---- \n");
scanf("%d",&pos);
new = (struct student *)malloc(sizeof(struct student));
printf("\t\t Please provide the entries you want to append\n");
printf("\t\t Name of the student:\n");
scanf("%s",new -> name);
printf("\t\t Roll no. of the student: \n");
scanf("%d",&num);
new -> roll = num;
new -> next = NULL;

iter = head;
i = 0;
while(i <= pos - 1){
iter = iter -> next;
i++;
}
temp = iter -> next;
new -> next = temp;
iter -> next = new;
}
}

/*Can delete a node, including the head and tail*/

void delete(){
struct student *iter;
int position;

if(!head){
printf("\t\t ***** All nodes absent! Provide head node first **** \n\n");
} else {
iter = head;
printf("\t\t  ----- Provide which node you want to delete ---- \n");
scanf("%d",&position);
if(position == 1){
head = head -> next;
iter -> next = NULL;
} else {
for(int i = 0; i < position - 2; i++){
iter = iter -> next;
}
struct student *temp;
temp = iter -> next;
iter -> next = temp -> next;
temp -> next = NULL;
}
}
}


void main(){
int flag = 0, choice;

printf("\t\t ===== A program to manage student database ===== \n");
while(flag == 0){
printf("\t\t 1: Create a node\n");
printf("\t\t 2: Print all nodes\n");
printf("\t\t 3: Search a student (based on roll no:)\n");
printf("\t\t 4: Modify student name (based on roll no:)\n");
printf("\t\t 5: Append an entry\n");
printf("\t\t 6: Add at the beginning\n");
printf("\t\t 7: Add at specific position\n");
printf("\t\t 8: Delete from a specific position\n");
printf("\t\t any other key: EXIT\n");

printf("\t\t Enter your choice:\n");
scanf("%d",&choice);
switch(choice){
 case 1:
	 printf("\t\t ----- Creating node -----.\n\n");
	 generate();
	 break;
 case 2: 
	 printf("\t\t ----- Printing all nodes ----- \n\n");
	 show();
	 break;
 case 3:
	 printf("\t\t ----- Want to search roll no? ----- \n\n");
	 search();
	 break;
 case 4:
         printf("\t\t ----- Mofifying the existing list ----- \n\n");
         update();
         break;
 case 5:
         printf("\t\t ----- Appending at the end of the existing list ----- \n\n");
         append();
         break;
 case 6:
         printf("\t\t ----- Adding at the beginning of the existing list ----- \n\n");
         insert_head();
         break;
 case 7:
         printf("\t\t ----- Inserting at a specific position ----- \n\n");
         push();
         break;
 case 8:
         printf("\t\t ----- Deleting an entry ----- \n\n");
         delete();
         break;


 default:
	 printf("\t\t Exiting....\n");
         flag = 1;
	 break;
}
}
}
