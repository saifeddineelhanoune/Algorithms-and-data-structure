 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>
 #include<alloc.h>
	 typedef struct
		 {	int num;
			int den;
		 } rational;


 rational *makerational(int a, int b)
  {
	rational *r;
			if(b==0)
			  {	printf("wrong argument");
					exit(0);
			  }
     r=(rational *)malloc(sizeof(rational));
			r->num=a;
			r->den=b;
      return(r);
   }


 rational *sumrational(rational *a,rational *b)
{
	rational *newrat;
   newrat=(rational *)malloc(sizeof(rational));
		newrat->num=a->num * b->den + a->den * b->num;
		newrat->den=a->den * b->den;
	return (newrat);
}


     rational *mulrational(rational *a,rational *b)
      {
		rational *newrat1;
	newrat1=(rational *)malloc(sizeof(rational));
			newrat1->num=a->num * b->num;
			newrat1->den=a->den * b->den;
		return(newrat1);
      }


     rational *divrational(rational *a,rational *b)
	{
		rational *newrat2;
	     newrat2=(rational *)malloc(sizeof (rational));
			newrat2->num=a->num * b->den;
			newrat2->den=a->den * b->num;
		return (newrat2);
	}


     rational *eqrational(rational *a,rational *b)
	{
		rational *newrat3;
		int x,y;
	     newrat3=(rational *)malloc(sizeof(rational));
		      x=newrat3->num=a->num * b->den;
		      y=newrat3->den=a->den * b->num;
			if (x%y==0)
				printf("equal");
			else printf("not equal rational number");
		return(newrat3);
	}


    void main()
    {
	rational *a,*b,*z,*y,*d;
	   int l,m;float k;
	clrscr();
		a=makerational(2,1);
		b=makerational(4,2);
		z=sumrational(a,b);
		y=mulrational(a,b);
		d=divrational(a,b);
		eqrational (a,b);
	l=d->num;
	m=d->den;
	k=(float)l/m;
	printf("\n%d/%d\n%d/%d",a->num,a->den,b->num,b->den);
	printf("\n%d/%d\n%d/%d",z->num,z->den,y->num,y->den);
	printf("\n%d/%d\n%f",d->num,d->den,k);
	getch();
    }

