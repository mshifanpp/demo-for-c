#include<stdio.h>
#include<stdlib.h>
int stack[10];
int sp=-1;
int size=10;
void main()
{ 
void push(int);
int pop(),opt,item;
void display();
do
{
printf("\n1.push\n2.pop\n3.display\n4.Exit\n");
printf("your option :");
scanf("%d",&opt);
switch(opt)
{
case 1: printf("Item to push:");
        scanf("%d",&item);
        push(item);
        break;
case 2: item=pop();
        printf("poped item=%d",item);
        break;
case 3:display();
        break;
case 4:exit(0);
}
}
while(1);
}//end of main
//function to push an item
void push(int data)
{
    if(sp==size)
    { printf("stack fall\n");
    return;}
    else
    stack[++sp]=data;
    return;
  }
//function pop an item
int pop()
{ if (sp==-1){

printf("empty stack\n");
exit(1);
}
else 
return stack[sp--];
}
//display stack contents
void display()
{ int i;
for(i=sp;i>=0;--i)
printf("%d  ", stack[i]);
return;
}

