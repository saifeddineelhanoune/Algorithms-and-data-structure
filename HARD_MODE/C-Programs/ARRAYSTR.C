#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int size;
	int *buffer;
	int lb;
} intarray;

intarray	*makeintarray(int n)
{
	intarray *newarray;
	if (n <= 0)
	{
		printf("wrong size");
		exit(1);
	}
	newarray = (intarray *)malloc(sizeof(intarray));
	newarray->size = n;
	newarray->lb = 0;
	newarray->buffer = (int *)malloc(sizeof(int) * n);
	return (newarray);
}

void	intarrayput(intarray *v, int x, int val)
{
	int ofset;
	ofset = x - v->lb; //* x is position of array size of v*//
						//* ofset shows position of founded num *//
	if (ofset < 0 && ofset >= v->size)
	{
		printf("wrong place to print data");
		exit(1);
	}
	v->buffer[ofset] = val;
}

int	intarrayget(intarray *v, int x)
{
	int ofset;
	ofset = x - v->lb;
	if (ofset < 0 && ofset >= v->size)
	{
		printf("wrong num to recieve value");
		exit(1);
	}
	return (v->buffer[ofset]);
}

void	printarray(intarray *v)
{
	int i, a;
	for (i = 0; i < v->size; i++)
	{
		a = intarrayget(v, i);
		printf("%d", a);
	}
}

void	main(void)
{
	intarray *l;
	int n, i, c;
	clrscr();
	printf("enter the size");
	scanf("%d", &c);
	l = makeintarray(c);
	for (i = 0; i < c; i++)
	{
		scanf("%d", &n);
		intarrayput(l, i, n);
	}
	printarray(l);
	getch();
}
