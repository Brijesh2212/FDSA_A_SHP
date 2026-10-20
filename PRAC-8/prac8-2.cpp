#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int x)
{
    Node *newnode = new Node;

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

Node* insert(Node *root, int x)
{
    if(root == NULL)
    {
        return createNode(x);
    }

    if(x < root->data)
    {
        root->left = insert(root->left, x);
    }
    else if(x > root->data)
    {
        root->right = insert(root->right, x);
    }

    return root;
}

void inorder(Node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;

        root = insert(root,x);
    }

    cout << "Inorder: ";
    inorder(root);

    cout << endl;

    return 0;
}