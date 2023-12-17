 #include<stdio.h>
 #include <conio.h>
 #include <alloc.h>
 #include <process.h>
 # define size 20
 typedef struct dequeue
 {
 int arrsize[size];
 int front,rear;
 }dequeue;

 dequeue *makedequeue()
 {
 dequeue *q;
 q=(dequeue *)malloc(sizeof(dequeue));
 q->front=-1;
 q->rear=-1;
 return q;
 }

 void adddequeue(dequeue *q,int val)
 {
 if((q->front==-1)&&(q->rear==-1))
	{
		q->front++;
		q->rear++;
		q->arrsize[q->front]=val;
	 }
else
     if((q->front==0)&&(q->rear==size-1))
	{
		printf("overflow");
		exit(0);
	}
else
  if(q->front!=0)
	{
	q->front--;
	  q->arrsize[q->front]=val;
	}
    else
	 {
	 q->rear++;
	 q->arrsize[q->rear]=val;
	 }
 }

 void deldequeue(dequeue *q)
 {
      int f,r;
      r=q->rear;
      f=q->front;
      while(f!=r+1)
      {
       q->arrsize[q->front]=NULL;
       q->front++;
	f++;
      }
 }

 void printdequeue(dequeue *q)
 {
 int t;
 int r,f;
 f=q->front;
 r=q->rear;
    while(f!=r+1)
    {
    t=q->arrsize[f];
    printf("%d",t);
    f++;
    }
  }


void main()
      {
      dequeue *a;
      int i,v,b;
      clrscr();
      a=makedequeue();
      for(i=0;i<5;i++)
      {
      scanf("%d",&v);
      adddequeue(a,v);
      }
     printdequeue(a);
      printf("\nentre val to b del= ");
      scanf("%d",&b);
      deldequeue(a);
      printdequeue(a);
      getch();
}






