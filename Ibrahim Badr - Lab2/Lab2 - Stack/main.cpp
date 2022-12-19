#include <iostream>

using namespace std;

class Stack
{
public:
    int counter=0;

    Stack(int n=10)
    {
        counter++;
        cout<<"This is Stack object No. "<<counter<<endl;
    }



    ~Stack()
    {
        counter--;
        cout<<"Stack object No. "<<counter+1<<" will be terminated."<<endl;
    }


};


int main()
{

    Stack s1;

    return 0;
}
