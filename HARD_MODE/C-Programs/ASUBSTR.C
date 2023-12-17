#include<stdio.h>
#include<conio.h>
main()
{
	char n[20],find[10];
	int pos;
	clrscr();
	gets(n);
	gets(find);
	pos=substr(n,find);
	if   (pos<0)
	     printf("not found");
	else
	     printf("nom is on position %d",pos);
}
	int substr(char s[],char f[])
	{
		int lenth_f,i,k,j;
		char temp[10]