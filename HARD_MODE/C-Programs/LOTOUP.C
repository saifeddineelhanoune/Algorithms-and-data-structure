#include<stdio.h>
#include<conio.h>
main()
{  char name[20];
	int i;
	clrscr();
	gets(name);
	for(i=0;name[i]!='\0';i++)
	{  if ((name[i]>='a')&&(name[i]<='z'))
		name[i]=name[i]-32;
	}
	puts(name);
	getch();
}