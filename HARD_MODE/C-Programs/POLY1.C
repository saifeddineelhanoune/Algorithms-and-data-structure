#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
typedef struct{
		float coeff;
		int exp;
		struct node *next;
		}node;

 typedef struct{
		node *first;
		node *last;
		}poly;

  poly *makepoly()
  {poly *p;
  p=(poly*)malloc(sizeof(poly));
  p->first=p->last=NULL;
  return p;
  }


  void addpoly(poly *p,float c,int e)
  { node *t,*o,*s,*n;
    if(c==0){printf("error");getch();exit(1);}
    n=(node*)malloc(sizeof(node));
    n->coeff=c;
    n->exp=e;
    n->next=NULL;
    if(p->first==NULL)
      {p->first=n;
      p->last=n;
      }
      else
	 {  t=p->first;
	    while(t!=NULL&&t->exp>e)
	    {  o=t;
	       t=t->next;
	    }
	    if(t==p->first&&(t->exp!=e||t->exp==e))
	    { p->first=n;
	      n->next=t;
	    }
	    else if(t->exp!=e||t->exp==e)
	    { o->next=n;
	    n->next=t;
	    }
       }
  }

  poly *addtwopoly(poly *p,poly *q)
  {   poly *s;node *t,*o;float sum;
      s=makepoly();
      t=p->first;
      o=q->first;

      while(t&&o)
      {  if(t->exp==o->exp)
	  {
	  sum=t->coeff+o->coeff;
	  addpoly(s,sum,t->exp);
	  t=t->next;
	  o=o->next;
	  }
	  if(t!=NULL)
	  {
	  addpoly(s,t->coeff,t->exp) ;
	  t=t->next;
	  }
	  else if(o!=NULL)
	  {
	  addpoly(s,o->coeff,o->exp);
	  o=o->next;
	  }
      }
	return s;
  }

  poly *multtwopoly(poly *p,poly *q)
  {
  poly *mult;node *t,*o;float a;int b;
  mult=makepoly();
  o=p->first;
  t=q->first;
  while(t)
    {
       while(o)
       {
       a=t->coeff*o->coeff;
       b=t->exp+o->exp;
	  addpoly(mult,a,b);
	  o=o->next;
       }
       o=p->first;
     t=t->next;
   }
   return mult;
 }

  void printpoly(poly *p)
  {  node *t;
     if(p->first==NULL)
       printf("empty list\n");
       else
	  { t=p->first;
	     while(t)
	     { printf("%fX^%d+",t->coeff,t->exp);
	     t=t->next;
	     }
	 }
 }

    void main()
     {
      poly *p,*q,*r,*k;
	clrscr();
	p=makepoly();
	q=makepoly();
	addpoly(p,2,4);
	addpoly(p,3,3);
	addpoly(q,4,3);
	addpoly(q,5,0);
     k=addtwopoly(p,q);
      printpoly(k);
	printf("\n");
	r=multtwopoly(p,q);
	printpoly(r);
	getch();
    }
