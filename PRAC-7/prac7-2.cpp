#include<iostream>
using namespace std;

struct Node
{
    string name;
    Node *next;
};

class Queue
{
    Node *front;
    Node *rear;

public:

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void arrive(string name)
    {
        Node *newnode = new Node;

        newnode->name = name;
        newnode->next = NULL;

        if(front == NULL)
        {
            front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }

        display();
    }

    void attend()
    {
        if(front == NULL)
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        Node *temp = front;

        front = front->next;

        if(front == NULL)
        {
            rear = NULL;
        }

        delete temp;

        display();
    }

    void display()
    {
        if(front == NULL)
        {
            cout << "Front: Empty" << endl;
        }
        else
        {
            cout << "Front: " << front->name << endl;
        }
    }
};

int main()
{
    Queue q;

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int choice;
        cin >> choice;

        if(choice == 1)
        {
            string name;
            cin >> name;
            q.arrive(name);
        }
        else if(choice == 2)
        {
            q.attend();
        }
    }

    return 0;
}