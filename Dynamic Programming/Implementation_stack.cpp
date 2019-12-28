// C++ program to Implement a stack
//using linked list and classes
#include <bits/stdc++.h>
using namespace std;

// Declare linked list class

class STACK {

   int value;                     //stores value of node

  class STACK* LINK;             //pointer to the next node

  STACK();                       //constructer to initialise stack to NULL

                    //Declaring functions of the STACK CLASS....

  int isEmptystack();           //private function: to check if the stack is empty or not

  public: //public functions:

  void push_value(int value);   // 1. PUSH: Function to add an element to the top of the stack

  void pop_value();             //2. POP: Function to pop top element from the stack

  void display_stack();         //3. DISPLAY: Function to print all the elements of the stack

  void TOP_value();             //4. PEEK: Function to display the topmost value of stack

};

                       //DEFINING all the above listed functions...

STACK::STACK()
{
  class STACK* top;
  top=NULL;
}


int STACK::isEmptystack()
{
	return top == NULL;
}

void STACK::push_value(int value)
{
	// create new node temp and allocate memory
  STACK* temp;
	temp = new STACK();

	// check if stack (heap) is full. Then inserting an element would
	// lead to stack overflow
	if (!temp)
  {
		cout << "\nHeap Overflow";
		exit(1);
	}

 //assign the value to temp
  temp->value=value;

// link temp to the top
  temp->LINK=top;

//make new node temp the top of the list..
  top=temp;

//release memory of the temp...
  free(temp);

}

void STACK::pop_value()
{

	// check for stack underflow
	if (isEmptystack()) {
		cout << "\nStack is Empty" << endl;
		exit(1);
	}
	else {

    STACK* temp;
		// assign top to temp
		temp = top;

		// assign NEXT node to top
		top = top->LINK;

    //link the temp node to NULL to disconnect it from the list...
    temp->LINK==NULL;

    //display the element..
    cout<<"Element popped:"<<temp->value;

		// release memory of the node
		free(temp);
	}
}


void STACK::display_stack()
{
	STACK* temp;

	//checking for empty stack..
	if (top == NULL) {
		cout << "\nStack is Empty";
	}
	else
  {
		temp = top;
		while (temp != NULL)
    {

			// printing current node data..
			cout << temp->data << " ";

			// assign temp link to temp i.e moving to the next node..
			temp = temp->link;
		}
	}
  free(temp);
}

STACK::TOP_value()
{
 cout<<"Top_value:"<<top->value;
}

// illustrating and creating a stack in main ..

int main()
{
  STACK OB1; //creating an object of a stack class
    //likewise we can create multiple stacks by creating multiple objects!!

	// push the elements to the stack
	OB1.push_value(96);
	OB1.push_value(54);
	OB1.push_value(32);
	OB1.push_value(81);
  OB1.push_value(23);

  //illustrating some more fuctions

	// display stack elements
	OB1.display_stack();

	// delete top 2 elements of stack
	OB1.pop_value();
	OB1.pop_value();

 //displaying the top value of the stack
  OB1.TOP_value();

	// displaying all stack elements after pop function
	OB1.display_stack();

	return 0;
}
