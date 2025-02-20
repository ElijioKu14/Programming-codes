#include <iostream>
#include <string.h>
#define SIZE 5
using namespace std;

class Stack
{
public:
    Stack()
    {
        data[0];
        counter = -1;
    }
    int push(int d)
    {
        if(counter <=3)
        {
            counter++;
            data[counter] = d;
            return 1;
        }
        else return -1;
    }

    int *pop()
    {
        if(counter !=-1 )
        {
            int *p;
            p = &data[counter];
            counter--;
            return p;
        }
        else return NULL;

    }
private:
    int data[SIZE];
    int counter;
};

int main()
{
    int data, *temp;
    char command[50];
    Stack *stack = new Stack();
    while(1)
    {
        cin>>command;
        if(strcmp(command, "exit") == 0)
        {
            break;
        }
        else if(strcmp(command, "push") == 0)
        {
            cout<<"Please input a integer data:";
            cin>>data;
            if(stack->push(data) == 1)
            {
                cout<<"Successfully push data "<<data<<" into stack.\n";
            }
            else
            {
                cout<<"Failed to push data into stack.\n";
            }
        }
        else if(strcmp(command, "pop") == 0)
        {
            temp = stack->pop();
            if(temp == NULL)
            {
                cout<<"Failed to pop a data from stack.\n";
            }
            else
            {
                cout<<"Pop data "<<*temp<<" from stack.\n"<<endl;
            }
        }
    }
}