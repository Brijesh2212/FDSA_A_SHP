#include<iostream>
using namespace std;

struct Node
{
    string page;
    Node *next;
};

Node *top = NULL;

void visit(string page)
{
    Node *newnode = new Node;

    newnode->page = page;
    newnode->next = top;

    top = newnode;
}

void back()
{
    if(top == NULL)
    {
        cout << "No history" << endl;
        return;
    }

    Node *temp = top;
    top = top->next;

    delete temp;
}

void display()
{
    if(top == NULL)
    {
        cout << "No page" << endl;
    }
    else
    {
        cout << "Current page: " << top->page << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int ch;
        cin >> ch;

        if(ch == 1)
        {
            string page;
            cin >> page;
            visit(page);
        }
        else if(ch == 2)
        {
            back();
        }

        display();
    }

    return 0;
}