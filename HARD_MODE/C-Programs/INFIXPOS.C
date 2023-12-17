#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include<string.h>
#include <process.h>
#include<stdlib.h>
#define size 20
typedef struct
	{
		char arrsize[size];
		int top;
	}stack;

stack *makestack()
{
stack *s;
s=(stack *)malloc(sizeof(stack));
s->top=-1;
return s;
}

void push(stack *s,char val)
{
	if(s->top == -1)
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

 char pop(stack *s)
 {
 char a;
	 if(s->top==-1)
	 {
		 printf("underflow");
		 exit(0);
	 }
	 else
	 {
		 a=s->arrsize[s->top];
		 s->top--;
		 return(a);
	 }
 }

 char peep(stack *s)
 {
 char a;
 a=s->arrsize[s->top];
 return(a);
 }

 int pre(char a)
 {
 int b;
		 switch(a)
		   {
			 case '(': b=0;break;
			 case '+':
			 case '-':b=1;break;
			 case '*':
			 case '/':b=2;break;
			 case '$':b=3;break;
		 }
 return b;
 }

 void intopost()
 {
 char in[size],pos[size],a,d;
 int i,j,k;
 stack *s;
		pos[0]=NULL;
 printf("plz enter infix xpression");
scanf("%s",in);
		i=strlen(in);
		in[i]=')';
		in[i+1]='\0';
	s=makestack();
	push(s,'(');
	for(i=0,j=0;in[i]!='\0';i++)
	{
			a=in[i];
		if((a>='a' && a<= 'z')||(a>='A' && a<='Z'))
		{
			pos[j]=a;
			j++;
		}
		else
		if(a=='(')
			push(s,'(');
		else
		if(a=='+'||a=='-'||a=='*'||a=='/'||a=='$')
		{
		while(pre (a)<=pre(peep(s)) )
			{
				d=pop(s);
				pos[j]=d;
				j++;
			}
		push(s,a);
		}
		else
			if(a==')')
			{
				while(peep(s)!='(')
				{
					d=pop(s);
					pos[j]=d;
					j++;
				}
					d=pop(s);
			}
	}

pos[j]='\0';
printf("%s",pos);
}


void main()
{
stack *a;
int v;
clrscr();
intopost();
getch();
}






