#include<stdio.h>
#include<conio.h>
 main()
 { char s1,s2,temp;
    clrscr();
    scanf("%c%c",&s1,&s2);
    temp=s1;
    s1=s2;
    s2=temp;
    printf("%c%c",s1,s2);
    getch();
 }