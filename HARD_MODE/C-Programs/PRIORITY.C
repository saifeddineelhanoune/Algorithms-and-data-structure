#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>
typedef struct node
{
int info,pri;
struct node *next;
}node;
typedef struct
{
node *first;
}pq;
pq *makequeue()
{
pq *p;
p=(pq *)malloc(sizeof(pq));
p->first=NULL;
return p;
}
void addnode(pq *p,int v1,int p1)
{
node *n,*t,*s;
n=(node *)malloc(sizeof(node));
n->info=v1;
n->pri=p1;
if(p->first==NULL)
{
p->first=n;
n->next=NULL;
}
else
{
t=p->first;
while(t->pri > p1)
{
s=t;
t=t->next;
}
if(t==p->first)
 {
  n->next=p->first;
  p->first=n;
 }
 else
  {
s->next=n;
n->next=t;
 }
}
}

void printqueue(pq *p)
{
int t;
node *n;
if(p->first==NULL)
{
printf("empty list");
exit(0);
}
else
 n=p->first;
 while(n)
 {
  t=n->info;
  printf("%d",t);
  n=n->next;
  }

}
void main()
{
pq *a; int i,v,p;
clrscr();
a=makequeue(); 
for(i=0;i<5;i++)
{
printf("entr the values ");
scanf("%d",&v);
printf("entr prio");
scanf("%d",&p);
addnode(a,v,p);
}
printqueue(a);
getch();
}