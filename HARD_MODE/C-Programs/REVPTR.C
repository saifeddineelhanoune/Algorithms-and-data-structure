#include<stdio.h>
#include<conio.h>
int len(char*s);
void rev(char*s);
main()
{
	char str[20];
	int len;
	clrscr();
	printf("enter:");
	gets(str);
	len=length(str);
	printf("\nlen=%d",len);
	printf("\nrev of str=");
	rev(str);
	getch();
}
void rev(char*s)
{int i;
for(i=0;*s!='\0';i++,s++);
s--;
for(;i>=0;i--,s--)
printf("%c",*s);
}
int length(char*s)
{
int i;
for(i=0;*s!='\0';i++,s++);
return i;
}