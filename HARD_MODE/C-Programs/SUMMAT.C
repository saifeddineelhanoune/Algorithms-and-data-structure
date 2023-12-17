#include<stdio.h>
#include<conio.h>
void main()
{
int a[3][3],b[3][3],c[3][3];
int i,j,m,n,p,q;
clrscr();
printf("entr the order of a:");
scanf("%d%d",&m,&n);
printf("\nentr the order of b:");
scanf("%d%d",&p,&q);
printf("\nenter the first matrix.:");
{
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
scanf("%d",a[i][j]);
}
}
printf("enter the sec matrix:");

for(i=0;i<p;i++)
{
for(j=0;j<q;j++)
scanf("%d",b[i][j]);
}

/*for(i=0;i<m;i++)
{ //
for(j=0;j<n;j++)
{
c[i][j]=a[i][j]+b[i][j];
}
}*/
c[i][j]=a[i][j]+b[i][j];
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
printf("%d\t\n",c[i][j]);
}
getch();
}

