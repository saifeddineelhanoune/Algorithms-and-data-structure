#include<iostream.h>
#include<conio.h>
#include<process.h>
inline void prime(int a,int b)
{
	int i,cnt;
	for(i=500;i<=700;i++)
	{
	for(cnt=2;cnt<=i/2;cnt++)
	{
	if(i%cnt==0){	cout<<"not prime"<<i<<endl;
			break;
		    }
	}
	if(cnt>i/2)
	{
	cout<<"no is prime"<<i;
	}
	}
}

void main()
{        int x,y;
	clrscr();
       prime(x,y);
       getch();
}