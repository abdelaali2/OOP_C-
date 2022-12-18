#include <iostream>

using namespace std;

class Complex
{
    float real;
    float imag;
public:
    void setReal(float r);
    {
        real=r;
    }
    void setImag(float i)
    {
        imag= i;
    }
    float getReal()
    {
        return real;
    }
    float getImag()
    {
        return imag;
    }
    void print()
    {
        if (0>imag)
        {
            cout<<real<<" - "<<fabs(imag)<<"i"<<endl;
        }
        else
        {
            cout<<real<<" + "<<fabs(imag)<<"i"<<endl;
        }
    }
};


int main()
{
    clrscr();
    Complex myComp1, myComp2, resultComp;
    myComp1.setReal(7);
    myComp1.setImag(2);
    myComp2.setReal(5);
    myComp2.setImag(3);
    return 0;
}
