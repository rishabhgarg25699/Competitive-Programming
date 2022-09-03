#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    struct node *next;
}*head=NULL;

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
void insertBegin()
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    cout<<"Enter the value to be inserted in linked list : ";
    cin>>newNode->value;
    newNode->next=NULL;
    if(head!=NULL)
        newNode->next=head;
    head=newNode;
}
void insertMiddle()
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    cout<<"Enter the value to be inserted in linked list : ";
    cin>>newNode->value;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    cout<<"\nEnter the element after which you want to enter the new node :  ";
    int index;
    cin>>index;
    struct node* currentNode=(struct node*)malloc(sizeof(struct node));
    currentNode=head;
    bool flag=true;
    while(true)
    {
        if(currentNode->value==index)
            break;
        if(currentNode->next==NULL)
        {
            flag=false;
            break;
        }
        currentNode=currentNode->next;
    }
    if(!flag)
    {
        cout<<"\nElement not found!!";
    }
    else
    {
        newNode->next=currentNode->next;
        currentNode->next=newNode;
    }


}

void insertEnd()
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    cout<<"Enter the value to be inserted in linked list : ";
    cin>>newNode->value;
    newNode->next=NULL;
    struct node* currentNode=(struct node*)malloc(sizeof(struct node));
    currentNode=head;
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    while(currentNode->next!=NULL)
        currentNode=currentNode->next;

    newNode->next=currentNode->next;
    currentNode->next=newNode;

}

void insertion()
{
    cout<<"\n\nINSERTION in linked list\n";
    cout<<"\nWhere would you like to do? ";
    cout<<"\n 1. Beginning";
    cout<<"\n 2. Middle";
    cout<<"\n 3. End\n";

    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:insertBegin();break;
        case 2:insertMiddle();break;
        case 3:insertEnd();break;
        default: cout<<"Invalid choice...breaking";
    }
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

void deleteBegin()
{
    if(head==NULL)
        {
            cout<<"\nUNDERFLOW";
            return;
        }
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=head;

    head=head->next;
    free(temp);
}

void deleteMiddle()
{
    if(head==NULL)
    {
        cout<<"\nUNDERFLOW!";
        return;
    }

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    cout<<"Enter the Element to be deleted ";
    int item;
    cin>>item;
    if(head->value==item)
    {

        head=head->next;
        free(temp);
        return;
    }
    while(temp->next!=NULL)
    {

        if(temp->next->value==item)
        {
            struct node* t=temp->next;
            temp->next=temp->next->next;
            free(t);
            return;
        }
        temp=temp->next;
    }
    cout<<"\nElement not found";
}

void deleteEnd()
{
    if(head==NULL)
    {
        cout<<"\nUnderflow!";
        return;
    }

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    struct node* t=temp->next;
    temp->next=NULL;
    free(t);

}

void deletion()
{
    cout<<"\n\nDELETION in linked list\n";
    cout<<"\nWhere would you like to do? ";
    cout<<"\n 1. Beginning";
    cout<<"\n 2. Middle";
    cout<<"\n 3. End\n";

    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:deleteBegin();break;
        case 2:deleteMiddle();break;
        case 3:deleteEnd();break;
        default: cout<<"Invalid choice...breaking";
    }
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void display()
{
    struct node* currentNode=(struct node*)malloc(sizeof(struct node));
    currentNode=head;
    if(currentNode==NULL)
    {
        cout<<"\nEmpty list ";
        return;
    }
    while(currentNode!=NULL)
    {
        cout<<currentNode->value<<" -> ";
        currentNode=currentNode->next;
    }
}

int main()
{
    char ch;
    do
    {
        cout<<"LINKED LIST\n";
        cout<<"\nWhat would you like to do? ";
        cout<<"\n 1. Insertion";
        cout<<"\n 2. Deletion";
        cout<<"\n 3. Display\n";

        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:insertion();break;
            case 2:deletion();break;
            case 3:display();break;
            default: cout<<"\nInvalid choice...breaking";
        }
        cout<<"\nWould you like to operate again?(y/n)";

        fflush(stdin);
        cin>>ch;
    }while(ch=='y');

    return 0;
}
