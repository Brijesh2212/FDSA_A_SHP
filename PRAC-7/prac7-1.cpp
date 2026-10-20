#include<iostream>
using namespace std;

class Queue
{
    int arr[100];
    int front;
    int rear;
    int size;
    int count;

public:

    Queue(int n)
    {
        size = n;
        front = 0;
        rear = -1;
        count = 0;
    }

    void join(int token)
    {
        if(count == size)
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        rear = (rear + 1) % size;
        arr[rear] = token;
        count++;

        display();
    }

    void serve()
    {
        if(count == 0)
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        front = (front + 1) % size;
        count--;

        display();
    }

    void display()
    {
        if(count == 0)
        {
            cout << "Front: Empty" << endl;
        }
        else
        {
            cout << "Front: " << arr[front] << endl;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    Queue q(n);

    int operations;
    cin >> operations;

    for(int i=0;i<operations;i++)
    {
        int choice;
        cin >> choice;

        if(choice == 1)
        {
            int token;
            cin >> token;
            q.join(token);
        }
        else if(choice == 2)
        {
            q.serve();
        }
    }

    return 0;
}