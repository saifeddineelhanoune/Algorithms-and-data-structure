#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>
typedef struct node
{
int info;
struct node *left,*right;
}node;

typedef struct
 {
 node *root;
 }tree;

tree *maketree()
{
tree *t;
t=(tree *)malloc(sizeof(tree));
t->root=NULL;
return(t);
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
		return (d);
	}
	else
	if(v < d->info)
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
		printf("%d->",d->info);
		preorder(d->left);
		preorder(d->right);
	}
}
void inorder(node *d)
{
	if(d)
	{
		inorder(d->left);
		printf("%d->",d->info);
		inorder(d->right);
	}
}
void postorder(node *d)
{
	if(d)
	{
		postorder(d->left);
		postorder(d->right);
		printf("%d->",d->info);
	}
}
void addtree(tree *t,int v)
{
t->root=addnode(t->root,v);
}

void main()
{
tree *s;
int i,v;
clrscr();
s=maketree();
for(i=0;i<6;i++)
{
scanf("%d",&v);
addtree(s,v);
}
printf("tree in preorder:");
preorder(s->root);
printf("\n tree in inorder:");
inorder(s->root);
printf("\n tree in postorder:");
postorder(s->root);
getch();
}
