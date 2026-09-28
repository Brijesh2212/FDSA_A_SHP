#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
     Node(int x)
    {
        data=x;
        next=NULL;
    }
};
class Queue
{
    Node* head;
    public:
    Queue()
    {
        head=NULL;
    }
    void insertEnd(int x)
    {
        Node* newnode=new Node(x);
        if(head==NULL)
        {
            head=newnode;
            return;
        }
        Node* temp=head;
         while(temp->next!=NULL)
        {
            temp=temp->next;
        }
         temp->next=newnode;
    }
        void deleteValue(int x)
    {
        if(head==NULL)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }

        if(head->data==x)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
            return;
        }

        Node* temp=head;

        while(temp->next!=NULL && temp->next->data!=x)
        {
            temp=temp->next;
        }

        if(temp->next==NULL)
        {
            cout<<"Value not found"<<endl;
            return;
        }

        Node* del=temp->next;
        temp->next=del->next;
        delete del;
    } 
        void display()
    {
        Node* temp=head;

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }

        cout<<endl;
    }
        void reversePrint(Node* temp)
    {
        if(temp==NULL)
            return;

        reversePrint(temp->next);
        cout<<temp->data<<" ";
    }

    void reverseDisplay()
    {
        reversePrint(head);
        cout<<endl;
    }
   

int main()
{
    Queue q;
    int n,x;

    cout<<"Enter number of patients: ";
    cin>>n;

    cout<<"Enter patient tokens: ";

    for(int i=0;i<n;i++)
    {
        cin>>x;
        q.insertEnd(x);
    }

    cout<<"Queue: ";
    q.display();

    cout<<"Enter token to delete: ";
    cin>>x;

    q.deleteValue(x);

    cout<<"After deletion: ";
    q.display();

    cout<<"Reverse queue: ";
    q.reverseDisplay();

    cout<<"Forward queue: ";
    q.display();

    return 0;
}
};