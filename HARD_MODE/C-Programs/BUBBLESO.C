#include<stdio.h>
#include<conio.h>
#define size 5
void main()
  {
  int a[size],i,j,k,temp,flag;
  int as=size-1;
  clrscr();
    for(i=0;i<size;i++)
      scanf("%d",&a[i]);
     for(i=0;i<as;i++)
      {
	    flag=0;
	    for(j=0;j<as-i;j++)
		   if(a[j]>a[j+1])
		    {
		      flag=1;
		      temp=a[j];
		      a[j]=a[j+1];
		      a[j+1]=temp;
		    }
	    if(flag==0)
	    break;
	    as--;
      }
    for(i=0;i<size;i++)
    printf("%d->",a[i]);
    getch();
}