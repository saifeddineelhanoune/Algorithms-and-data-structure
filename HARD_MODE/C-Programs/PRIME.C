#include <stdio.h>
#include <conio.h>
void main()
{
int n,ctr;
clrscr();
printf("entr the num:");
scanf("%d",&n);
for (ctr=2;ctr<=n/2;ctr++)
{
if (n%ctr==0)
break;
}


if (ctr>n/2)
printf("%d no is prime",n);
else
printf("%d no is not prime",n);
getch();
}

