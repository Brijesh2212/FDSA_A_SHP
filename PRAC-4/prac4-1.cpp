#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtFront(int value)



































{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

void insertAtEnd(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPosition(int value, int position)
{
    if (position <= 1)
    {
        insertAtFront(value);
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Position is greater than the current queue length." << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display()
{
    Node* temp = head;

    cout << "Queue: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice;
    int value;
    int position;

    while (true)
    {
        cout << "\n1. Insert at Front";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert at Position";
        cout << "\n4. Display Queue";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter patient token: ";
            cin >> value;

            insertAtFront(value);
            display();
        }
        else if (choice == 2)
        {
            cout << "Enter patient token: ";
            cin >> value;

            insertAtEnd(value);
            display();
        }
        else if (choice == 3)
        {
            cout << "Enter patient token: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            insertAtPosition(value, position);
            display();
        }
        else if (choice == 4)
        {
            display();
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}