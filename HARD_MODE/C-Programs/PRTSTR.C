#include<stdio.h>
#include<conio.h>
main()
	{	char str;
		int i,l;
	clrscr();
		scanf("%c",&str);
		l=strlen(str);
		for(i=1;i<=l;i++);
		printf("%*.*s",i,l,str);
	getch();
	}
