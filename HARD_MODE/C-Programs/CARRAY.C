
 #include<stdio.h>
 #include <conio.h>
 #include <alloc.h>
 #include <process.h>
 # define size 20

 typedef struct
 {
 int arrsize[size];
 int first;
 int last;
 }cqueue;

 cqueue *makecqueue()
 {
 cqueue *s;
 s=(cqueue *)malloc(sizeof(cqueue));
 s->first=-1;
 s->last=-1;
 return (s);
 }

 void addcqueue(cqueue *s,int val)
 {
 if((s->first==-1)&&(s->last==-1))
 {
 s->first=0;
 s->last=0;
 s->arrsize[s->last]=val;
 }
 else
 if((s->first==0)&&(s->last==size-1))
 {
 printf("overflow");
 }
 else
  if((s->first!=0) && (s->last==size-1))
   {
    s->last=0;
    s->arrsize[s->last]=val;
   }
   else
    {
     s->last++;
     s->arrsize[s->last]=val;
    }
 }

 void printcqueue(cqueue *s)
 {
  int t,k;
  k=s->first;
  if(s->first==s->last)
  {
  t=s->arrsize[s->first];
  printf("%d",t);
  }
  else
  while(k!=s->last+1)
  {
 t=s->arrsize[k];
  printf("%d,",t);
  k++;
  }
  }
void delcqueue(cqueue *s)
 {
 int t;
 if((s->first==-1)&&(s->last==-1))
 {
 printf("empty cqueue");
 exit(0);
 }
 else
  if(s->first==s->last)
  {
  t=s->arrsize[s->first];
  s->first=-1;
  s->last=-1;
  }
  else
  {
 t=s->arrsize[s->first];
  s->first++;
 }
 printf("%d",t);
 }


   void main()
  {
  cqueue *a;
  int i,v;
  clrscr();
  a=makecqueue();
  printf("enter elements of cqueue=");
  for(i=0;i<5;i++)
  {
  scanf("%d",&v);
  addcqueue(a,v);
  }
  printf("circular queue is = ");
  printcqueue(a);
  printf("\ndel the no =");
  delcqueue(a);
  printf("\nafter delition queue is =");
  printcqueue(a);
getch();
  }





