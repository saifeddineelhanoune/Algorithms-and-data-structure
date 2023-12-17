//tree throuogh  link list
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>
typedef struct node
	{
	struct node *left,*right;
	int info;
	}node ;

typedef struct tree
	{
	node *root;
	}tree;

tree *maketree()
{
tree *t;
t=(tree *)malloc(sizeof(tree));
t->root=NULL;
return (t);
}

node *addnode(node *d,int v)
{
if(d==NULL)
	{
	d=(node *)malloc(sizeof(node));
	d->info=v;
	d->left=NULL;
	d->right=NULL;
	}
else
if(v==d->info)
	{
	return 0;
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
return(d);
}

void preorder(node *d)
{
if(d)
	{
	printf("%d",d->info);
	preorder(d->left);
	preorder(d->right);
	}
}

void inorder(node *d)
{
if (d)
	{
	inorder(d->left);
	printf("%d",d->info);
	inorder(d->right);
	}
}

void postorder(node *d)
{
if(d)
	{
	postorder(d->left);
	postorder(d->right);
	printf("%d",d->info);
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
					c[0]='L';
				}
				else
				{
					*p=n;
					n=n->right;
					c[0]='R';
				}
			}
return(0);
}

void addtree(tree *t,int v)
{
t->root=addnode(t->root,v);
}

void delnode(tree *t,int v)
{
node *n,*per,*q,*q1;
char c[2];
c[1]=NULL;
n=find(t,v,&per,c);
	if(n!=0)
	{
		if(n->left==NULL)
			q=n->right;
		else
		if(n->right==NULL)
			q=n->right;
	 }
	 else
	 {
		if(n->left!=NULL && n->right!=NULL)
			q=n->right;
			while(q->left)
				{
					q1=q;
					q=q->left;
				}
				if(q->right!=NULL)
					q1=q->right;
				else
				{
					q1->left=NULL;
					q->left=n->left;
					q->right=n->right;
				}
	   }

	if(per==NULL)
	t->root =q;

	if(c[0]=='L')
		per->left=q;
	else
		per->right=q;

}

void main()
{
tree *t;
int v,i;
node *n;
clrscr();
t=maketree();
printf("\n");
for(i=0;i<3;i++)
{
printf("\nEnter the value of tree = ");
scanf("%d",&v);
addtree(t,v);
}
printf("\n");
postorder(t->root);
printf("\n entr value to b del =");
scanf("%d",&v);
delnode(t,v);
printf("\n");
postorder(t->root);
getch();
}