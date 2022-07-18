#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void horizontalLineBres(int x0,int y0,int x1,int y1)          //|m|<=1
{
     int d, dx, dy, twoDy, twoDyMinusDx;
     int x,y;

     dx = abs(x1-x0);
     dy = abs(y1-y0);
     twoDy = 2*dy;
     twoDyMinusDx = 2*(dy-dx);

     d = 2*dy - dx;

     if(x0 > x1)        //starting point
     {
	 x = x1;
	 y = y1;
	 x1 = x0;
     }
     else
     {
	x = x0;
	y = y0;
     }

     putpixel(x,y,WHITE);

     while(x < x1)
     {
	x++;

	if(d>=0)
	{
	   d += twoDyMinusDx;
	   y++;
	}
	else if (d<0)
	{
	   d += twoDy;
	}

	putpixel(x,y,WHITE);
     }
}

void verticalLineBres(int x0,int y0, int x1, int y1)     //|m| > 1
{
     int d, dx, dy, twoDx, twoDxMinusDy;
     int x, y;

     dx = abs(x1-x0);
     dy = abs(y1- y0);
     twoDx = 2*dx;
     twoDxMinusDy = 2*(dx-dy);

     d = 2*dx - dy;

     if(y0 > y1)
     {
	x = x1;
	y = y1;
	y1 = y0;
     }
     else
     {
	x = x0;
	y = y0;
     }

     putpixel(x,y,WHITE);

     while(y < y1)
     {
	y++;

	if(d >= 0)
	{
	   x++;
	   d += twoDxMinusDy;
	}
	else if (d < 0)
	{
	   d += twoDx;
	}

	putpixel(x,y,WHITE);
     }

}

void main()
{
  int gd = DETECT, gm;

  initgraph(&gd, &gm, "c:\\TC\\BGI");

  int x0, x1, y0, y1, m;

  cout<<"Enter x0 = ";
  cin>>x0;
  cout<<"\nEnter y0 = ";
  cin>>y0;
  cout<<"\nEnter x1 = ";
  cin>>x1;
  cout<<"\nEnter y1 = ";
  cin>>y1;

  cout<<"\nEnter m(slope/line gradient) = ";
  cin>>m;

  if(m<1)
  {
     horizontalLineBres(x0,y0,x1,y1);
  }
  else if(m >= 1)
  {
     verticalLineBres(x0,y0,x1,y1);
  }

  getch();
}