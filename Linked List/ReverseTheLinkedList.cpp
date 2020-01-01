#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *link;
};

node *head;

//print the list
void show() {
	cout<<"The list is"<<endl;
	node *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<endl;
}


//insertaion at first
void addfirst(int n) {
	node *temp = new node;
	temp->data = n;
	temp->link = NULL;
	
	
	if(head!=NULL) {
		temp->link = head;		
	}
	
	head = temp;
}


//reverse a list
node* rev() {
	node *cur,*prev,*next;
	
	cur = head;
	prev = NULL;
	while(cur != NULL) {
		
		next = cur->link;
		cur->link = prev;
		
		prev = cur;
		cur = next;
		
	}
	head = prev;
	return head;
}


int main() {
	head=NULL;
	
	addfirst(1);
	addfirst(54);
	addfirst(21);
	addfirst(44);
	addfirst(15);
	show();
	
	rev();
	cout<<"After reversing ";
	show();
	
	return 0;
}

