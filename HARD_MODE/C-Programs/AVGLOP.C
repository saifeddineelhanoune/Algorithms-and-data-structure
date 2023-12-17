#include <stdio.h>
#include <conio.h>
void main()
{
int c,sum=0,nv=0,n,num;
float avg;
clrscr();
printf("entr the num:");
scanf("%d",&n);
sum=0;
for (c=1,nv=0;c<=n;c++)
{
scanf("%d",&num);
if (num<=0)
{
nv++;
continue;
}
sum+=num;
}
c--;
avg=(float)sum/(c-nv);
printf("sum=%d,avg=%f",sum,avg);
printf("\ntotal no. is %d",c);
printf("\ntotal no. is -ve nos is %d",nv);
getch();
}
