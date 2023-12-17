#include<stdio.h>
#include<conio.h>
int lenth(char name[]);
main()
{
	char name[20];
	int a;
	clrscr();
	gets(name);
	a=lenth(name);
	printf("lenth of str=%d",a);
	getch();
}
	int lenth(char name[])
	{ 	int i;
		for(i=0;name[i]!='\0';i++);
		return i;
	}