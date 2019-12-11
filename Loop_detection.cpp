#include <bits/stdc++.h>
using namespace std;

//Declaring of linked list node
struct Node
{
	int data;
	Node* next;
};

//Function to insert a node
void push(Node*& head, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}


//Floyd’s cycle detection function
bool isCycle(Node *head)
{
	// There are two pointers
	Node *first = head, *second = head;
	while (second && second->next)
	{
		//move first poiner by one pointer
		first = first->next;
		//move second pointer by two pointers
		second = second->next->next;
		//linked list contains a cycle if they meet
		if (first == second)
		   return true;
	}
	return false;
}

int main()
{
    //Sample input
	int data[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(data) / sizeof(data[0]);

	Node* head = nullptr;
	for (int i = n - 1; i >= 0; i--)
		push(head, data[i]);
	if (isCycle(head))
		cout << "Cycle Found";
	else
		cout << "No Cycle Found";

    //No cycle found
	return 0;
}
