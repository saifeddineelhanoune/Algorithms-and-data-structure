#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
typedef struct node
{
int info;
struct node *prev;
struct node *next;
}node;

typedef struct
{
struct node *first;
}dll;

dll *makedll()
{
dll *l;
l=(dll *)malloc(sizeof(dll));
l->first=NULL;
return(l);
}

void fadddll(dll *l,int v)
{
node *n,*p;
n=(node *)malloc(sizeof(node));
n->info=v;
	if(l->first==NULL)
		{
			l->first=n;
			n->prev=NULL;
			n->next=NULL;
		}
	else
		{
			p=l->first;
			p->prev=n;
			n->next=p;
			n->prev=NULL;
			l->first=n;
		}
}

void enddll(dll *l,int v)
{
node *n,*p;
n=(node *)malloc(sizeof(node));
n->info=v; //n->next=NULL;
	if(l->first==NULL)
	{
		l->first=n;
		n->prev=NULL;
		n->next=NULL;
	}
	else
	{
		p=l->first;
		while(p->next != NULL)
			p=p->next;
			n->next=NULL;
			p->next=n;
			n->prev=p;

	}
}


void madddll(dll *l,int v,int f)
{
node *n,*p;
int flag=0;
n=(node *)malloc (sizeof(node));
n->info=v;
p=l->first;
	while(p->next!=NULL)
	{
		if(p->info==f)
		{
			flag=1;
			break;
		}
	 p=p->next;
	}
		if(flag==0)
			printf("node can't be inserted");
		else
		{
			n->next=p->next;
			n->prev=p;
			p->next->prev=n;
			p->next=n;
		}
}

void deldll(dll *l,int m)
{
node *p,*t;
int flag=0;
	if(l->first==NULL)
	{
		printf("empty dll");
	}
	else
	{
		p=l->first;
		while(p)
		{
			if(p->info==m)
			{
				flag=1;
				break;
			}
		p=p->next;
		}
			if(flag==0)
				printf("node can't b deleted");
			else if((p->prev==NULL) && (p->next==NULL))
				l->first=NULL;
				else
				if(p->prev==NULL)
				{
					l->first=p->next;
					p->next->prev=NULL;
				}
				else
				if(p->next==NULL)
					p->prev->next=NULL;
				else
				{
					p->prev->next=p->next;
					p->next->prev=p->prev;
				}
	}
}

void printdll(dll *l)
{
node *p;
	if(l->first==NULL)
	{
		printf("empty dll");
		exit(0);
	}
	else
	{
		p=l->first;
		while(p)
		{
			printf("%d->",p->info);
			p=p->next;
		}
	}
}

void main()
{
dll *a;
int v;
clrscr();
a=makedll();
fadddll(a,7);
fadddll(a,10);
madddll(a,5,10);
enddll(a,8);
printdll(a);
printf("\n enter the value to b deleted=");
scanf("%d",&v);
deldll(a,v);
printdll(a);
getch();
}