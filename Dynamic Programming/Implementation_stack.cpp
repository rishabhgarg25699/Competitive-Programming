// C++ program to Implement a stack
//using linked list and classes
#include <bits/stdc++.h>
using namespace std;

// Declare linked list class
class STACK {
   int value;                     //stores value of node
   class STACK* LINK;             //pointer to the next node
   STACK();
                    //Declaring functions of the STACK CLASS....
  int isEmptystack();
  public:
  void push_value(int value);
  void pop_value();
  void display_stack();
  void TOP_value();
};

                       //DEFINING all the above listed functions...
//constructer to initialise stack to NULL
STACK::STACK()
{
  class STACK* top;
  top=NULL;
}
// Function to check if the stack is empty or not
int STACK::isEmptystack()
{
	return top == NULL;
}

// 1. PUSH: Function to add an element to the top of the stack
void STACK::push_value(int value)
{
  STACK* temp;
 	temp = new STACK();
	if (!temp)
		cout << "\nHeap Overflow";                 //checking for memory overflow...
	else
  {
   temp->value=value;
   temp->LINK=top;
   top=temp;                                   //assigning temp to top...
  }
  free(temp);
}

 //2. POP: Function to pop top element from the stack
void STACK::pop_value()
{
	if (isEmptystack())
		cout << "\nStack is Empty" << endl;

	else {
    STACK* temp;
		temp = top;
		top = top->LINK;
    temp->LINK==NULL;                          //disconnecting temp from the list
    cout<<"Element popped:"<<temp->value;
		free(temp);                                //releasing memory of temp
	}
}

//3. DISPLAY: Function to print all the elements of the stack
void STACK::display_stack()
{
	STACK* temp;
	if (top == NULL) {
		cout << "\nStack is Empty";
	}
	else
  {
		temp = top;
		while (temp != NULL)
    {
			cout << temp->data << " ";                //displaying element value..
			temp = temp->link;
		}
	}
  free(temp);                                   //releasing memory of temp
}

//4. PEEK: Function to display the topmost value of stack
STACK::TOP_value()
{
 cout<<"Top_value:"<<top->value;
}

// illustrating and creating stacks in main ..
int main()
{
  int n,j;
  cout<<"Enter the no. of stacks to be created:";                 //creating multiple stacks
  cin>>j;
  STACK* OB[j];
  for(int i=0;i<j;i++)
  {
    char y='y';
    cout<<"\n Enter stack no. "<<i+1<<":";
    while(y=='y')
    {
      int value;
      cout<<"\n Enter element:";
      cin>>value;
      OB[i].push_value(value);                                //push_function...
      cout<<"\n press y to enter another element:";
      cin>>y;
    }
  }
  //illustrating some more fuctions....
	// displaying stacks...
	for(int i=0;i<j;i++)
  {
    cout<<"\n Displaying stack no. "<<i+1<<":";
    OB[i].display_stack();
  }
// pop function...
 cout<<"\nEnter stack no. to pop its element(s):";
 cin>>n;
 if(n<=j)
 {
  char y='y';
  while(y=='y')
  {
    OB[n-1].pop_value();
    cout<<"\npress y to continue:";
    cin>>y;
  }
 cout<<"\nCurrent ";
 OB[n-1].TOP_value();                                            //displaying top value...
 }
 else
  cout<<"\nstack not present!";
	return 0;
}
