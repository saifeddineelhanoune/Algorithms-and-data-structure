#include<stdio.h>
#include<conio.h>
void main()
{
int a[10],i,v;
clrscr();
for(i=0;i<5;i++)
scanf("%d",&a[i]);
printf("ntr the element 2 b found");
scanf("%d",&v);
for(i=0;i<5;i++)
{
if(a[i]==v)
{
printf("the position of element is=%d",i+1);
break;
}
}
if(i==5)
{
printf("no is not found");
}
getch();
}
