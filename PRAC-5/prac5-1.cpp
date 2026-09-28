#include<iostream>
using namespace std;

struct Node
{
    string song;
    Node *prev;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void addFirst(string s)
{
    Node *newnode = new Node;
    newnode->song = s;
    newnode->prev = NULL;
    newnode->next = head;

    if(head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        head->prev = newnode;
        head = newnode;
    }
}

void addLast(string s)
{
    Node *newnode = new Node;
    newnode->song = s;
    newnode->next = NULL;
    newnode->prev = tail;

    if(head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

void insertAfter(string findSong, string s)
{
    Node *temp = head;

    while(temp != NULL && temp->song != findSong)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Song not found" << endl;
        return;
    }

    Node *newnode = new Node;
    newnode->song = s;

    newnode->prev = temp;
    newnode->next = temp->next;

    if(temp->next != NULL)
    {
        temp->next->prev = newnode;
    }
    else
    {
        tail = newnode;
    }

    temp->next = newnode;
}

void removeFirst()
{
    if(head == NULL)
    {
        cout << "Playlist is empty" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;

    if(head == NULL)
    {
        tail = NULL;
    }
    else
    {
        head->prev = NULL;
    }

    delete temp;
}

int countSongs()
{
    int count = 0;
    Node *temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void display()
{
    Node *temp = head;

    cout << "Playlist: ";

    while(temp != NULL)
    {
        cout << temp->song;

        if(temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
    cout << "Total songs: " << countSongs() << endl;
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
            string s;
            cin >> s;
            addFirst(s);
        }
        else if(ch == 2)
        {
            string s;
            cin >> s;
            addLast(s);
        }
        else if(ch == 3)
        {
            string oldSong, newSong;
            cin >> oldSong >> newSong;
            insertAfter(oldSong,newSong);
        }
        else if(ch == 4)
        {
            removeFirst();
        }

        display();
    }

    return 0;
}