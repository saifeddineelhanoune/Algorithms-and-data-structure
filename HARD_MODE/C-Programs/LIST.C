#include<stdio.h>
#include<conio.h>
#include<alloc.h>
	typedef struct  node
	{
		int info;
		struct node *next;
	}node;
	typedef struct
	{
		struct node *first;
	}list;


	list *makelist(void)
	{
		list *l;
	l=(list *)malloc(sizeof(list));
		l->first=NULL;
	return(l);
	}


	void faddnode(list *l,int n)
	{
		node *v;
			v=(node *)malloc(sizeof(node));
			v->info=n;
		if(l->first==NULL)
			{
			v->next=NULL;
			l->first=v;
			}
		else
		{
			v->next=l->first;
			l->first=v;
		}
	}


	void laddnode(list *l,int n)
	{
	node *v,*t;
	v=(node *)malloc(sizeof(node));
	v->info=n;
	if(l->first==NULL)
	{
	v->next=NULL;
	l->first=v;
	}
	else
	{
	t=l->first;
	while(t->next!=NULL)
		t=t->next;
	v->next=NULL;
	t->next=v;
	}
	}


  void *maddnode(list *l,int n,int t)
	{
		node *v,*s;
		v=(node *)malloc(sizeof(node));
		v->info=n;
	       s=l->first;
		while(s->info!=t)
		{
		s=s->next;
		}
		v->next=s->next;
		s->next=v;
	 }
	void *printlist(list *l)
	{
		node *t;
		t=l->first;
		while(t->info!=NULL)
		{
		printf("%d\n",t->info);
		t=t->next;
		}
	}
   void delnode(list *l,int n)
   {
	node *p,*s;
	if(l->first==NULL)
	{
	printf("empty");
	exit(0);
	}
	s=l->first;
	if(l->first->info==n)
	l->first=s->next;
	else
	{
	p=s;
	while(s->info!=n)
	{
	p=s;
	s=s->next;
	}
	p->next=s->next;
	}
  }


	void main()
	{
	list *p;   int a;
	clrscr();
	p=makelist();
	faddnode(p,33);
	faddnode(p,60);
	maddnode(p,55,60);
	laddnode(p,89);
	printlist(p);
	printf("enter val to b del =");
	scanf("%d",&a);
	delnode(p,a);
	printlist(p);
	getch();
	}
