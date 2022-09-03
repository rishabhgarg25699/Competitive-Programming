// This program is to create a Binary Tree in C++ and then
// do Level Order traversal of the Binary tree

// Code by Nishit Anand


#include<iostream>
#include<queue>
using namespace std;

// Defining structure of elements of binary tree
struct node
    {
    int data;
    struct node *left;
    struct node *right;
    };

// Function to create a new node of the binary tree
struct node* create_node(int key)
{
    struct node* newnode= new node;
    newnode->data=key;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

// Function to insert an node in the binary tree
void insert_node(struct node*& root,struct node* node)
{
    char a;
    if(root==NULL)
    {
        root=node;
        cout<<"node Inserted\n";
    }
    else
    {
        cout<<"ENTER L OR R to insert in left or right of : "<<root->data<<" respectively : ";
        cin>>a;
        if(a=='L')
            insert_node(root->left,node);
        if(a=='R')
            insert_node(root->right,node);
    }
}

// Function for Level Order Traversal of Binary Tree
// I have used queue from C++ STL
void levelorder(struct node* root)
{
    struct node* curr=NULL;
    queue<struct node*> q;
    q.push(root);
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        cout<<" "<<curr->data;
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
}


// Main function
int main()
{
    struct node* root=NULL;
    int value;
    char b='y';
    do
    {
        cout<<"\nEnter value to be inserted into Binary Tree:";
        cin>>value;
        insert_node(root,create_node(value));
        cout<<"\nWANT TO ENTER MORE(y/n):";
        cin>>b;
    }
    while(b=='y');
    cout<<"LEVEL ORDER TRAVERSAL"<<endl;
    levelorder(root);
    return 0;
}

