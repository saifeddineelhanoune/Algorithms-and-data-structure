#include<stdio.h>
#include<conio.h>
main()
{
	char x,y;
	clrscr();
	printf("enter first ch");
	x=getchar();
	fflush(stdin);
	printf("enter second ch");
	y=getchar();
	putchar(x);
	putchar(y);
	getch();
}

