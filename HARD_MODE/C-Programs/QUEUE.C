#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <process.h>
typedef struct
{
int info;
struct node *next;
}node;

typedef struct
{
 node *first;
 node *last;
}queue;

queue *makequeue()
{
queue *q;
q=(queue *)malloc(sizeof(queue));
q->first=NULL;
q->last=NULL;
return (q);
}

void addqueue(queue *q,int val)
{
node *t;
t=(node *)malloc(sizeof(node));
t->info=val; t->next=NULL;
if((q->first==NULL)&&(q->last==NULL))
{
q->first=t;
q->last =t;
}
else
{
q->last->next=t;
q->last=t;
}
}


void delqueue(queue *q)
{
node *t;
if((q->first==NULL)&&(q->last==NULL))
{
printf("queue is empty");
exit(0);
}
else
{
t=q->first;
q->first=t->next;
free(t);
}
}

void printqueue(queue *q)
{
node *s;
s=q->first;
while(s!=NULL)
{
printf("%d",s->info);
s=s->next;
}
}

void main()
{
queue *a;
int v,i;
clrscr();
a=makequeue();
printf("enter the values");
for(i=0;i<5;i++)
{
scanf("%d",&v);
addqueue(a,v);
}
printqueue(a);
delqueue(a);
printf("\n");
printqueue(a);
delqueue(a);
printf("\n");
printqueue(a);
getch();
}




