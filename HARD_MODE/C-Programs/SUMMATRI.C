#include <conio.h>
#include <stdio.h>
#include <process.h>
#include<alloc.h>
typedef struct
{
int row;
int col;
int *buffer;
}matrix;


matrix *makematrix(int r,int c)
{
matrix *data;
if((r<=0 && r>data->row)||(c<=0 && c>data->col))
{
printf("wrong rows &colummn entered");
exit(0);
}
data=(matrix *)malloc(sizeof(matrix));
data->row=r;
data->col=c;
data->buffer=(matrix *)malloc(sizeof(int) * r * c);
return(data);
}

void *putmatrix(matrix *m,int r,int c,int val)
{
if((r<0&&r>m->row)&&(c<0&&c>m->col))
{
printf("wrong rows &col entered");
exit(0);
}
else
m->buffer[r * m->col + c]=val;
}


matrix *summatrix(matrix *a,matrix *b)
{
matrix *c;
int x,y;
if((a->row!=b->row)&&(a->col!=b->col))
{
printf("error");
exit(1);
}
c=makematrix(a->row,a->col);
for(x=0;x<a->row;x++)
{
for(y=0;y<a->col;y++)
{
c->buffer[x * a->col + y]
=a->buffer[x * a->col + y]+b->buffer[x * a->col + y];
}
}
return (c);
}

int getmatrix(matrix *m,int r,int c)
{
if((r<0&&r>m->row)&&(c<0&&c>m->col))
{
printf("wrong rows &col entered");
exit(0);
}
else
return(m->buffer[r * m->col + c]);
}

void printmatrix(matrix *m)
{
int i,j,a;
for(i=0;i<m->row;i++)
{
for(j=0;j<m->col;j++)
{
a=getmatrix(m,i,j);
printf("%d \t",a);
}
printf("\n");
}
}


void main()
{
int i,j,k,l,a,b;
matrix *p,*r,*s;
clrscr();
printf("first matrix:");
r=makematrix(2,3);
for(i=0;i<r->row;i++)
{
for(j=0;j<r->col;j++)
{
scanf("%d",&a);
putmatrix(r,i,j,a);
}
}
printf("second matrix");
s=makematrix(2,3);
for(k=0;k<s->row;k++)
{
for(l=0;l<s->col;l++)
{
scanf("%d",&b);
putmatrix(s,k,l,b);
}
}
p=summatrix(r,s);
printmatrix(p);
getch();
}







