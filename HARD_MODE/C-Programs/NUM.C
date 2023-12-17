#include <stdio.h>
#include <conio.h>
void main()
{
int a,b,c;
float k;
clrscr();
scanf("%d%d",&a,&b);
c=a+b;
printf("%d",c);
k=(float)a+(float)b;
printf("\n%f",k);
printf("\n%d\n%d",sizeof(k),sizeof(c));
getch();
}