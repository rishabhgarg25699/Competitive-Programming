//============================================================================
// Name        : btree.cpp
// Author      : Snehal Khandve
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
	1)  This C++ program has both recursive and non-recursive codes for all traversals , height , copy and 
		mirror image of the tree . 
	
	2)	For better understanding of data structure , I have not taken tree nodes in an array
		but constructed it using a class object for each tree node .

	3) 	Also , for those who wants clear understanding of how stack and queue works , I have written this code
		without making use of STL vector and queue and have actually implemented stack and queue
.

*/

#include <iostream>
#include <cmath>
using namespace std;
#define MAX 10

// 1. insert
// 2. delete
// 3. modify
// 4. search
class node
{
    node *right;
    node *left;
    int data;

public:
	node()
	{
		data=0;
		right=left=NULL;
    }

	node(int d)
		{
			data=d;
			right=left=NULL;
	    }

	friend class queue1;
	friend class binarytree;
	friend class stack1;
};

class queue1
{
	int front,rear;
	node * arr[MAX];
public:
    queue1()
   {
	   front=rear=-1;
	   for(int i=0; i<MAX; i++)
	      arr[i]=NULL;
   }

   int isempty()
   {

	   if(front==-1)
		   return 1;
	   else
		   return 0;
   }

   int isfull()
   {
	   if(rear==MAX)
		   return 1;
	   else
		   return 0;
   }

   node* getrear()
   {
      node* temp=arr[rear];
	  return temp;
   }

   node* getfront()
   {
      node* temp=arr[front];
	  return temp;
   }

   void insert(node* temp)
   {

      if(!isfull())
      {
    	  if(front==-1)
    	  {
    	  	++front;
		  }
    	  ++rear;
    	  arr[rear]=temp;
      }

      else
    	 cout<<"\nQueue is full";
    }
   node* del()
   {
	   //cout<<size();
	   if(!isempty())
	   {
		   node* temp;
	       temp=arr[front];
	       if(front==rear)
	    	   front=rear=-1;
	       else
	           front++;
	       return temp;
	   }
	   else
		   {
		   cout<<"\nQueue is empty";
		   return NULL;
		   }
   }

   void clear()
   {
       int i=0;
   	   while(arr[i]!=NULL)
   	   {
   	   	  arr[i]=NULL;
   	   	  i++;
	   }
   }
   void disp()
   {
	   int i=front;
	   while(i!=(rear+1))
	      {
	      	cout<<"\n"<<arr[i]->data;
	      	i++;
		  }
		  if(isempty())   // NOt working :(
		    cout<<"\nUnderflow";
  }


};

class stack1
{
	int top;
	node* data[20];

public:
	stack1()
   {
		top=-1;
   }

   node* pop()
   {
   	   if(isempty())
   	     cout<<"\nUnderflow";
   	   else
   	   {
   	     node* temp=data[top];
	     top--;
	     return temp;
	   }

   }

   void push(node * temp)
   {
       if(isfull())
         cout<<"\nOverflow";
       else
       {
       	  top++;
	      data[top]=temp;
	   }

   }

   int isfull()
   {
	   if(top==(MAX-1))
		   return 1;
	   else
		   return 0;

   }

   int isempty()
      {
   	   if(top==-1)
   		   return 1;
   	   else
   		   return 0;

      }

};

class binarytree
{
    node *root;
	int info,leaf_nodes;
public:
	int no_of_ele;
	node* getroot()
	{
		return root;
	}

    binarytree()  //constructor
    {
    	root=NULL;
    	info=0;
    	no_of_ele=0;
    	leaf_nodes=0;
	}
    queue1 q;

    void create_nonrec()
	{
		int info;
		queue1 q;
		node *temp;
		if(root==NULL)
		  {
		  	cout<<"\nEnter data";
		  	cin>>info;
		  	root=new node(info);
		  	no_of_ele++;
		  }
		q.insert(root);
		 while(!q.isempty())
		 {
		 	temp=q.del();
		 	cout<<"Left data of "<<temp->data;
		 	cin>>info;
		 	if(info!=(-1))
		 	{
		 	   temp->left=new node(info);
			   q.insert(temp->left);
			   no_of_ele++;
			}
			cout<<"Right data of "<<temp->data;
		 	cin>>info;
		 	if(info!=(-1))
		 	{
		 	   temp->right=new node(info);
			   q.insert(temp->right);
			   no_of_ele++;
			}
	     }

     }

   void insert_rec()
   {
	   root=create_rec();
   }
	node* create_rec()
	{
		node *r;
	    cout<<"\n Enter data ";
	    cin>>info;
	    if(info==-1)
	    	return NULL;
	    else
	    {
	    	r=new node(info);
	    	no_of_ele++;
	    	cout<<"\nLeft child of "<<r->data;
	    	r->left=create_rec();
	    	cout<<"\nRight child of "<<r->data;
	    	r->right=create_rec();
	    	return r;
	    }
	}

  void inorder_rec(node *temp)  //being recursive code u have to pass root as a
	{                             //parameter so every tym it is called we pass a node
		if(temp!=NULL)
		{
			inorder_rec(temp->left);
			cout<<temp->data<<" ";
			inorder_rec(temp->right);
		}
	}

    void inorder_nonrec()  //being non-rec we needn't pass the root cuz it isn't being
    {                      // and doesn't need the parameter
    	node* current=root;
    	stack1 s;                // whatever we did for recursive internally with the stack we do same thing
    label:	while(current!=NULL) // here in non-recursive but here we just hand code the internal working
    	{
    		s.push(current);           //  inorder_rec(temp->left); --> equivalent line in recursive code
    		current=current->left;
		}
    	if(current==NULL && !s.isempty())
         {
            node* item=s.pop();       //  cout<<temp->data<<" "; --> equivalent line in recursive code
			cout<<item->data<<" ";
			current=item->right;      //  inorder_rec(temp->right); --> equivalent line in recursive code
			goto label;
	     }
		 if(current==NULL && s.isempty())
		    return;
	}

   void postorder_rec(node *temp)
	 {
       if(temp!=NULL)
        {
        	postorder_rec(temp->left);
        	postorder_rec(temp->right);
        	cout<<temp->data<<" ";
        }
	 }

	void postorder_nonrec()
		 {
			 stack1 s1,s2;
			 node *temp;
			 node *p;
			 while(!s1.isempty())  //to clear the stack
			 	s1.pop();
			 while(!s2.isempty())  //to clear the stack
			 	s2.pop();
			 s1.push(root);
			 while(!s1.isempty())
			 {
				temp=s1.pop();
				s2.push(temp);            // take example :   20
                                          //                  / \
                                         //                 10  30
                if(temp->left!=NULL)
					s1.push(temp->left);    // 1st take root into s1
				if(temp->right!=NULL)       // keep popping out s1 n insert this popped element into s2
				   s1.push(temp->right);    // also inert popped element left n right into s1
			 }                              // entire s2 is to be displayed
			 while(!s2.isempty())
			 {
				 p=s2.pop();
				 cout<<p->data<<" ";
			 }
		 }

     void preorder_rec(node *temp)
	{
        if(temp!=NULL)
        	{
        	  cout<<temp->data<<" ";
        	  preorder_rec(temp->left);
        	  preorder_rec(temp->right);
        	}
	}

     void preorder_nonrec()
       {
    	   stack1 s;
    	   node *temp;
    	   while(!s.isempty())
    	  		s.pop();
    	   s.push(root);
    	   while(!s.isempty())
    	   {
    		   temp=s.pop();
    		   cout<<temp->data<<" ";
    		   if(temp->right!=NULL)       // so that root->left nodes remain on top of stack n left children r
    		      s.push(temp->right);    // displayed 1st then right children
    		   if(temp->left!=NULL)
    		      s.push(temp->left);
    	   }
       }

     int height_rec(node *temp)
     {
    	 int lefth=0,righth=0;
    	 if(temp==NULL)
    		  return 0;  //return -1 if u want height of leaf as 0
    	 else
    	 {
    		 lefth+=height_rec(temp->left);
    		 righth+=height_rec(temp->right);
    		 return(1+max(lefth,righth));
    	 }
     }

    int height_nonrec()
    {
    	int ht=0;
    	node *temp;
    	if(root==NULL)
    	  return 0;
	    q.insert(root);
       	while(1)
       	{
          if(q.isempty())
		     return ht;
		   while(!q.isempty())
		   {
			   ht++;
			   temp=q.del();
		   	   if((temp->left)!=NULL)
		   	    {
				    q.insert(temp->left);
		   	  	  if((temp->right)!=NULL)  // if 2 nodes r present at same lvl no need to
		   	  	    ht--;                 // increment ht for just 1 node
                }

              if((temp->right)!=NULL)  // if 2 nodes present at same lvl ht is incremented for
		   	     {                    // this node
		   	     	q.insert(temp->right);

				 }
		   }
		}
        // return ht;
    }

    void mirror_rec(node *temp)
    {
    	if(temp!=NULL)
    	  {
    	  	mirror_rec(temp->left);
    	  	mirror_rec(temp->right);
    	  	node *temp2=temp->left;   // exchanging code
    	  	temp->left=temp->right;
    	  	temp->right=temp2;
		  }
	}

	void mirror_nonrec()
	{   // same as tree traversal just exchange it's r n l links
        queue1 q;
        q.clear();
        q.insert(root);
        node *temp;
        while(!q.isempty())
        {
            temp = q.del();
            if(temp->left!=NULL)
                q.insert(temp->left);
            if(temp->right!=NULL)
                q.insert(temp->right);
            node *exch;
            exch = temp->left;
            temp->left = temp->right;
            temp->right = exch;
        }
	}

   void insert_copyrec(node* root1)
    {
       root=copy_rec(root1);
    }
    node* copy_rec(node* root1)  //copy from root1 to root2
    {   // same as creation
    	node* root2;
    	if(root1==NULL)
    	   return NULL;
    	else
    	{
    		root2=new node(root1->data);
    		no_of_ele++;
			root2->left=copy_rec(root1->left);
			root2->right=copy_rec(root1->right);
		    return root2;
		}
	}

	void copy_nonrec(node* root1) //copy from root1 to root2
	{
        queue1 orig;
        queue1 cop;
        orig.insert(root1);
        node *temp;
        if(root1!=NULL)
        {
            temp = new node(root1->data);
            root = temp;
        }
        cop.insert(temp);
        while(!orig.isempty())
        {
            node *o = orig.del();
            node *c = cop.del();
            if(o->left!=NULL)
            {
                c->left = new node(o->left->data);
                orig.insert(o->left);
                cop.insert(c->left);
            }
            if(o->right!=NULL)
            {
                c->right = new node(o->right->data);
                orig.insert(o->right);
                cop.insert(c->right);
            }
        }
	}

	void deltree(node *temp)
	{
		if(temp!=NULL)
		{
		    cout<<"\n inside delete()";
			deltree(temp->left);
			deltree(temp->right);
			temp=NULL;
		    delete temp;
		    cout<<"\nAfter deletion";
		}
	}

    void operator = (binarytree b)
    {
    	insert_copyrec(b.getroot());
	}

    int count_nodes(node* temp)
    {
    	if(root!=NULL)
    	   {
    	   	count_nodes(temp->left);   //  }->this is just a traversal thru tree
    	   	count_nodes(temp->right);  //  }
    	   	if((temp->left==NULL)&&(temp->right==NULL))
		        {
		     	   leaf_nodes++;
		        }
		   }
    	return leaf_nodes;
	}
};


int main() {
    int choice;
    int c=1,leaf_nodes;
	binarytree obj,obj2;
	queue1 q;
	do
	{
		cout<<"\nEnter\n 1.Create non-recursively.\n 2.Create recursively.\n";
		cin>>choice;
		switch(choice)
		{
		case 1: obj.create_nonrec();  //non-recurrence method
		        cout<<"\nInorder :";
				obj.inorder_nonrec();
				cout<<"\nPreorder :";
			    obj.preorder_nonrec();
			    cout<<"\nPostorder :";
				obj.postorder_nonrec();
				cout<<"\nHeight of tree non-rec :"<<obj.height_nonrec();
				cout<<"\nCopy of tree :";
				obj2.copy_nonrec(obj.getroot());
				cout<<"\nInorder :";
				obj2.inorder_nonrec();
				cout<<"\nPreorder :";
				obj2.preorder_nonrec();
				cout<<"\nPostorder :";
				obj2.postorder_nonrec();
		        cout<<"\nMirror of tree :";
				obj.mirror_nonrec();
				cout<<"\nInorder :";
				obj.inorder_nonrec();
				cout<<"\nPreorder :";
				obj.preorder_nonrec();
				cout<<"\nPostorder :";
				obj.postorder_nonrec();
		        break;
		case 2: obj.insert_rec();
		        cout<<"\nInorder :";
				obj.inorder_rec(obj.getroot());
				cout<<"\nPreorder :";
				obj.preorder_rec(obj.getroot());
				cout<<"\nPostorder :";
				obj.postorder_rec(obj.getroot());
				cout<<"\nHeight of tree :"<<obj.height_rec(obj.getroot());
				cout<<"\nCopy of tree :";
				obj2=obj;
				cout<<"\nInorder :";
				obj2.inorder_rec(obj2.getroot());
				cout<<"\nPreorder :";
				obj2.preorder_rec(obj2.getroot());
				cout<<"\nPostorder :";
				obj2.postorder_rec(obj2.getroot());
				cout<<"\nMirror of tree :";
				obj2.mirror_rec(obj2.getroot());
				cout<<"\nInorder :";
				obj2.inorder_rec(obj2.getroot());
				cout<<"\nPreorder :";
				obj2.preorder_rec(obj2.getroot());
				cout<<"\nPostorder :";
				obj2.postorder_rec(obj2.getroot());
				leaf_nodes=obj.count_nodes(obj.getroot());
				cout<<"\nTotal Interior nodes :"<<(obj.no_of_ele)-leaf_nodes;
				cout<<"\nTotal leaf nodes"<<leaf_nodes;
				break;

		}
		cout<<"\nContinue?(0/1)";
		cin>>c;
	}while(c==1);
}
