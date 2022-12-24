#include <iostream>
#include <graphics.h>
#include <conio.h>
using namespace std;

class Point
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

class Line
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

class Rect
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

class Circle
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
    Circle *pCircles;
    Rect *pRects;
    Line *pLines;

public:

    Picture()
    {
        cNum=0;
        rNum=0;
        lNum=0;
        pCircles=NULL;
        pRects=NULL;
        pLines=NULL;

        cout << "Picture: default const." << endl;
    }

    Picture(int cn, int rn, int ln, Circle *pC, Rect *pR, Line *pL)
    {
        cNum=cn;
        rNum=rn;
        lNum=ln;
        pCircles=pC;
        pRects=pR;
        pLines=pL;

        cout<<"Picture: other const."<<endl;
    }

    void setCircles(int cn, Circle *cptr)
    {
        cNum=cn;
        pCircles=cptr;
    }

    void setRects(int rn, Rect *rptr)
    {
        rNum=rn;
        pRects=rptr;
    }

    void setLines(int ln, Line *lptr)
    {
        lNum=ln;
        pLines=lptr;
    }

    void paint()
    {
        int i;
        for(i=0; i<cNum; i++)
        {
            pCircles[i].draw();
        }

        for(i=0; i<rNum; i++)
        {
            pRects[i].draw();
        }

        for(i=0; i<lNum; i++)
        {
            pLines[i].draw();
        }
    }

    ~Picture()
    {
        cout<<"Picture: BYE!"<<endl;
    }
};


int main( )
{
    Picture myPic;
    // example on static allocation
    Circle cArr[3]= {Circle(50,50,50 ),Circle(200,100,100 ),Circle( 420,50,30)};
    // example on static allocation, using temporary objects (on the fly)
    Rect rArr[2];
    rArr[0]=Rect(30,40,170,100 );
    Point myP1(420,50);
    Point myP2(500,300);
    rArr[1]=Rect(myP1, myP2);

    return 0;

}
