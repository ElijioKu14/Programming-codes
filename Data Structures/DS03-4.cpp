#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
	int data;
	Node *next;
};

class Queue
{
public:
	Queue()
	{
	    top = NULL;
	    bot = NULL;
	}
	int enqueue(int data)
	{

	    create = new Node();
	    create->data = data;
	    create->next = NULL;

	    if(top==NULL)
        {

            bot = create;
            top=create;
            return 1;
        }
        else
        {
            bot->next=create;
            bot=create;
            return 1;

        }
	}


	int *dequeue()
	{
	    if(top == NULL)
        {
          return NULL;
        }
        else
        {
            int *p;
            *p = top->data;

            if (top==bot)
            {
               top=NULL;
               bot=NULL;

            }
            else{

            top= top->next;
        }
             return p;}

	}
private:
	Node *top;
  	Node *bot;
  	Node *create;
};

int main()
{
	int data, *temp;
	string command;
	Queue *queue = new Queue();
	while(1)
	{
		cin>>command;
		if(command.compare("exit") == 0)
		{
			break;
		}
		else if(command.compare("enqueue") == 0)
		{
			cout<<"Please input a integer data:";
			cin>>data;
			if(queue->enqueue(data) == 1)
			{
				cout<<"Successfully enqueue data "<<data<<" into queue."<<endl;
			}
			else
			{
				cout<<"Failed to enqueue data into queue."<<endl;
			}
		}
		else if(command.compare("dequeue") == 0)
		{
			temp = queue->dequeue();
			if(temp == NULL)
			{
				cout<<"Failed to dequeue a data from queue.\n";
			}
			else
			{
				cout<<"Dequeue data "<<*temp<<" from queue."<<endl;
			}
		}
	}
}