#include <iostream>

using namespace std;

class Stack
{
    int *st;
    int tos;
    int Size;
    static int counter; // Declare

    friend void viewContent(Stack);


public:

    Stack(int n)
    {
        cout<<"Hello from the default constructor"<<endl;
        st=new int[n];
        Size=n;
        tos=0;
        counter++;
        cout<<"Stack Constructor: This is Stack object No. "<<counter<<endl;
    }

    Stack(Stack &z)
    {
        cout<<"Hello from the copy constructor."<<endl;
        tos=z.tos;
        Size=z.Size;
        st=new int[Size];
        for (int i=0;i<tos;i++)
        {
            st[i]=z.st[i];
        }
        counter++;
        cout<<"Stack Constructor: This is Stack object No. "<<counter<<endl;

    }

    void push(int a)
    {
        if (tos==Size)
        {
            cout<<"STACK OVERFLOW!"<<endl;
        }
        else
        {
            tos++;
            st[tos]=a;
            cout<<"Element "<<a<<" is inserted."<<endl;
        }
    }

    int pop(int a)
    {
        if (ifexisits(a))
        {
            int popped;
            if (0==tos)
            {
                cout<<"STACK EMPTY!"<<endl;
                return -1;
            }
            else
            {
                tos--;
                popped=st[tos];
                cout<<"Element "<<popped<<" is popped."<<endl;
                return popped;
            }
        }
        else
        {
            cout<<"INVALID ELEMENT!"<<endl;
        }
    }

    void print()
    {
        if (0==tos)
        {
            cout<<"STACK EMPTY!"<<endl;
        }
        else
        {
            for (int i=0; i<=tos; i++)
            {
                cout<<st[i]<<endl;
            }
        }
    }

    ~Stack()
    {
        delete[] st;
        counter--;
        cout<<"Stack Destructor: Stack object No. "<<counter+1<<" will be terminated."<<endl;
    }

    bool ifexisits (int a)
    {
        cout<<"ifexisits is here";
        for (int i=0; i<=Size; i++)
        {
            if (st[i]==a)
            {
                return true;
            }
        }
        return false;
    }

};

int Stack::counter=0; // Initialization


int main()
{
    int length;


    Stack s1(5);

    s1.push(5);
    s1.push(10);
    s1.push(15);
    s1.push(20);
    s1.push(25);

    viewContent(s1);


    return 0;
}



void viewContent (Stack x)
{

    int top =x.tos;
    while (0!=top)
    {
        cout<<"Value No. "<<top<<" is :"<<x.st[top]<<endl;
        top--;
    }

}









