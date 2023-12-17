#include<stdio.h>
#include<conio.h>
main()
{
	int a,b,c;
	clrscr();
	printf("enter the two num");
	scanf("%d%d%d",&a,&b,&c);
	if(a>b)
	printf("a is greater");
	else
	printf("\nb is greater");
	if(b>c)
	printf("\nb is greater");
	else
	printf("\nc is greater");
	getch();
}

