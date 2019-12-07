
//c++ program to insert in binary search tree
#include <iostream>
using namespace std;
	struct node
	{
		int val;
		node  *left;
		node *right;
	};
	
	struct node *get(int d)//to create a new node
	{
		struct node *newnode=new struct node();
		newnode->val=d;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	}
	 struct node *insert(struct node *root,int d)//to insert nodes 
	{
		if(root==NULL)
		root=get(d);
		else if(d>(root->val))
		root->right=insert(root->right,d);
		else if (d<=root->val)
		root->left=insert(root->left,d);
		return root;
	}
	struct node *print(struct node *root)//to print inorder traversal of trees
	{
		if(root!=NULL)
		{
		print(root->left);
		cout<<root->val<<endl;
		print(root->right);
		}

	}
	int main()//driver to test the above functions
	{
		struct node *root=NULL;
		root=insert(root,10);
		root=insert(root,2);
		root=insert(root,5);
		print(root);
	}

