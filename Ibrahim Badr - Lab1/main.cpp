#include <iostream>

using namespace std;

class Complex
{

    float real, imag;

public:

    void setReal(float r)
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
            cout<<real<<imag<<"i"<<endl;
        }
        else
        {
            cout<<real<<"+"<<imag<<"i"<<endl;
        }
    }

    void add(Complex temp1, Complex temp2)
    {
        real=temp1.getReal()+temp2.getReal();
        imag=temp1.getImag()+temp2.getImag();
    }

    void sub(Complex temp1, Complex temp2)
    {
        real=temp1.getReal()-temp2.getReal();
        imag=temp1.getImag()-temp2.getImag();
    }

    Complex add2(Complex comp1)
    {
        //receive: complex.add(comp1)
        Complex result;
        result.setReal(real+comp1.getReal());
        result.setImag(imag+comp1.getImag());
        return result;
    }

        Complex sub2(Complex comp1)
    {
        //receive: complex.add(comp1)
        Complex result;
        result.setReal(real-comp1.getReal());
        result.setImag(imag-comp1.getImag());
        return result;
    }
};


int main()
{
    Complex myComp1, myComp2, resultComp;
    float rinp,iinp;

    cout<<"Complex No. 1: Enter the Real part then Enter the Imaginary part"<<endl;
    cin>>rinp>>iinp;

    myComp1.setReal(rinp);
    myComp1.setImag(iinp);
    myComp1.print();
    cout<<endl;

    cout<<"Complex No. 2: Enter the Real part then Enter the Imaginary part"<<endl;
    cin>>rinp>>iinp;

    myComp2.setReal(rinp);
    myComp2.setImag(iinp);
    myComp2.print();
    cout<<endl;

    resultComp.add(myComp1,myComp2);
    resultComp.print();
    cout<<endl;

    resultComp=myComp1.add2(myComp2);
    resultComp.print();
    cout<<endl;

    resultComp.sub(myComp1,myComp2);
    resultComp.print();

    resultComp=myComp1.sub2(myComp2);
    resultComp.print();
    cout<<endl;

    return 0;
}
