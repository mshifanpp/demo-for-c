#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node * next;
};
void main()
{
struct node * start=(struct node*)0;//null list
struct node *insert(struct node*,int);
struct node * delete(struct node*);
void display(struct node *);
int search(struct node*,int);
while(1)
{
printf("\n1.insert\n2.delete\n3.display\n4.saerch\n5.exit\n");
printf("your option :");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("item to insert:");
       scanf("%d",&item);
       start=insert(start,item);
       break;
case 2:start=delete(start);
       break;
case 3: display();
        break;
case 4:printf("item to search:");
        sacnf("%d",&item);
        ans=search(start,item)
        if(ans==1)
        printf("found---");
        else
        printf("note found");
        break;
case 5:exit(0);
}
}
}
        
