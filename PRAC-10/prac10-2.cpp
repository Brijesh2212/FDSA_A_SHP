#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *table[10];

void insertBook(int code)
{
    int index = code % 10;

    Node *newnode = new Node;

    newnode->data = code;
    newnode->next = NULL;

    if(table[index] == NULL)
    {
        table[index] = newnode;
    }
    else
    {
        Node *temp = table[index];

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

void display()
{
    for(int i=0;i<10;i++)
    {
        cout << i << " : ";

        Node *temp = table[i];

        if(temp == NULL)
        {
            cout << "Empty";
        }

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
}

int main()
{
    for(int i=0;i<10;i++)
    {
        table[i] = NULL;
    }

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int code;
        cin >> code;

        insertBook(code);
    }

    display();

    return 0;
}