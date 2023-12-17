#include<stdio.h>
#include<conio.h>
#define size 20
int binarysearch(int a[],int v,int n)
{
 int top,bottom,mid;
 top=0;
 bottom=n-1;
 while(top<=bottom)
{
mid=(top+bottom)/2;
if(a[mid]==v)
return mid+1;
else
if(v>a[mid])
top=mid+1;
else
bottom=mid-1;
}
return 0;
}

void main()
{
int v,a[size],i,b;
clrscr();
printf("ntr the values:");
for(i=0;i<5;i++)
scanf("%d",&a[i]);
printf("ntr the value 2 b search");
scanf("%d",&v);
b=binarysearch(a,v,size);
printf("%d",b);
getch();
}
