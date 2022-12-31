#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;
class Shape
{
    int color;
public:
    Shape()
    {
        color=0;
    }
    void setColor(int c)
    {
        color=c;
    }
    int getColor()
    {
        return color;
    }
};

class Point : public Shape
{
    int x;
    int y;

public:

    Point()
    {
        cout<<"Point: default const."<<endl;
        x=0;
        y=0;

    }

    Point(int x1, int y1)
    {
        cout<<"Point: other const."<<endl;
        x=x1;
        y=y1;
    }

    void setX(int x1)
    {
        x=x1;
    }

    void setY(int y1)
    {
        y=y1;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
    ~Point()
    {
        cout<<"Point: BYE!"<<endl;
    }
};

class Line : public Shape
{
    Point Start,End;

public:

    Line():Start(),End()
    {
        cout<<"Line: default const."<<endl;
    }

    Line (int x1, int y1,int x2, int y2):Start(x1,y1),End (x2,y2)
    {
        cout<<"Line: other const."<<endl;
    }

    void draw()
    {
        line(Start.getX(),Start.getY(),End.getX(),End.getY());
    }

    ~Line()
    {
        cout<<"Line: BYE!"<<endl;
    }

};

class Rect : public Shape
{
    Point ul;
    Point lr;

public:

    Rect():ul(),lr()
    {
        cout<<"Rect: default const."<<endl;
    }

    Rect(int x1, int y1, int x2, int y2) : ul(x1, y1), lr(x2, y2)
    {
        cout<<"Rect: other const."<<endl;
    }

    void draw()
    {
        rectangle(ul.getX(),ul.getY(),lr.getX(),lr.getY());
    }

    ~Rect()
    {
        cout<<"Rect: BYE!"<<endl;
    }

};

class Circle : public Shape
{
    Point center;
    int radius;

public:

    Circle() : center()
    {
        radius = 0;
        cout << "Circle: default const." << endl;
    }

    Circle(int m, int n, int r) : center(m, n)
    {
        radius = r;
        cout << "Circle: other const." << endl;
    }

    void draw()
    {
        circle(center.getX(), center.getY(), radius);
    }

    ~Circle()
    {
        cout << "Circle: BYE!" << endl;
    }

};

class Picture
{
    int cNum;
    int rNum;
    int lNum;
    Circle *pCircle;
    Rect *pRect;
    Line *pLine;
public:
    Picture()
    {
        cNum=0;
        rNum=0;
        lNum=0;
        pCircle=NULL;
        pRect=NULL;
        pLine=NULL;
        cout<<"picture default constructor"<<endl;
    }
    Picture(int cn, int rn, int ln, Circle *pC, Rect *pR, Line *pL)
    {
        cNum=cn;
        rNum=rn;
        lNum=ln;
        pCircle=pC;
        pRect=pR;
        pLine=pL;
        cout<<"picture second constructor"<<endl;
    }
    ~Picture()
    {
        cout<<"picture destructor"<<endl;
    }
    void setCircle (int c, Circle *ptrcircle)
    {
        cNum=c;
        pCircle=ptrcircle;

    }
    void setRect (int r, Rect *ptrrect)
    {
        rNum=r;
        pRect=ptrrect;

    }
    void setLine (int l, Line *ptrline)
    {
        lNum=l;
        pLine=ptrline;

    }
    void paint()
    {
        int i;
        for (i=0; i<cNum; i++)
        {
            pCircle[i].draw();
        }
        for (i=0; i<rNum; i++)
        {
            pRect[i].draw();
        }
        for (i=0; i<lNum; i++)
        {
            pLine[i].draw();
        }
    }
};

int main()
{
    Picture mypic;
    Circle cArr[3]= {Circle(50,50,50), Circle(200,100,100), Circle(420,50,30)};
    Rect rArr[2]= {Rect(30,40,170,100), Rect(420,50,500,300)};
    Line lArr[2]= {Line(420,50,300,300), Line(40,500,500,400)};
    mypic.setCircle(3,cArr);
    mypic.setRect(2,rArr);
    mypic.setLine(2,lArr);
    mypic.paint();
    return 0;
}


