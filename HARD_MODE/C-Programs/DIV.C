#include<stdio.h>
#include <conio.h>
void main()
{
int n;
clrscr();
printf("entr the num:");
scanf("%d",&n);
if ((n%6==0)&&(n%9==0))
printf("\nno is div by 3,6,9");
else
if (n%9==0)
printf("\nno is div by 9,3");
else
if (n%6==0)
printf("\nno is div by 6,3");
else
if (n%3==0)
printf("\nno is div by 3");
else
printf("no is not div by 3,6,9");
getch();
}
