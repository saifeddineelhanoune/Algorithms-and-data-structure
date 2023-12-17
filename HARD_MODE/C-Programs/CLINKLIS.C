#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
typedef struct node
{
int info;
struct node *next;
}node;
typedef struct
{
node *first;
}cllist;


cllist *makecll()
{
cllist *l;
node *h;
l=(cllist *)malloc (sizeof(cllist));
h=(node *)malloc(sizeof(node));
l->first=h;
h->info=NULL;
h->next=h;
return(l);
}

void faddcll(cllist *l,int v)
{
node *n;
n=(node *)malloc(sizeof(node));
n->info=v;
n->next=l->first->next;
l->first->next=n;
}

void eaddcll(cllist *l,int v)
{
node *n,*p;
n=(node *)malloc(sizeof(node));
n->info=v;
p=l->first;
	while(p->next != l->first)
	{
	p=p->next;
	}
n->next=p->next;
p->next=n;
}

void printcll(cllist *l)
{
int t;
node *p;
p=l->first;
	while(p->next!=l->first)
	{
		t=p->next->info;
		printf("%d->",t);
		p=p->next;
	}
}

void maddcll(cllist *l,int v,int f)
{
node *t,*n;
n=(node *)malloc(sizeof(node));
n->info=v;
t=l->first;
		while(t->next->info != f)
		{
			t=t->next;
		}
			n->next=t->next;
			t->next=n;
}


void main()
{
cllist *c;
clrscr();
c=makecll();
faddcll(c,78);
faddcll(c,56);
eaddcll(c,89);
maddcll(c,45,78);
printcll(c);
getch();
}