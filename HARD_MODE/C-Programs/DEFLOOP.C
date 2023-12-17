#include<stdio.h>
#include<conio.h>
#define loop(n){for(lines=1;lines<=n;lines++)\
	{for(count=1;count<=n-lines;count++)\
		putchar(' ');\
	for(count=1;count<=2*lines-1;count++)\
		putchar('*');\
		printf("\n");\
	}\
	}
	main()
	{	int num,lines,count;
	clrscr();
		printf("enter no of lines:");
		scanf("%d",&num);
		loop(num);
	getch();
	}
