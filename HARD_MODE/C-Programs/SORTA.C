#include<stdio.h>
#include<conio.h>
int sort(int n[],int size);
main()
{
	int n[10],i,j;
	clrscr();
	printf("sort an arrey:");
	for (i=0;i<10;i++)
	scanf("%d",&n[i]);
	sort (n,10);
	for(j=0;j<10;j++)
	printf("\n%d",n[j]);
	getch();
}
	int sort(int n[],int size)
	{
		int i,j,temp;
		for (i=0;i<9;i++)
		for(j=i+1;j<10;j++)
	   {
		if (n[i]>n[j])
		{
		temp=n[i];
		n[i]=n[j];
		n[j]=temp;
		}
	   }
		return n[j];
	 }