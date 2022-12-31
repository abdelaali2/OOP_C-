#include <iostream>

using namespace std;

class Base
{
    int a;
    int b;
public:
    Base()
    {
        a=b=0;
    }
    Base(int n)
    {
        a=b=n;
    }
    Base(int x, int y)
    {
        a=x;
        b=y;
    }
    void setA(int x)
    {
        a=x;
    }
    void setB(int y)
    {
        b=y;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    int productAB()
    {
        return a*b;
    }
};
class Derived : public Base
{
    int c;
public:
    Derived() : Base()
    {
        c=0;
    }
    Derived(int n) : Base(n)
    {
        c=n;
    }
    Derived(int x, int y, int w) : Base (x,y)
    {
        c=w;
    }
    void setC(int z)
    {
        c=z;
    }
    int getC()
    {
        return c;
    }
    int productABC()
    {
        return productAB()*c;
    }
};

class SecondDerived : public Derived
{
    int d;
public:
    SecondDerived() : Derived()
    {
        d=0;
    }
    SecondDerived(int n) : Derived(n)
    {
        d=n;
    }
    SecondDerived(int x, int y, int w, int p) : Derived (x,y,w)
    {
        d=p;
    }
    void setD(int z)
    {
        d=z;
    }
    int getD()
    {
        return d;
    }
    int productABCD()
    {
        return productABC()*d;
    }
};


int main()
{
    cout<<"Test Case No.1"<<endl;
    Derived obj1;
    obj1.setA(3);
    obj1.setB(7);
    obj1.setC(1);
    cout<<"Obj1: "<<obj1.productAB()<<endl;
    cout<<"Obj1: "<<obj1.productABC()<<endl;

    cout<<endl<<"Test Case No.2"<<endl;
    Base b(5,4);
    cout<<"a= "<<b.getA()<<endl;
    cout<<"b= "<<b.getB()<<endl;
    b.setA(3);
    cout<<"a updated"<<endl;
    b.setB(7);
    cout<<"b updated"<<endl;
    //b.setC(1);
    cout<<"a*b= "<<b.productAB()<<endl;

    cout<<endl<<"Test Case No.3"<<endl;
    Base b0(5,4);
    Derived obj;
    cout<<b0.productAB()<<endl;
    cout<<obj.productAB()<<endl;
    cout<<obj.productABC()<<endl;

    cout<<endl<<"Test Case No.4"<<endl;
    Derived s1(2,3,2);
    cout<<"S1: a*b*c= "<<s1.productABC()<<endl;

    SecondDerived s2(2,3,3,2);
    cout<<"S2: a*b*c*d= "<<s2.productABCD()<<endl;


    return 0;
}
