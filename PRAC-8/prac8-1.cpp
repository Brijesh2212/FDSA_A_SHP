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

void inorder(Node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(Node *root)
{
    if(root == NULL)
        return;

    Node *q[100];
    int front = 0;
    int rear = 0;

    q[rear] = root;
    rear++;

    while(front < rear)
    {
        Node *temp = q[front];
        front++;

        cout << temp->data << " ";

        if(temp->left != NULL)
        {
            q[rear] = temp->left;
            rear++;
        }

        if(temp->right != NULL)
        {
            q[rear] = temp->right;
            rear++;
        }
    }
}

int main()
{
    Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    cout << "Inorder: ";
    inorder(root);

    cout << endl;

    cout << "Preorder: ";
    preorder(root);

    cout << endl;

    cout << "Postorder: ";
    postorder(root);

    cout << endl;

    cout << "Levelorder: ";
    levelorder(root);

    cout << endl;

    return 0;
}