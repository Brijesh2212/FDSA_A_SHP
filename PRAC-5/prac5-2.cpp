#include<iostream>
using namespace std;

struct SNode
{
    string name;
    SNode *next;
};

struct DNode
{
    string name;
    DNode *next;
    DNode *prev;
};

SNode *shead = NULL;
DNode *dhead = NULL;

void singlyJoin(string name, int pos)
{
    SNode *newnode = new SNode;
    newnode->name = name;

    if(shead == NULL)
    {
        shead = newnode;
        newnode->next = shead;
        return;
    }

    if(pos == 1)
    {
        SNode *temp = shead;

        while(temp->next != shead)
            temp = temp->next;

        newnode->next = shead;
        temp->next = newnode;
        shead = newnode;
        return;
    }

    SNode *temp = shead;

    for(int i=1;i<pos-1;i++)
    {
        temp = temp->next;

        if(temp == shead)
            break;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void singlyLeave(string name)
{
    if(shead == NULL)
        return;

    if(shead->name == name)
    {
        if(shead->next == shead)
        {
            delete shead;
            shead = NULL;
            return;
        }

        SNode *temp = shead;

        while(temp->next != shead)
            temp = temp->next;

        SNode *del = shead;
        shead = shead->next;
        temp->next = shead;

        delete del;
        return;
    }

    SNode *temp = shead;

    while(temp->next != shead && temp->next->name != name)
        temp = temp->next;

    if(temp->next != shead)
    {
        SNode *del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

void singlyDisplay()
{
    if(shead == NULL)
    {
        cout << "Singly Circular: Empty" << endl;
        return;
    }

    SNode *temp = shead;

    cout << "Singly Circular: ";

    do
    {
        cout << temp->name << " ";
        temp = temp->next;
    }
    while(temp != shead);

    cout << endl;
}

void doublyJoin(string name, int pos)
{
    DNode *newnode = new DNode;
    newnode->name = name;

    if(dhead == NULL)
    {
        dhead = newnode;
        newnode->next = dhead;
        newnode->prev = dhead;
        return;
    }

    if(pos == 1)
    {
        DNode *last = dhead->prev;

        newnode->next = dhead;
        newnode->prev = last;

        last->next = newnode;
        dhead->prev = newnode;

        dhead = newnode;
        return;
    }

    DNode *temp = dhead;

    for(int i=1;i<pos-1;i++)
    {
        temp = temp->next;

        if(temp == dhead)
            break;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    temp->next->prev = newnode;
    temp->next = newnode;
}

void doublyLeave(string name)
{
    if(dhead == NULL)
        return;

    DNode *temp = dhead;

    do
    {
        if(temp->name == name)
        {
            if(temp->next == temp)
            {
                delete temp;
                dhead = NULL;
                return;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if(temp == dhead)
                dhead = temp->next;

            delete temp;
            return;
        }

        temp = temp->next;
    }
    while(temp != dhead);
}

void doublyDisplay()
{
    if(dhead == NULL)
    {
        cout << "Doubly Circular: Empty" << endl;
        return;
    }

    DNode *temp = dhead;

    cout << "Doubly Circular: ";

    do
    {
        cout << temp->name << " ";
        temp = temp->next;
    }
    while(temp != dhead);

    cout << endl;
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
            string name;
            int pos;

            cin >> name >> pos;

            singlyJoin(name,pos);
            doublyJoin(name,pos);
        }
        else if(ch == 2)
        {
            string name;
            cin >> name;

            singlyLeave(name);
            doublyLeave(name);
        }
        else if(ch == 3)
        {
            singlyDisplay();
            doublyDisplay();
        }

        if(ch != 3)
        {
            singlyDisplay();
            doublyDisplay();
        }

        cout << endl;
    }

    return 0;
}