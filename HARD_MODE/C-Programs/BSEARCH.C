//binary search
#include<stdio.h>
#include<conio.h>
int binarysearch(int a[],int v,int n)
{
int top=0,bottom=n-1;int mid;
while(top<=bottom)
{
mid=(top+bottom)/2;
if(a[mid]==v)
return mid;
else if(v>a[mid])
top=mid+1;
else
bottom=mid-1;
}
return -1;
}

void main()
{
int v,a[20],i,b;
clrscr();
printf("ntr the values:");
for(i=0;i<9;i++)
scanf("%d",&a[i]);
printf("ntr the value 2 b search");
scanf("%d",&v);
b=binarysearch(a,v,9);
printf("the pos is at %d",b);
getch();
}
