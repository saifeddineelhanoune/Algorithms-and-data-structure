#include<stdio.h>
#include<conio.h>
void main()
{
int a[10];//={-32767,83,5,7,9,2,15,20,45,10};
int i,k,temp,ptr;
clrscr();
for(i=0;i<10;i++)
scanf("%d",&a[i]);
for(k=2;k<10;k++)
{
temp=a[k];
ptr=k-1;
	while(a[ptr]>temp)
	{
		a[ptr+1]=a[ptr];
		ptr--;
	}
a[ptr+1]=temp;
}
for(i=1;i<10;i++)
printf("%d->",a[i]);
getch();
}



