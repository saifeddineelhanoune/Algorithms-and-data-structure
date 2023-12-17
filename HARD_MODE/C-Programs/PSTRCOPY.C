#include<stdio.h>
#include<conio.h>
#include<string.h>
char* rev(char*s);
main()
{
char str1[20],temp;
printf("enter 1st str");
gets(str1);
strcpy(temp,rev(str1));
puts(temp);
getch();
}
char*rev(char*s)
{
int i,j;
char temp[20];
for(i=0;*s!='\0';i++,s++);
s--;
for(;*s!='\0';i--,s--,j++);
printf("rev=%c",*s);
temp[j]=*s;
return temp;

}

