#include<stdio.h>
#include<conio.h>
int bin(int);
main()
{
	int n;
	clrscr();
	printf("enter a number:");
	scanf("%d",&n);
	printf("binary equivilent of %d is %d",n,bin(n));
	getch();
}
	int bin(int b)
	{
		int r=0,res=0;
		while(b>0)
	    {
	      r=r*10+b%2;
	      b=b/2;
	    }
		while(r>0)
		{  res=res*10+r%10;
		   r=r/10;
		}
		   return res;
	    }
