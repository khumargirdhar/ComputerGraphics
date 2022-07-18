#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

int x1, x2, x3, y1, y2, y3; 
float thetaDeg, thetaRad;

void draw(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void translate(float tx, float ty)
{
    x1 += tx;
    x2 += tx;
    x3 += tx;

    y1 += ty;
    y2 += ty;
    y3 += ty;
}

void rotationAboutOrigin()
{
    x1 = floor(x1*cos(thetaRad) - y1*sin(thetaRad));
    y1 = floor(x1*sin(thetaRad) + y1*cos(thetaRad));
    x2 = floor(x2*cos(thetaRad) - y2*sin(thetaRad));
    y2 = floor(x2*sin(thetaRad) + y2*cos(thetaRad));
    x3 = floor(x3*cos(thetaRad) - y3*sin(thetaRad));
    y3 = floor(x3*sin(thetaRad) + y3*cos(thetaRad));
}

void rotationAboutAPt(float tx, float ty)
{
    translate(-tx, -ty);
    x1 = x1*cos(thetaRad) - y1*sin(thetaRad);
    y1 = x1*sin(thetaRad) + y1*cos(thetaRad);
    x2 = x2*cos(thetaRad) - y2*sin(thetaRad);
    y2 = x2*sin(thetaRad) + y2*cos(thetaRad);
    x3 = x3*cos(thetaRad) - y3*sin(thetaRad);
    y3 = x3*sin(thetaRad) + y3*cos(thetaRad);
    translate(tx, ty);
}

void main()
{
    int gd = DETECT, gm;
    int ch;
    float tx, ty;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    cout<<"Enter (x,y) coordinates for all 3 sides of Triangle = ";
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    cout<<"Enter angle = ";
    cin>>thetaDeg;

    // converting degrees to radians
    thetaRad = thetaDeg * 3.14/180;

    cout<<"1. Rotation about origin \n2. Rotation about a point\n";
    cin>>ch;

    setcolor(BLUE);
    draw(x1, y1, x2, y2, x3, y3);

    switch (ch)
    {
	    case 1:     rotationAboutOrigin();
                    setcolor(RED);
                    draw(x1, y1, x2, y2, x3, y3); 
                    break;

        case 2:     cout<<"Enter translation factors (Tx, Ty) = ";
                    cin>>tx>>ty;
                    rotationAboutAPt(tx, ty);

                    setcolor(RED);
                    draw(x1, y1, x2, y2, x3, y3); 
                    break;

        default: cout<<"INVALID CHOICE!";
    }

    getch();
}