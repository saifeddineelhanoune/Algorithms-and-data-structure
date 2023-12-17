#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
#define size 20
typedef struct nonleaf
	 {
			int ldata;
			struct node *lptr;
			int mdata;
			struct node *mptr;
			struct node *rptr;
		}nonleaf;

typedef struct node
{
	int tag;
	int data;
	struct nonleaf   nonl;
}node;

typedef struct
{
struct node *root;
}tree;
tree *maketree()
{
tree *t;
t=(tree *)malloc(sizeof(tree));
t->root=NULL;
return t;
}
typedef struct
{
int top;
node *arr[size];
}stack;

stack *makearr()
{
stack *s;
s=(stack *)malloc(sizeof(stack));
s->top=-1;
return(s);
}

void push(stack *s,node *v)
{
	if(s->top==-1)
	  {
	    s->top++;
	    s->arr[s->top]=v;
	  }
	else
	  {
	    s->top++;
	    s->arr[s->top]=v;
	  }
}
node  *pop(stack *s)
{
node *a;
	if(s->top==-1)
	  {
	    printf("Empty stack");
            return(0);

	  }
	else
	  {
	    a=s->arr[s->top];
	    s->top--;
	    return(a);
	  }

}

stack *s;
void rebalanceinsert(node *p,node *new1,int loc)
    {
     node *p1,*nroot;
     stack *s;
     node *g;
       p1=(node *)malloc(sizeof(node));
     p1->tag=1;
       p1->nonl.rptr=NULL;
	       if(loc==1)
	       {
	       p1->nonl.lptr=p->nonl.mptr;
	       p1->nonl.mptr=p->nonl.rptr;
	       p->nonl.mptr=p->nonl.lptr;
	       p->nonl.lptr=new1;
	       p1->nonl.ldata=p->nonl.mdata;
	       p1->nonl.mdata=p->nonl.rptr->data;
	       p->nonl.mdata=p->nonl.ldata;
	       p->nonl.ldata=new1->data;
	       }
	       else
	       if(loc==2)
	       {
	       p1->nonl.lptr=p->nonl.mptr;
	       p1->nonl.mptr=p->nonl.rptr;
	       p->nonl.mptr=new1;
	       p1->nonl.ldata=p->nonl.mdata;
	       p1->nonl.mdata=p->nonl.rptr->data;
	       p->nonl.mdata=new1->data;
	       }
	       else
	       if(loc==3)
	       {
	       p1->nonl.lptr=new1;
	       p1->nonl.mptr=p->nonl.rptr;
	       p1->nonl.ldata=new1->data;
	       p1->nonl.mdata=p->nonl.rptr->data;
	       }
	       else
	       if(loc==4)
	       {
	       p1->nonl.lptr=p->nonl.rptr;
	       p1->nonl.mptr=new1;
	       p1->nonl.ldata=p->nonl.rptr->data;
	       p1->nonl.mdata=new1->data;
	       }
      if(s->top==NULL)
	       {
	       nroot=(node *)malloc(sizeof(node));
	       nroot->tag=1;
	       nroot->nonl.rptr=NULL;
	       nroot->nonl.lptr=p;
	       nroot->nonl.mptr=p1;
	       nroot->nonl.ldata=p->nonl.mdata;
	       nroot->nonl.mdata=p1->nonl.mdata;
	       push(s,nroot);
	       }
	       else
	       {
	       g=pop(s);
	       if(g->nonl.lptr==p)
	       loc=2;
	       else
	       if(g->nonl.mptr==p)
	       loc==3;
	       else
	       if(g->nonl.rptr==p)
	       loc==4;
	       if(g->nonl.rptr==NULL)
	       {
	       if(loc==2)
	       {
	       g->nonl.rptr=g->nonl.mptr;
	       g->nonl.mptr=p1;
	       g->nonl.mdata=p1->nonl.mdata;
	       }
	       else
	       if(loc==3)
	       g->nonl.rptr=p1;
	       }
	       else
	       rebalanceinsert(g,p,loc);
	       }
	       }


void findpath(node *n,int key)
{
    node *curr;
     curr=n;
     s=makearr();
	     while(curr->tag!=0)
	     {
	     push(s,curr);
	     if(key<=curr->nonl.ldata)
	     curr=curr->nonl.lptr;
	     else
	     if(key<=curr->nonl.mdata)
	     curr=curr->nonl.mptr;
	     else
	     if(curr->nonl.rptr!=NULL)
	     curr=curr->nonl.rptr;
	     else
	     break;
	     }
    }


node *insert(tree *t,int v)
{
struct node *nroot;
struct node *new1,*parent;
int pos;
new1=(node *)malloc(sizeof(node));
new1->tag=0;
new1->data=v;
if (t->root==NULL)
return new1;

	if(t->root->tag==0)
	{
	 nroot=(node *)malloc(sizeof(node));
	 t->root->tag=1;
	 nroot->nonl.rptr=NULL;
	 if(v<t->root->data)
	 {
	 nroot->nonl.lptr=new1;
	 nroot->nonl.mptr=t->root;
	 nroot->nonl.ldata=v;
	 nroot->nonl.mdata=t->root->data;
	 }
	 else
	 {
	 nroot->nonl.lptr=t->root;
	 nroot->nonl.mptr=new1;
	 nroot->nonl.ldata=t->root->data;
	 nroot->nonl.mdata=v;
	 }
	 return nroot;
	}
	 findpath(t->root,v);
	 parent=pop(s);
	 if(parent->nonl.rptr==NULL)
	 {
		if(v<parent->nonl.ldata)
		{
		parent->nonl.rptr=parent->nonl.mptr;
		parent->nonl.mptr=parent->nonl.lptr;
		parent->nonl.lptr=new1;
		parent->nonl.mdata=parent->nonl.ldata;
		parent->nonl.ldata=v;
		}
		else
		if(v<parent->nonl.mdata)
		{
		parent->nonl.rptr=parent->nonl.mptr;
		 parent->nonl.mptr=new1;
		 parent->nonl.mdata=v;
		 }
		 else
		 parent->nonl.rptr=new1;
		 return t->root;
		 }

     else
     if(v<parent->nonl.ldata)
	     pos=1;
	     else
	     if(v<parent->nonl.mdata)
	     pos=2;
	     else
	     if(v<parent->nonl.rptr->data)
	     pos=3;
	     else
	     pos=4;
	     rebalanceinsert(parent,new1,pos);
	     return t->root;
      }

   void main()
   {
   tree *t;
   int i,a;
   t=maketree();
   for(i=0;i<3;i++)
   {
   scanf("%d",&a);
   insert(t,a);
   }
   getch();
   }

