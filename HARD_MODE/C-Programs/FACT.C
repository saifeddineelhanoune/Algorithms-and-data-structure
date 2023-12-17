#include<stdio.h>
#include<conio.h>
long fact(int n);
main()
{
long int n;
clrscr();
scanf("%d",&n);
fact(n);
printf("%ld",fact(n));
getch();
}
     long fact(int n)
     {
     int i;
     long prod=1;
     if(n>1)
     for(i=2;i<=n;++i)
     prod*=i;
     return prod;
     }
