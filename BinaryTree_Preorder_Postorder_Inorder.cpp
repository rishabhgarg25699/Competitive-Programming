// This program is to create a Binary Tree in C++ and then
// do Pre Order, Post Order and In order traversals of the Binary tree

// Code by Nishit Anand


#include<iostream>
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
        cout<<"Node Inserted\n";
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



// Function for preorder traversal of Binary Tree
void preorder(struct node* root)
{
    if(root)
    {
        cout<<" "<<root->data;
        if(root->left)
            preorder(root->left);
        if(root->right)
            preorder(root->right);
    }
}

// Function for postorder traversal of Binary Tree
void postorder(struct node* root)
{
    if(root)
    {
        if(root->left)
            postorder(root->left);
        if(root->right)
            postorder(root->right);
        cout<<" "<<root->data;
    }
}

// Function for inorder traversal of Binary Tree
void inorder(struct node* root)
{
    if(root)
    {
        if(root->left)
            inorder(root->left);
        cout<<" "<<root->data;
        if(root->right)
            inorder(root->right);
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
    cout<<"PRE ORDER TRAVERSAL"<<endl;
    preorder(root);
    cout<<"\n";
    cout<<"POST ORDER TRAVERSAL"<<endl;
    postorder(root);
    cout<<"\n";
    cout<<"IN ORDER TRAVERSAL"<<endl;
    inorder(root);
    return 0;
}
