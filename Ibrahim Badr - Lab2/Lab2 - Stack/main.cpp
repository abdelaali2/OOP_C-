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
        tos=0;
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

void menu(Stack &);

int main()
{
    int length;
    // Bonus No.1: Create the stack with a user input size.
    cout<<"Enter the size of the Stack"<<endl;
    cin>>length;
    Stack s1(length);
    menu(s1);
    return 0;
}


//Bonus No.2: Menu


void menu(Stack &s1)
{
    int choice,User_input,cont,exit=0;

    while (0==exit)
    {
        cout<<endl<<endl;
        cout<<"Press 1 to Display the Stack"<<endl;
        cout<<"Press 2 to Push into the Stack"<<endl;
        cout<<"Press 3 to Pop from the Stack"<<endl;
        cout<<"Press any key to exit"<<endl;

        cin>>choice;

        switch (choice)
        {

        case 1:
            s1.print();

            break;

        case 2:
            cout<<"Enter value"<<endl;
            cin>>User_input;
            s1.push(User_input);

            break;
        case 3:
            cout<<"Enter the value you want to pop."<<endl;
            cin>>User_input;
            s1.pop(User_input);
            break;
        default:
            exit=1;
            break;
        }
    }
    return;
}

