#include<iostream.h>
#include<graphics.h>
#include<conio.h>

void plotEllipse(int x, int y,int xc, int yc)
{
	putpixel(x+xc, y+yc, WHITE);
	putpixel(-x+xc, y+yc, WHITE);
	putpixel(x+xc, -y+yc, WHITE);
	putpixel(-x+xc, -y+yc, WHITE);
}

void MidPtEllipse(int rx, int ry, int xc, int yc)
{
      float dx, dy, d1, d2, x, y;
      x = 0; y = ry;

      //REGION 1
      d1 = (ry*ry) - (rx*rx*ry) + ((1/4)*rx*rx);
      dx = 2 * (ry*ry) * x;
      dy = 2 * (rx*rx) * y;

      while(dx < dy)
      {
	   plotEllipse(x, y, xc, yc);

	   if(d1<0)
	   {
		x++;
		dx = dx + (2*ry*ry);
		d1 = d1 + dx + (ry*ry);
	   }
	   else
	   {
		x++; y--;
		dx = dx + 2*(ry*ry);
		dy = dy + 2*(rx*rx);
		d1 = d1 + dx - dy + (ry*ry);
	   }
      }

      //REGION 2
      d2 = ((ry*ry)*(x+(1/2) * x+(1/2))) + ((rx*rx)*(y-1*y-1)) - (rx*rx*ry*ry);

      while(y>=0)
      {
	   plotEllipse(x, y, xc, yc);

	   if(d2>0)
	   {
		y--;
		dy = dy - 2*(rx*rx);
		d2 = d2 - dy + (rx*rx);
	   }
	   else
	   {
		x++; y--;
		dx = dx + 2*(ry*ry);
		dy = dy - 2*(rx*rx);
		d2 = d2 + dx - dy + (rx*rx);
	   }

      }
}

void main()
{
   int x, y, xc, yc;             clrscr();
   cout<<"Enter x, y, xc, yc = ";
   cin>>x>>y>>xc>>yc;

   int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\TC\\BGI");

   MidPtEllipse(x, y, xc, yc);

   getch();
}