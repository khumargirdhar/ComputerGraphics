#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

int n, i, x[100],y[100];
float sx, sy;

void draw()
{
    for(i=0; i<n; i++)
    {
        line(x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
    }
}

void scale() 
{
    for(i=0; i<n; i++)
    {
        x[i] = x[0] + (int)((float)(x[i]-x[0]) * sx);
        y[i] = y[0] + (int)((float)(y[i]-y[0]) * sy);
    }
}

void main() 
{
    clrscr();
    int gd = DETECT, gm;
    cout<<"Enter no. of sides - ";
    cin>>n;
    cout<<"Enter (x,y) coordinates for each side - ";
    for(i=0; i<n; i++)
    {
        cin>>x[i]>>y[i];
    }
    cout<<"Enter scaling factors (Sx, Sy) = ";
    cin>>sx>>sy;

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setcolor(BLUE);
    draw();         //Original object
    scale();

    setcolor(RED);
    draw();          //Object after scaling

    getch();
}