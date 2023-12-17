#include<stdio.h>
#include<conio.h>
float average(int n[],int size);
main()
{
	int n[10],i;
	float avg;
	clrscr();
	printf("enter arrey elements:");
	for (i=0;i<10;i++)
	scanf("%d",&n[i]);
	avg=average(n,10);
	printf("average of arrey=%f",(float)avg);
	getch();
}
	float average(int n[],int size)
	{
		int s=0,i;
		float a;
		for(i=0;i<size;i++)
		s=s+n[i];
		a=(float)s/(float)size;
		return a;
	}

