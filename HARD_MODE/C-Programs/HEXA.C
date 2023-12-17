#include<stdio.h>
#include<conio.h>
int hex(int);
main()
{
	int n;
	clrscr();
	printf("enter a number:");
	scanf("%d",&n);
	hex(n);
	getch();
}
	int hex(int d)
	{
		int r,i=0;
		int res[20];
		while(d>0)
	    {
	      r=d%16;
	      d=d/16;
	      switch(r)
	      {	case 10:
	      res[i++]='A';
	      break;
		case 11:
		res[i++]='B';
		break;
		case 12:
		res[i++]='C';
		break;
		case 13:
		res[i++]='D';
		    break;
		    case 14:
		    res[i++]='E';
		    break;
		    case  15:
		    res[i++]='F';
		    break;
		    default:
				res[i++]=r;
	    }
	    }
	   for(i--;i>0;i--)
	   if    (res[i]<10)
	   printf("%d",res[i]);
	   else
	   printf("%c",res[i]);
	   }