#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int que[SIZE],front=0,rear=0;//empty queue
void main()
{
void enqueue(int);
int dequeue(),opt,item,ans;
void display();
int search();
while(1)
{
printf("\n1.insert\n2.delete\n3.dipslay\n4.search\n5.Exit\n");
printf("your option :");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("item to insert :");
       scanf("%d",&item);
       enqueue(item);
       break;
case 2:item=dequeue();
        printf("Deleted item=%d\n",item);
        break;
case 3:display();
        break;
case 4:printf("item to search:");
        scanf("%d",&item);
        ans=search(item);
       if(ans)
        printf("found---:");
      else
        printf("not found");
        break;
case 5:exit(0);
}
}// End of main function
}
//Function to insert an item in circular queue
void enqueue(int data)
{
int r1;
r1=(rear+1)%SIZE;
if(r1==front)
printf("queue is full");
else
{
rear=r1;
que[rear]=data;
}
return;
}
//Function to delete an item from queue
int dequeue()
{
if (front==rear)
{
printf("empty queue");
exit(-1);
}
else
{front=(front+1)%SIZE;
return que[front];
}
}
//function to display queue contents 
void display()
{
int f=front,r=rear;
while(f!=r)
{
f=(f+1)%SIZE;
printf("%d,\n",que[f]);
}
return;
}
// function to serach in queue
int search(int item)
{
int f=front,r=rear;
while(f!=r)
{
f=(f+1)%SIZE;
if(que[f]==item)
return 1;
}
return 0;
}




