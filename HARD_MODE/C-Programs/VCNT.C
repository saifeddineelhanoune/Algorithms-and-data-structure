# include <stdio.h>
# include <conio.h>
void main()
{
char ch;
int vcnt=0,ocnt=0;
clrscr();
printf("entr the char:");
while((ch=getchar())!=EOF)
{
switch(ch)
{
case 'a':  case 'e':  case 'i':   case 'o':  case 'u':
vcnt++;
break;
default:
ocnt++;
}
fflush(stdin);
}
printf("vowels=%d\ncharacters=%d",vcnt,ocnt);
getch();
}
