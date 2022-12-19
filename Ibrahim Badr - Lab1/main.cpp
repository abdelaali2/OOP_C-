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


void swap_value(int, int);

void swap_reference(int &, int &);

void swap_address(int *, int *);

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

    //swap functions

    int a=5,b=7;
    cout<<"No.1 is "<<a<<"\t"<<"No.2 is"<<b<<endl;

    swap_value(a,b);

    swap_reference(a,b);

    swap_address(&a,&b);

    return 0;
}

void swap_value(int a, int b)
{
    cout<<endl<<"Swapping by Value"<<endl<<"No.1 is "<<a<<"\t"<<"No.2 is"<<b<<endl;
    int temp =a;
    a=b;
    b=temp;
    cout<<"No.1 is "<<a<<"\t"<<"No.2 is"<<b<<endl;
}

void swap_reference(int &a, int &b)
{
    cout<<endl<<"Swapping by Reference"<<endl<<"No.1 is "<<a<<"\t"<<"No.2 is"<<b<<endl;
    int temp =a;
    a=b;
    b=temp;
    cout<<"No.1 is "<<a<<"\t"<<"No.2 is"<<b<<endl;
}

void swap_address(int *a, int *b)
{
    cout<<endl<<"Swapping by address"<<endl<<"No.1 is "<<*a<<"\t"<<"No.2 is"<<*b<<endl;
    int temp = *a;
    *a=*b;
    *b=temp;
    cout<<"No.1 is "<<*a<<"\t"<<"No.2 is"<<*b<<endl;
}
