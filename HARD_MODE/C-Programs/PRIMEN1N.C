#include <stdio.h>
#include <conio.h>
void main()
{
int n,n1,n2,ctr,j;
clrscr();
printf("entr the 1st num");
scanf("%d",&n1);
printf("entr the 2nd num");
scanf("%d",&n2);
for(n=n1;n<=n2;n++)
{
for(ctr=2;ctr<=n/2;ctr++)
{
if (n%ctr==0)
break;
}
if (ctr>n/2)
{
printf("\n%d is prime",n);
j++;
}
printf("\n%d",j);
else
printf("\n%d is not prime",n);
getch();
}
}