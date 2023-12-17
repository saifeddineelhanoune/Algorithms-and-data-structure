#include<stdio.h>
#include<conio.h>
void main()
{
int k=0,i;
char s[20];
clrscr();
gets(s);
for(i=0;s[i]!='\0';i++)
if(s[i]==' ')
{
k++;
}
printf("%d",k);
getch();
}