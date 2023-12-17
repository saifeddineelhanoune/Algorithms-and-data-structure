//stack through linklist
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
typedef struct node
{
int info;
struct node *left,*right;
}node;

typedef struct stack
{
 int top;
 struct node *data[20];
}stack;

typedef struct
{
node *root;
}tree;

stack *makestack()
{
stack *l;
l=(stack *)malloc(sizeof(stack));
l->top=-1;
return (l);
}

void push(stack *p,node *v)
{
if(p->top==-1)
	{
	p->top=0;
	p->data[p->top]=v;
	}
else
	{
	p->top++;
	p->data[p->top]=v;
	}
}

node *pop(stack *p)
{

node *t;
if(p->top==-1)
	{
	return(0);
	}
else
	{
	t=p->data[p->top];
	p->top--;
	return(t);
	}
}
 tree *maketree()
 {
 tree *t;
 t=(tree *)malloc(sizeof(tree));
 t->root=NULL;
 return t;
 }

 node *addnode(node *d,int v)
 {
	if(d==NULL)
	{
	  d=(node*)malloc(sizeof(node));
	  d->info=v;
	  d->left=NULL;
	  d->right=NULL;
	}
       else
	  if(v<d->info)
	    {
	       d->left=addnode(d->left,v);
	    }
	  else
	    {
	       d->right=addnode(d->right,v);
	    }
	  return d;
       }

 void addtree(tree *t,int v)
 {
 t->root=addnode(t->root,v);
 }

void preorder(tree *t)
{
stack *s;node *p,*q;
s=makestack();
p=t->root;
if(p!=NULL)
printf("%d",p->info);
if(p->right)
	push(s,p->right);
	p=p->left;
while (p)
	{
	if(p->right)
	push(s,p->right);
	printf("%d",p->info);
	p=p->left;
	}
while(s->top!=-1)
{
q=pop(s);
while (q)
{
if (q->right!=NULL)
push(s,q->right);
printf("%d",q->info);
q=q->left;
}
}
}
void inorder(tree *t)
{
node *p,*q,*k;
stack *s;
s=makestack();
p=t->root;
if(p)
push(s,p);
while(p->left)
{
push(s,p->left);
p=p->left;
}
while(s->top!=-1)
{
q=pop(s);
printf("%d",q->info);
if(q->right)
push(s,q->right);
k=q->right;
while(k->left)
{
push(s,k->left);
k=k->left;
}
}
}
void insertstack(stack *s,node *p)
{
 node *q,*r;
 q=p;
 while(q)
 {
  push(s,q);
   q=q->left;
  }
}

void postorder(tree *t)
{
node *p,*q,*k;
stack *s,*tr;
s=makestack();
tr=makestack();
p=t->root;
while(p)
{
push(s,p);
p=p->left;
}
while(s->top!=-1)
{
q=pop(s);
k=pop(tr);
if(q->info==k->info) printf("%d",q->info);
else
if(q->right == NULL) { printf("%d",q->info);push(tr,k); }
else
	{
	push(s,q);
	push(tr,k);
	push(tr,q);
	insertstack(s,q->right);
	}
 }
}
node *find(tree *t,int v,node **p,char c[])
{
node *n;
*p=NULL;
if(t->root!=NULL)
n=t->root;
else
exit(0);
while(n)
{
if(v==n->info)
return n;
else
if(v<n->info)
{
*p=n;
n=n->left;
c[0]='l';
}
else
{
*p=n;
n=n->right;
c[0]='r';
}
}
return 0;
}

void delnode(tree *t,int v)
{
node *n,*par,*q,*q1;
char c[2];
c[1]=NULL;
n=find(t,v,&par,c);
	if(n!=0)
	{
		if(n->left==NULL)
			q=n->right;
		if(n->right==NULL)
			q=n->left;
		else
		 if(n->left!=NULL && n->right!=NULL)
		 {
			q=n->right;
			while(q->left)
			{
				q1=q;
				q=q->left;
			}
				if(q->right!=NULL)
				q1->left=q->right;
				else
				{
				q1->left=NULL;
				q->left=n->left;
				if(n!=t->root)
				q->right=n->right;
				}
		 }
		if(par==NULL)
			t->root=q;
		else
			if(c[0]=='l')
			par->left=q;
			else
			par->right=q;
	}
}


void main()
{
int i,j,k,m;
tree *t;
node *p,*s,*h;
clrscr();
t=maketree();
printf("enter num to add:");
scanf("%d",&j);
for(i=0;i<j;i++)
{
printf("enter values:");
scanf("%d",&k);
addtree(t,k);
}
printf("\npreorder\n");
preorder(t);
printf("\ninorder\n");
inorder(t);
printf("\n postorder\n");
postorder(t);
printf("\nEnter the value of node to delete= ");
scanf("%d",&m);
delnode(t,m);
printf("\npreorder\n");
preorder(t);
getch();
}

