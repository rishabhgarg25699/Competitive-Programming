//finding intersection of linked list which are in descending order
#include<iostream>

using namespace std;
struct nodelink
{
	int data;
	struct nodelink *next;
};
 typedef struct nodelink node;
node *intersect(node *l1,node *l2)//accepting head nodes of two linked list whicj have data stored in descending order
{
	node *p1,*p2;
	p1=l1;
	p2=l2;
	while(1)
	{
		if(p1->data == p2->data)//if equal than return the pointer
		return p1;
		else if(p1->data>p2->data)//if more than point to the next node of p1
		p1=p1->next;
		else
		p2=p2->next;//else point to next node of p2
	}
}
void create(node **r)
{
	int i,n,v;
	cout<<"enter the number of values in linked list";//accepting the number of values in linked list
	cin>>n;
	node *p,*q;
	for(i=0;i<n;i++)
	{
		p=new node();
		cout<<"enter the value"<<endl;
		cin>>v;
		p->data=v;
		p->next=NULL;

		if(*r==NULL)
		*r=p;
		else
		q->next=p;
		q=p;
	}

}
void print(node *r)
{
	node *p;
	p=r;
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}

int main()
{
	node *head1,*head2;
	head1=NULL;
	head2=NULL;
	create(&head1);
	create(&head2);
	cout<<"FIRST LINKED LIST"<<endl;
	print(head1);
	cout<<"SECOND LINKED LIST"<<endl;
	print(head2);
	node *inter;
	inter=intersect(head1,head2);
	print(inter);
}


