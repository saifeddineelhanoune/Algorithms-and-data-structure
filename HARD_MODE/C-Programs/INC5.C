#include<stdio.h>
#include<conio.h>
 void  main()
{
	int i,n;
	clrscr();
	i=0;
	scanf("%d",&n);
	do
	{
	   printf("%d\n",n);
	   n+=5;
	   i++;
	} while(i<10);
	   getch();
}