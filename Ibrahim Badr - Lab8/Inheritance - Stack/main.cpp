#include <iostream>

using namespace std;
template <class T>
class Stack
{
    int tos;
    int Size;
    T *ptr;
    static int counter;
public:
    Stack();
    Stack(int n);
    ~Stack();
    static int getCounter();
    void push(T);
    T pop(T);
    bool ifexists (int a);
    void print();
};

template <class T>
int Stack<T>::counter=0;

template <class T>
Stack<T>::Stack()
{
    tos=0;
    Size=10;
    ptr= new T[Size];
    counter++;
};

template <class T>
Stack<T>::Stack(int n)
{
    cout<<"Hello from the default constructor"<<endl;
    ptr=new T[Size];
    Size=n;
    tos=-1;
    counter++;
    cout<<"Stack Constructor: This is Stack object No. "<<counter<<endl;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] ptr;
    counter--;
    cout<<"Stack Destructor: Stack object No. "<<counter+1<<" will be terminated."<<endl;
};

template <class T>
void Stack<T>::push(T a)
{
    if (tos==Size)
    {
        cout<<"STACK OVERFLOW!"<<endl;
    }
    else
    {
        tos++;
        ptr[tos]=a;
        cout<<"Element "<<a<<" is inserted."<<endl;
    }
};

template <class T>
T Stack<T>::pop(T a)
{
    if (ifexists(a))
    {
        int popped;
        if (-1==tos)
        {
            cout<<"STACK EMPTY!"<<endl;
            return -1;
        }
        else
        {
            (tos)--;
            popped=ptr[tos];
            cout<<"Element "<<popped<<" is popped."<<endl;
            return popped;
        }
    }
    else
    {
        cout<<"INVALID ELEMENT!"<<endl;
    }
};


template <class T>
int Stack<T>::getCounter()
{
    return counter;
}

template <class T>
bool Stack<T>::ifexists (int a)
{
    for (int i=0; i<=Size; i++)
    {
        if (ptr[i]==a)
        {
            return true;
        }
    }
    return false;
}

template <class T>
void Stack<T>::print()
{
    if (-1==tos)
    {
        cout<<"STACK EMPTY!"<<endl;
    }
    else
    {
        for (int i=0; i<=tos; i++)
        {
            cout<<ptr[i]<<endl;
        }
    }
}


int main()
{

    Stack<int> s1(5);
    cout<<"Number of Integer Stack= "<<Stack<int>::getCounter()<<endl;

    s1.push(5);
    s1.push(10);
    s1.push(15);
    s1.push(20);
    s1.push(25);

    s1.print();

    s1.pop(10);
    s1.pop(15);

    s1.print();

    return 0;
}
