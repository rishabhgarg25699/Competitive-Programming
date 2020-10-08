#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;
        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = NULL;
            this->prev = NULL;
        }
};
DoublyLinkedListNode *head=NULL;
/*


		Function to Insert a node in Sorted DLL.

		
*/		
void sortedInsert() 
{
	int data;
	cout<<"Enter element to be inserted in sorted DLL: ";
	cin>>data;
    DoublyLinkedListNode* new_node=new DoublyLinkedListNode(data);
    if(head==NULL)
    {
        head=new_node;
    }
    else if(head->next==NULL)
    {
        if(head->data>data)
        {
            head->prev=new_node;
            new_node->next=head;
            head=new_node;
        }
        else{
            head->next=new_node;
            new_node->prev=head;
        }
    }
    else{
        DoublyLinkedListNode* temp=head;
        DoublyLinkedListNode* pre_temp=head;
        while(temp->next!=NULL && temp->data<data)
        {
            pre_temp=temp;
            temp=temp->next;
        }
        if(temp->prev==NULL)
        {
            temp->prev=new_node;
            new_node->next=temp;
            head=new_node;
        }
       else if(temp->next==NULL)
        {
            if(temp->data<data)
            {
                temp->next=new_node;
                new_node->prev=temp;
            }
            else
            {
                pre_temp->next=new_node;
                new_node->prev=pre_temp;
                new_node->next=temp;
                temp->prev=new_node;
            }
        }
        else
        {
            pre_temp->next=new_node;
            new_node->prev=pre_temp;
            new_node->next=temp;
            temp->prev=new_node;
        }
    }
}
/*

 		Funtion to delete a node fron Sorted DLL.
 		
*/
void sortedDelete() {
	if(head==NULL)
	{
		cout<<"Underflow."<<endl;
		return;
	}
	int del;
	cout<<"Enter the the element to be deleted from Sorted DLL: ";
	cin>>del;
	DoublyLinkedListNode* temp=head;
	DoublyLinkedListNode* pre_temp=head;
	while(temp->data!=del)
	{
		pre_temp=temp;
		temp=temp->next;
	}
	if(temp->prev==NULL)
	{
		temp->next->prev=NULL;
		head=temp->next;
		free(temp);
	}
	else if(temp->next==NULL)
	{
		if(temp->prev==NULL)
		{
			free(temp);
		}
		else
		{
			pre_temp->next=NULL;
			free(temp);
		}
	}
	else
	{
		pre_temp->next=temp->next;
		temp->next->prev=pre_temp;
		free(temp);
	}
}
/*

		Function to display Sorted DLL.
		
*/
void sorteddisplay()
{
	DoublyLinkedListNode* temp=head;
    if(temp==NULL)
    {
        cout<<"\nEmpty list ";
        return;
    }
    while(temp->next!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<temp->data;
}
int main()
{
    char ch;
    do
    {
        cout<<"SORTED DOUBLY LINKED LIST\n";
        cout<<"\nPRESS: ";
        cout<<"\n 1. Insertion";
        cout<<"\n 2. Deletion";
        cout<<"\n 3. Display\n";

        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:sortedInsert();break;
            case 2:sortedDelete();break;
            case 3:sorteddisplay();break;
            default: cout<<"\nInvalid choice...breaking";
        }
        cout<<"\nWant to continue?(y/n)";

        fflush(stdin);
        cin>>ch;
    }while(ch=='y'||ch=='Y');

    return 0;
}
