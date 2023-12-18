#include <alloc.h>
#include <conio.h>
#include <process.h>
#include <stdio.h>
#define size 10

typedef struct
{
	int arrsize[size];
	int front;
	int rear;
} queue;

queue	*makequeue(void)
{
	queue *q;
	q = (queue *)malloc(sizeof(queue));
	q->front = -1;
	q->rear = -1;
	return (q);
}

void	addqueue(queue *q, int val)
{
	if (q->front == -1)
	{
		q->front++;
		q->rear++;
		q->arrsize[q->rear] = val;
	}
	else
	{
		q->rear++;
		q->arrsize[q->rear] = val;
	}
	if (q->rear > size - 1)
	{
		printf("overflow");
		exit(1);
	}
}

void	delqueue(queue *q)
{
	int t;
	if (q->front == q->rear)
	{
		q->front = -1;
		q->rear = -1;
	}
	else
	{
		t = q->arrsize[q->front];
		printf("%d", t);
		q->front++;
	}
}
void	printqueue(queue *q)
{
	int t;
	int f, r;
	f = q->front;
	r = q->rear;
	while (f != r + 1)
	{
		t = q->arrsize[f];
		printf("%d,", t);
		f++;
	}
}

void	main(void)
{
	queue *a;
	int i, b, j;
	clrscr();
	a = makequeue();
	printf("enter elements");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &b);
		addqueue(a, b);
	}
	printf("print queue's elements=");
	printqueue(a);
	printf("\ndel val=");
	delqueue(a);
	printf("\nprinting after delition=");
	printqueue(a);
	getch();
}