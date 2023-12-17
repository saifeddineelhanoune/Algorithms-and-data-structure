#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
	typedef struct
	{
		int row;
		int col;
		int *buffer;
	}darray;


	darray  *makedarray(int r,int c)
	{
		darray *data;
		if(r<=0||c<=0)
		{
			printf("wrong r,c");
			exit(1);
		}
	data=(darray *)malloc(sizeof (darray));
			data->row=r;
			data->col=c;
	data->buffer=(darray *)malloc(sizeof(int) * r * c);
		return(data);
	}


	void *putdarray(darray *m,int r,int c,int val)
	{
		if(r<0&&r>m->row && c<0&&c>m->col)
			{
				printf("wrong no of rows and col");
				exit(1);
			}
		m->buffer[r * m->col + c]=val;
	}


	int *getdarray(darray *m,int r,int c)
	{
			int of;
		if(r<0&&r>m->row && c<0&&c>m->col)
			{
				printf("wrong row & col");
				exit(1);
			}
		   of=r * m->col + c;
		return(m->buffer[of]);
	}


	void printdarray(darray *m)
	{
			int i,j,a,cnt;
		for(i=0;i<m->row;i++)
		{
			for(j=0;j<m->col;j++)
				{
					a=getdarray(m,i,j);
					printf("%d",a);
				}
		}
	}



	void main()
	{
		darray *l;
		int i,j,n;
	clrscr();
		l=makedarray(3,4);
		for(i=0;i<3;i++)
		{
			for(j=0;j<4;j++)
			{
				scanf("%d",&n);
				putdarray(l,i,j,n);
			}
		}
		printdarray(l);
	 getch();
	}