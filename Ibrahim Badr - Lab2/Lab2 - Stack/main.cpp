#include <iostream>

using namespace std;

class Stack
{
    int *st;
    int tos;
    int Size;
    static int counter; // Declare


public:

    Stack(int n)
    {
        st=new int[n];
        Size=n;
        tos=-1;
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
        if (ifexists(a))
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
        for (int i=0; i<=tos; i++)
        {
            cout <<st[i]<<endl;
        }
    }

    ~Stack()
    {
        delete[] st;
        counter--;
        cout<<"Stack Destructor: Stack object No. "<<counter+1<<" will be terminated."<<endl;
    }

    bool ifexists (int a)
    {
        for (int i=0; i<=Size; i++)
        {
            if (st[i]==a)
                return true;
        }
        return false;
    }


};

int Stack::counter=0; // Initialization

int main()
{
    // Bonus No.1: Create the stack with a user input size.

    int length;
    int User_input;

    cout<<"Enter the size of the Stack"<<endl;
    cin>>length;
    Stack s1(length);

    for (int i=0; i<length; i++)
    {
        cout<<"Enter value No. "<<i+1<<endl;
        cin>>User_input;
        s1.push(User_input);
    }

    s1.print();

    cout<<"Enter the value you want to pop."<<endl;
    cin>>User_input;

    s1.pop(User_input);
    s1.print();

    return 0;
}






