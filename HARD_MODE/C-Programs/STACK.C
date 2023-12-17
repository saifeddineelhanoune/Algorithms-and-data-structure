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
node *top;
}stack;

stack *makestack()
{
stack *s;
s=(stack *)malloc(sizeof(stack));
s->top=NULL;
return (s);
}

void pushstack(stack *s,int val)
{
node *t;
t=(node *)malloc(sizeof(node));
t->info=val;
t->next=NULL;
if(s->top==NULL)
{
s->top=t;
}
else
{
t->next=s->top;
//s->top->next=t;
s->top=t;
}
}

int popstack(stack *s)
{
int f;
if(s->top==NULL)
{
printf("empty stack");
exit(0);
}
else
{
f=s->top->info;
printf("%d",f);
free(s->top);
s->top=s->top->next;

}
}

void peepstack(stack *s)
{
int f;
if(s->top==NULL)
{
printf("empty stack");
exit(0);
}
else
{
f=s->top->info;
printf("%d",f);
}
}

void main()
{
stack *q;
int v,i;
clrscr();
q=makestack();
printf("enter the values");
for(i=0;i<5;i++)
{
scanf("%d",&v);
pushstack(q,v);
}
peepstack(q);
printf("\nget val =");
popstack(q);
printf("\nsee after get top val =");
peepstack(q);
getch();
}
