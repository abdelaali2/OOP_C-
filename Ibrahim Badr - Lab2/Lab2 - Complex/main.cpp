#include <iostream>

using namespace std;

class Complex
{

    float real, imag;

public:

    Complex()
    {
        real=0;
        imag=0;
        cout<<"Complex object created: The default Constructor is used"<<endl;
    }

    Complex (float n)
    {
        real=imag=n;
        cout<<"Complex object created: The Constructor used assigned the Real part = Imaginary part = "<<n<<endl;
    }

    Complex(float re, float im)
    {
        real=re;
        imag=im;
        cout<<"Complex object created: The Constructor used assigned the Real part = "<<re<<" & Imaginary part = "<<im<<endl;
    }

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

    void setComplex(float re, float im)
    {
        real=re;
        imag=im;
    }


    ~Complex()
    {
        cout<<"The object will be terminated."<<endl;
    }

};


int main()
{

    Complex myComp1;
    float rinp,iinp;

    cout<<"Complex No. 1: Enter the Real part then Enter the Imaginary part"<<endl;
    cin>>rinp>>iinp;

    myComp1.setComplex(rinp,iinp);
    myComp1.print();
    cout<<endl;

    Complex myComp2(2.5);
    myComp2.print();
    cout<<endl;

    Complex myComp3(4.8,5.3);
    myComp3.print();
    cout<<endl;



    return 0;
}
