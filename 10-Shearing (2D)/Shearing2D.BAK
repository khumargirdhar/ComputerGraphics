#include<iostream.h>
#include<graphics.h>
#include<conio.h>

int n, i, x[100], y[100], shx, shy;

void draw() 
{
    for(i=0; i<n; i++)
    {
        line(x[i], y[i], x[(i+1) % n], y[(i+1) % n]);
    }
}

void shearing(char ch)
{
    if(ch=='X')
    {
        cout<<"Enter Shearing factor (Shx) = ";
        cin>>shx;

        for(i=0; i<n; i++)
        {
            x[i] += shx * y[i];
        }

    }
    else if(ch=='Y')
    {
        cout<<"Enter Shearing factor Shy) = ";
        cin>>shy;

        for(i=0; i<n; i++)
        {
            y[i] += shy * x[i];
        }

    } else if(ch=='B')
    {
        cout<<"Enter Shearing factors (Shx, Shy) = ";
        cin>>shx>>shy;

        for(i=0; i<n; i++)
        {
            x[i] += shx * y[i];
            y[i] += shy * x[i];
        }
    }
}

void main()
{
    clrscr();
    int gd = DETECT, gm;
    char ch;

    cout<<"Enter no. of sides = ";
    cin>>n;

    cout<<"Enter (x,y) coordinates for each side = ";
    for(i=0; i<n; i++)
    {
        cin>>x[i]>>y[i];
    }

    cout<<"In what direction do you want to shear? (X,Y,XY) - ";
    cin>>ch;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    setcolor(BLUE);
    draw();         //original object

    shearing(ch);

    setcolor(RED);
    draw();         //Object after shearing

    getch();
}