#include <stdio.h>
#include <conio.h>
# define size 20
typedef struct
{
int arrsize[size];
int top;
}stack;

stack *makestack()
{
stack *s;
s=(stack *)malloc(sizeof(stack));
s->top=-1;
return (s);
}

void pushstack(stack *s,int val)
{
if(s->top==-1)
{
s->top++;
s->arrsize[s->top]=val;
}
else
{
s->top++;
s->arrsize[s->top]=val;
}

if(s->top>size-1)
{
printf("overflow");
exit(0);
}
}


int popstack(stack *s)
{
int a;
if(s->top==-1)
{
printf("underflow");
exit(0);
}
else
{
a=s->arrsize[s->top];
printf("%d",a);
free(a);
s->top--;
}
 }
void peepstack(stack *s)
{
int a;
a=s->arrsize[s->top];
printf("%d",a);
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
printf("\n see top value of stack=");
peepstack(q);
printf("\nnow get that seen value=");
popstack(q);
printf("\n now see next top most value of stack=");
peepstack(q);
getch();
}




