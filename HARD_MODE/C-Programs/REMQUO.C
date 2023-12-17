#include <stdio.h>
#include <conio.h>
void main()
{
int a,q,b;
clrscr();
printf("entr the two num:");
scanf("%d %d",&a,&b);
for (q=0;a>=b;q++)
{
a=a-b;
}
printf("the remainder is =%d",a);
printf("the quotient is =%d",q);
getch();
}
