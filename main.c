#include <stdio.h>
#include <stdlib.h>
#define size 10
struct student
{
char name[50];
int id;
int day;
int month;
int year;
int score;
};
struct node{
int key;
struct student data;
struct node * next;
};
struct node * chain;

// intialize all pointers with null
void initialize()
{
for (int i=0;i<size; i++)
{
chain[i] = NULL;
}
}

void insert()
{
    int hashvalue;
 int key;
//create a new node
struct node *newnode=NULL;
newnode= (struct node *) malloc(sizeof(struct node));
newnode->next=NULL;
printf("\nPlease add the student's data in the following order->> \nName \nID \nDate of birth (Day,Month,Year) \nScore \n");
scanf("%s",(newnode->data.name));
scanf("%d",&(newnode->data.id));
scanf("%d",&(newnode->data.day));
scanf("%d",&(newnode->data.month));
scanf("%d",&(newnode->data.year));
scanf("%d",&(newnode->data.score));
hashvalue=gethashvalue(newnode->data.name);
// finding the value of the key
key = hashvalue % size;
if(chain[key] == NULL)
{chain[key] = newnode;}
// if some elements are found on chain[key]
else{
struct node *temp = chain[key];
while (temp->next)
{temp=temp->next;
}
temp->next=newnode;
newnode->next=NULL;

}
}
void display()
{int i;
for( i=0; i<size ; i++){
struct node *temp = chain[i];
while(temp)
{
printf ("\nStudent's name: %s\n",temp->data.name);
printf ("Student's id: %d\n", temp->data.id);
printf ("Student's day  of birth: %d\n", temp->data.day);
printf ("Student's month of birth: %d\n", temp->data.month);
printf ("Student's year of birth:%d\n", temp->data.year);
printf ("Student's score: %d\n",temp->data.score);
printf ("----------------------------\n");
temp=temp->next;}
}
}
//we will search for a certain structure using name and id
void search(){
int number;
int flag=1;
char myname[50];
int hashvalue;
int key;
printf("\n please enter the name and the id of the person you are searching for");
scanf("%s",myname);
scanf("%d",&number);
hashvalue=gethashvalue(myname);
key = hashvalue % size;
    struct node *temp = chain[key];
while (temp)
{if(temp->data.id==number)
{printf("\n the student is found\n");
printf ("Student's name: %s\n",temp->data.name);
printf ("Student's id: %d\n", temp->data.id);
printf ("Student's day  of birth: %d\n", temp->data.day);
printf ("Student's month of birth: %d\n", temp->data.month);
printf ("Student's year of birth:%d\n", temp->data.year);
printf ("Student's score: %d\n",temp->data.score);
printf ("----------------------------\n");
 flag=0;
}
temp=temp->next;
}
if(flag==1)
{
 printf("\n the student is not found ");
}
}
//we will delete a certain structure using name and id

int delete(){
int number;
int flag=1;
char myname[50];
int hashvalue;
int key;
printf("\n please enter the name and the id of the person you want to delete");
scanf("%s",myname);
scanf("%d",&number);
hashvalue=gethashvalue(myname);
key = hashvalue % size;
 struct node *temp = chain[key], *remove;
   //search for student to be deleted
    if(temp != NULL)
    {
        if(temp->data.id == number)
        {
           remove = temp;
            temp = temp->next;
            free(remove);
            chain[key]=temp;
            return 1;
        }
        else
        {
            while(temp->next)
            {
                if(temp->next->data.id == number)
                {
                    remove = temp->next;
                    temp->next = temp->next->next;
                    free(remove);
                    return 1;
                }
                temp = temp->next;
            }
        }
    }

    return 0;



}










// this function convert characters to values according to ASCII CODE
int gethashvalue(char name[50]){
int x =0;
for (int i=0; i<50; i++)
{x=x+name[i];
if(name[i]==NULL)
break;}
return x; }


int main()
{

int x;
int choice;
int flag2=1;
initialize();
printf("welcome");
while(flag2)
{
printf("\n if you want to insert in hash table press 1");
printf("\n if you want to search in hash table press 2");
printf("\n if you want to delete in hash table press 3");
printf("\n if you want to end press 4");
printf("\n if you want to display hash table press 5");

scanf("%d",&choice);
if (choice==1)
insert();
else if(choice==2)
 search();
else if (choice==3)
{x=delete();
if(x==1)
printf("\n element is successfully deleted ");
else
printf("\n element is not found");
}
else if(choice==4)
 flag2=0;
else if (choice==5)
display();

else
printf("\n invalid input");
}

/*insert();
insert();
insert();
insert();
insert();
display();
x=delete();
if(x==1)
printf("\n element is successfully deleted ");
else
printf("\n element is not found");
display();*/
return 0;}
