#include<bits/stdc++.h> 
#define SIZE 100 //default stack size

using namespace std;

//Stack Implementation

class Stack {
	int *arr;		//pointer to stack
	int top;		//index of topmost element in stack
	int capacity;	//maximum size of stack

public:
	Stack(int size = SIZE);
	~Stack();
	void push(int);
	int pop();
	int size();
	bool isEmpty();
	bool isFull();
};

//Constructor for class stack initialized with size of stack
Stack::Stack(int size) {
	arr = new int[size];
	capacity = size;
	top = -1;
}

//destructor for class stack
Stack::~Stack() {
	delete arr;
}

//function to push element into stack
void Stack::push(int x) {
	if(isFull()) {
		cout<<"Stack Overflow!!!"<<endl;
	}
	else {
		cout<<"Inserting "<<x<<" into the stack..."<<endl;
		top++;
		arr[top] = x;
	}
}

//function to pop element from stack
int Stack::pop() {
	if(isEmpty()) {
		cout<<"Stack Empty!!!"<<endl;
	}
	else {
		cout<<"Removing "<<arr[top]<<" from the stack..."<<endl;
		return arr[top];
		top--;
	}
}

//function to return stack size
int Stack::size() {
	return top+1;
}

//function to check whether stack is empty
bool Stack::isEmpty() {
	return top==-1;
}

//function to check whether stack has reached maximum capacity
bool Stack::isFull() {
	return top == capacity-1;
}

int main() {

	return 0;
}