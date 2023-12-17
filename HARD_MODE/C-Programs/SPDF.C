#include<stdio.h>
#include<conio.h>
main()
{

	int x,n,res;
	clrscr();
	printf("enter x & no of terms");
	scanf("%d%d",&x,&n);
	res=sum(x,n);
	printf("res=%d",res);
	getch();
}
	int sum(int x,int n)
	{
		int s=0,i;
		for(i=1;i<=n;i++)
		s=s+power(x,i)/fact(i);
		return s;
	}
		int power(int x,int i)
		{
			int z=1;
			for(;i>0;i--)
			z=z*x;
			return z;
		}
		       int fact(int i)
		       {	int f=1;
				for(;i>1;i--)
				f=f*i;
				return f;
		       }
