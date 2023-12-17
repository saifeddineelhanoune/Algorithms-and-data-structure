#include<stdio.h>
#include<conio.h>
main()
{
clrscr();
printf("%d",strtoint("12345678"));
getch();
}
int strtoint(char s[])
{
int i,val,res=0;
for(i=0;s[i]>='0'&&s[i]<='9';i++)
{
	val=s[i]-'0';
	res=res*10+val;
}
return res;
}
