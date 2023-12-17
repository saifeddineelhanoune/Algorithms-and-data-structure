#include<stdio.h>
#include<conio.h>
#include<alloc.h>
	typedef struct node
	{
	int info,row,col;
	struct node *left,*up;
	}node;

	typedef struct
	{
	int numrow,numcol;
	 node *arow,*acol;
	}spmatrix;

spmatrix *creatmatrix(int r,int c)
	{
	spmatrix *l;
	int i,j;
	l=(spmatrix *)malloc(sizeof(spmatrix));
	l->numrow=r;
	l->numcol=c;
	l->arow=(node *)malloc (sizeof(node) * r);
	l->acol=(node *)malloc(sizeof(node) * c);
		for(i=0;i<r;i++)
		{
			l->arow[i].left=&l->arow[i];
			l->arow[i].col=-1;
			l->arow[i].row=i;
		}
		for(j=0;j<c;j++)
		{
			l->acol[j].up=&l->acol[j];
			l->acol[j].row=-1;
			l->acol[j].col=j;
		}
	return(l);
	}


void smput(spmatrix *l,int r,int c,int v)
{
node *s,*p,*t;
	if((r>=0 && r<l->numrow)||(c>=0 && c<l->numcol))
	{
		s=(node *)malloc(sizeof(node));
		s->info=v;
		s->row=r;
		s->col=c;
		p=&l->arow[r-1];
		while(p->left->col > c)
			p=p->left;
			if(p->left->col != c)
			{
				s->left=p->left;
				p->left=s;
			}
		t=& l->acol[c-1];
		while(t->up->row > r)
			t=t->up;
			if(t->up->row != r)
			{
				s->up=t->up;
				t->up=s;
			}
	    }
			else
				printf("node cannot b insert");
}



int smget(spmatrix *l,int r,int c)
{
node *s,*p;
if((r>=0 && r<l->numrow)||(c>=0 && c<l->numcol))
{
p=l->arow[r-1].left;
	while(c<p->col)
	{
		p=p->left;
	}
	if(p->col == c)
	{
	printf("%d",p->info);
	}
	else
	return(0);
}
else
printf("node has wrong value");
}

void main()
{
spmatrix *s;
clrscr();
s=creatmatrix(3,3);
smput(s,2,2,9);
smget(s,2,2);
printf("\n");
smput(s,2,1,1);
smget(s,2,1);
printf("\n");
smput(s,2,3,8);
smget(s,2,3);
getch();
}