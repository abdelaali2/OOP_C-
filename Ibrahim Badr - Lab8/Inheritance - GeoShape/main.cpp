#include <iostream>

using namespace std;

class GeoShape
{
protected:
    float dim1;
    float dim2;
public:
    GeoShape()
    {
        dim1=dim2=0;
    }
    GeoShape(float x)
    {
        dim1=dim2=x;
    }
    GeoShape(float x, float y)
    {
        dim1=x;
        dim2=y;
    }
    void setDim1(float x)
    {
        dim1=x;
    }
    int getDim1()
    {
        return dim1;
    }
    void setDim2(float y)
    {
        dim2=y;
    }
    int getDim2()
    {
        return dim2;
    }
    virtual float calculateArea()
    {
        return 3;
    }
};

class Triangle : public GeoShape
{
public:
    Triangle(float x, float y) : GeoShape (x,y)
    {
        cout<<"Triangle: default const."<<endl;
    }
    float calculateArea()
    {
        return 0.5*dim1*dim2;
    }
    ~Triangle()
    {
        cout<<"Triangle: BYE!"<<endl;
    }
};

class Rect : public GeoShape
{
public:
    Rect()
    {
        cout<<"Rect: default const."<<endl;
    }
    Rect(float x, float y) : GeoShape (x,y)
    {

    }
    float calculateArea()
    {
        return dim1*dim2;
    }
    ~Rect()
    {
        cout<<"Rect: BYE!"<<endl;
    }
};

class Circle : public GeoShape
{
public:
    Circle()
    {
        cout<<"Circle: default const."<<endl;
    }
    Circle(float x) : GeoShape (x)
    {

    }
    void setRadius(float r)
    {
        dim1=dim2=r;
    }
    float getRadius()
    {
        return dim1;
    }
    float calculateArea()
    {
        return 22.0/7*dim1*dim1;
    }
    ~Circle()
    {
        cout<<"Circle: BYE!"<<endl;
    }
};

class Square : public Rect
{
public:
    Square()
    {
        cout<<"Square: other const."<<endl;
    }
    Square(float x) : Rect(x,x)
    {

    }
    void setSQDim (float x)
    {
        dim1=dim2=x;
    }
    float getSQDim ()
    {
        return dim1;
    }
    float calculateArea()
    {
        return Rect::calculateArea();
    }
    ~Square()
    {
        cout<<"Square: BYE!"<<endl;
    }
};

float sumofAreas(GeoShape *, GeoShape *, GeoShape *);

int main()
{
    Triangle t1(2,3);
    cout<<"Triangle area= "<<t1.calculateArea()<<endl;

    Rect r1(3,5);
    cout<<"Rect area= "<<r1.calculateArea()<<endl;

    Circle c1(4);
    cout<<"circle area= "<<c1.calculateArea()<<endl;

    cout<<"the sum of all areas= "<<sumofAreas(&r1,&c1,&t1)<<endl;

    return 0;

}


float sumofAreas(GeoShape *p1, GeoShape *p2, GeoShape *p3)
{
    return p1->calculateArea() + p2->calculateArea() + p3->calculateArea();
}

