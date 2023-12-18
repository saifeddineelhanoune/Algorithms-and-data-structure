#include <conio.h>
#include <stdio.h>

main()
{
	char n[20], find[10];
	int pos;
	clrscr();
	gets(n);
	gets(find);
	pos = substr(n, find);
	if (pos < 0)
		printf("not found");
	else
		printf("nom is on position %d", pos);
}
