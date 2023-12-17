#include<stdio.h>
#include<conio.h>
 void  main()
{
	int a[5][5],b[5][5],c[5][5];
	int i,j,k,l,m,n,p,q;
	clrscr();
	printf("enter first matrix");
	scanf("%d%d",&m,&n);
	printf("enter second metrix");
	scanf("%d%d",&p,&q);
	if(n!=p)
	{
	printf("multiplication not possible");
	exit(0);
	}
	printf("enter a");
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	printf("enter b");
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	scanf("%d",&b[i][j]);
	for(i=0;i<m;i++)
	{
	for(j=0;j<q;j++)
	{
	c[i][j]=0;
	for(k=0;k<n;k++)
	c[i][j]=a[i][k]+b[k][j];
	}
	}
	printf("result of metrix");
	for(i=0;i<m;i++)
	for(j=0;j<q;j++)
	printf("%d\n",c[i][j]);
	printf("\n");
	   getch();
}