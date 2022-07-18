#include<iostream.h>
#include<graphics.h>
#include<conio.h>

void drawCircle(int x0, int y0, int x, int y)
{
	putpixel(x0+x, y0+y, WHITE);
	putpixel(x0-x, y0+y, WHITE);
	putpixel(x0-y, y0+x, WHITE);
	putpixel(x0-y, y0-x, WHITE);
	putpixel(x0-x, y0-y, WHITE);
	putpixel(x0+x, y0-y, WHITE);
	putpixel(x0+y, y0-x, WHITE);
	putpixel(x0+y, y0+x, WHITE);
}

void midptcircle(int x0, int y0, int r)
{
    int x = 0, y = r;
    int d = 1 - r;

    do
    {
	drawCircle(x0, y0, x, y);

	x++;

	if(d<0)
	{
		d += 2*x + 1;
	}
	else if(d>0)
	{
		y--;
		d += 2*(x-y) + 1;
	}

	drawCircle(x0, y0, x, y);
    }while(y>=x);
}

void main()
{
	int x0, y0, r;                 clrscr();
	cout<<"Enter x0, y0 = ";
	cin>>x0>>y0;
	cout<<"\nEnter radius of circle = ";
	cin>>r;

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\TC\\BGI");

	midptcircle(x0, y0, r);
	getch();
}




