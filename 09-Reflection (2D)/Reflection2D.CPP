#include<iostream.h>
#include<graphics.h>
#include<conio.h>

void draw(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void reflectionAboutXaxis(int x1, int y1, int x2, int y2, int x3, int y3)
{
	line(x1, getmaxy()-y1, x2, getmaxy()-y2);
	line(x2, getmaxy()-y2, x3, getmaxy()-y3);
	line(x3, getmaxy()-y3, x1, getmaxy()-y1);
}

void reflectionAboutYaxis(int x1, int y1, int x2, int y2, int x3, int y3)
{
	line(getmaxx()-x1, y1, getmaxx()-x2, y2);
	line(getmaxx()-x2, y2, getmaxx()-x3, y3);
	line(getmaxx()-x3, y3, getmaxx()-x1, y1);
}

void reflectionAboutOrigin(int x1, int y1, int x2, int y2, int x3, int y3)
{
	line(getmaxx()-x1, getmaxy()-y1, getmaxx()-x2, getmaxy()-y2);
	line(getmaxx()-x2, getmaxy()-y2, getmaxx()-x3, getmaxy()-y3);
	line(getmaxx()-x3, getmaxy()-y3, getmaxx()-x1, getmaxy()-y1);
}

void reflectionAboutYequalsX(int x1, int y1, int x2, int y2, int x3, int y3)
{
	line(getmaxx(), 0, 0, getmaxy());
	line(getmaxx()-x1, getmaxy()-y1, getmaxx()-x2, getmaxy()-y2);
	line(getmaxx()-x2, getmaxy()-y2, getmaxx()-x3, getmaxy()-y3);
	line(getmaxx()-x3, getmaxy()-y3, getmaxx()-x1, getmaxy()-y1);
}

void main()
{
    clrscr();
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    line(getmaxx()/2, 0, getmaxx()/2, getmaxy());
    line(0, getmaxy()/2, getmaxx(), getmaxy()/2);

    cout<<"Enter (x,y) coordinates for all 3 sides of Triangle = ";
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    draw(x1, y1, x2, y2, x3, y3);
    //reflectionAboutXaxis(x1, y1, x2, y2, x3, y3);
    //reflectionAboutYaxis(x1, y1, x2, y2, x3, y3);
    //reflectionAboutOrigin(x1, y1, x2, y2, x3, y3);
    reflectionAboutYequalsX(x1, y1, x2, y2, x3, y3);
    getch();
}
