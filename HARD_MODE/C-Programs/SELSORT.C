//selection sort
#include<stdio.h>
#include<conio.h>
void main()
{
int temp,a[20],i,j,v;
clrscr();
for(i=0;i<10;i++)
scanf("%d",&a[i]);
for(i=0;i<9;i++)
{
for(j=i+1;j<10;j++)
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
printf("aftr sorting\n");
for(i=0;i<10;i++)
printf("%d \n",a[i]);
getch();
}