#include <stdio.h>
#include <conio.h>
void main()
{
int n[10],ctr,max=0;
clrscr();
printf("entr the num:");
for (ctr=1;ctr<=10;ctr++)
{
scanf("%d",&n[ctr]);
if (n[ctr]>max)
max=n[ctr];
}
printf("the max no is=%d",max);
getch();
}