#include<stdio.h>
struct date
{
int dd,mm,yy;
};

int main()
{
struct date d,*p;
int is_leap(int);
p=&d;
printf("enter a date[dd-mm-yy]:");
scanf("%d-%d-%d",&p->dd,&p->mm,&p->yy);
if (is_leap(p->yy))
printf(" it is a leap year");
else
printf(" not a leap year");
}
int is_leap(int y)
{
if((y%4==0&&y%100!=0)||y%400==0)
return 1;
else
return 0;
}




