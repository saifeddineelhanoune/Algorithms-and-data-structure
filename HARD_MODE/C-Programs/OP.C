#include <stdio.h>
#include <conio.h>
main()
{
int a,b,res;
char op;
clrscr();
scanf("%d",&a);
scanf("%c",&op);
scanf("%d",&b);
{
switch(op)
{
case '+':res=a+b;
break;
case '-':res=a-b;
break;
case '*':res=a*b;
break;
case '/':res=a/b;
break;
default:
printf("\ninvalid op");
}
}
printf("\n%d",res);
getch();
}
