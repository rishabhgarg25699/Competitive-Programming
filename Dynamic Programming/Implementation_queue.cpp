// C++ program to Implement a QUEUE
//using linked list and classes
#include <bits/stdc++.h>
using namespace std;

// Declare linked list queue class

class QUEUE
{
  int value;
  class QUEUE* LINK;
  QUEUE();
                    //Declaring functions of the QUEUE CLASS..
  int isEmptyqueue();
  public:
  void enqueue(int value);
  void dequeue();
  void display_queue();
};

                       //DEFINING all the above listed functions...
//constructer to initialise front and rear pointers to NULL
QUEUE::QUEUE()
{
  class QUEUE* front, rear ;
  front=rear=NULL;
}

// to check if the queue is empty or not
int QUEUE::isEmptyqueue()
{
	return front == NULL;              //returns true or false value
}

// Function to add an element at the back of the queue
void QUEUE::enqueue(int value)
{
  QUEUE* temp;
	temp = new QUEUE();               // create new node temp and allocate memory
	if (!temp)
  {
		cout << "\nHeap Overflow";       //check for heap overfloW
		exit(1);
	}
   temp->value=value;
   temp->LINK=NULL;

if(front==NULL)
{
    front=rear=temp;                 // if front is null i.e. queue is empty, we assign the value to both front and rear
}
else
{
  rear->LINK=temp;
  rear=temp;
}
  free(temp);
}

// Function to remove the front most element of the queue
void QUEUE::dequeue()
{
	if (isEmptyqueue()) {
		cout << "\nqueue is Empty" << endl;
	}
	else
  {
    QUEUE* temp;
		temp = front;                                   //assign front to temp
		front = front->LINK;
    if(isEmptyqueue())
      rear=NULL;
    temp->LINK==NULL;                               //disconnect temp from the list
    cout<<"Front most element deleted:"<<temp->value<<endl;
		free(temp);
	}
}

//Function to print all the elements of the queue
void QUEUE::display_queue()
{
	QUEUE* temp;
	if (isEmptyqueue()) {
		cout << "\nQueue is Empty";
	}
	else
  {
     temp = front;
		while (temp != NULL)
    {
			cout << temp->data << " ";
			temp = temp->link;
		}
	}
  free(temp);
}

// illustrating and creating a queue in main ..
int main()
{
  int n,j;
  cout<<"Enter the no. of queues to be created:";
  cin>>j;
  QUEUE* OB[j];
  for(int i=0;i<j;i++)
  {
    char y='y';
    cout<<"\n Enter queue no. "<<i+1<<":";
    while(y=='y')
    {
      int value;
      cout<<"\n Enter element:";
      cin>>value;
      OB[i].enqueue(value);
      cout<<"\n press y to enter another element:";
      cin>>y;
    }
  }
  //illustrating some more fuctions....
	// displaying queues...
	for(int i=0;i<j;i++)
  {
    cout<<"\n Displaying queue no. "<<i+1<<":";
    OB[i].display_queue();
  }
// dequeue function...
 cout<<"\nEnter queue no. to be dequeued:";
 cin>>n;
 if(n<=j)
 {
  char y='y';
  while(y=='y')
  {
    OB[n-1].dequeue();
    cout<<"\npress y to continue:";                               //if you want to dequeue one more element from list
    cin>>y;
  }
 }
 else
  cout<<"\nQueue not present!";
	return 0;
}
