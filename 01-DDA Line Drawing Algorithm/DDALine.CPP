//line with DDA algorithm
#include<iostream.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

void DDA(int x0,int y0,int x1,int y1)
{
    int dx,dy,m,x,y,step,xinc,yinc;

    dx = abs(x1-x0);
    dy = abs(y1-y0);

    if (abs(x0) > abs(y0))
    {
	step = abs(x0);
    }
    else step = abs(y0);

    xinc = dx/step;
    yinc = dy/step;

    x = x0;
    y = y0;

    for(int i=0; i<=step; i++)
    {
	putpixel(x,y,WHITE);
	x += xinc;
	y += yinc;
	//delay(10);
    }
}

void main()
{
   clrscr();
   int x0,y0,x1,y1;
   int gd = DETECT, gm;

   initgraph(&gd,&gm,"c:\\TC\\BGI");

   cout<<"\nEnter x0 = "; cin>>x0;
   cout<<"\nEnter y0 = "; cin>>y0;
   cout<<"\nEnter x1 = "; cin>>x1;
   cout<<"\nEnter y1 = "; cin>>y1;

   DDA(x0,y0,x1,y1);
   getch();
}
