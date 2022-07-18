#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void drawCircle(int x1, int y1, int x, int y)
{
	putpixel(x1+x, y1+y, WHITE);
	putpixel(x1-x, y1+y, WHITE);
	putpixel(x1-y, y1+x, WHITE);
	putpixel(x1-y, y1-x, WHITE);
	putpixel(x1-x, y1-y, WHITE);
	putpixel(x1+x, y1-y, WHITE);
	putpixel(x1+y, y1-x, WHITE);
	putpixel(x1+y, y1+x, WHITE);
}

void brescir(int x0, int y0, int r)
{
    int x=0, y=r;
    int d = 3 - 2 * r;

    drawCircle(x0, y0, x, y);

do {

	x++;

	if(d<0)
	{
		d += 4*x + 6;
	}

	else if(d>0)
	{
		y--;
		d += 4*(x-y) + 10;
	}

	drawCircle(x0, y0, x, y);

    }while(y>=x);

}

void main()
{
	int x0, y0, r;         clrscr();
	cout<<"Enter x0 & y0 =  ";
	cin>>x0>>y0;
	cout<<"\nEnter radius of circle = ";
	cin>>r;


	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\TC\\BGI");
	brescir(x0, y0, r);
	getch();
}