#include<iostream>
using namespace std;

class Stack
{
    int arr[100];
    int top;
    int size;

public:

    Stack(int n)
    {
        size = n;
        top = -1;
    }

    void push(int x)
    {
        if(top == size-1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = x;

        cout << "Top: " << arr[top] << endl;
    }

    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        top--;

        if(top == -1)
            cout << "Top: Empty" << endl;
        else
            cout << "Top: " << arr[top] << endl;
    }

    void displayTop()
    {
        if(top == -1)
            cout << "Top: Empty" << endl;
        else
            cout << "Top: " << arr[top] << endl;
    }
};

int main()
{
    int n;
    cin >> n;

    Stack s(n);

    int q;
    cin >> q;

    for(int i=0;i<q;i++)
    {
        int choice;
        cin >> choice;

        if(choice == 1)
        {
            int tray;
            cin >> tray;
            s.push(tray);
        }
        else if(choice == 2)
        {
            s.pop();
        }
    }

    return 0;
}