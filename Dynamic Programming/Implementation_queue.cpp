// C++ program to Implement a QUEUE
//using linked list and classes

#include <bits/stdc++.h>
using namespace std;

// Declare linked list queue class

class QUEUE {

   int value;                     //stores value of node

  class QUEUE* LINK;             //pointer to the next node

  QUEUE();                       //constructer to initialise front and rear pointers to NULL

                    //Declaring functions of the QUEUE CLASS....

  int isEmptyqueue();           //private function: to check if the queue is empty or not

  public: //public functions:

  void enqueue(int value);   // 1. Function to add an element at the back of the queue

  void dequeue();             //2. Function to remove the front most element of the queue queue

  void display_queue();         //3. Function to print all the elements of the queue

};

                       //DEFINING all the above listed functions...

QUEUE::QUEUE()
{
  class QUEUE* front, rear ;
  front=rear=NULL;                  //initialising front and rear to NULL
}


int QUEUE::isEmptyqueue()
{
	return front == NULL;              //returns true or false value
}

void QUEUE::enqueue(int value)
{
	// create new node temp and allocate memory
  QUEUE* temp;
	temp = new QUEUE();

	// check if heap is full. Then inserting an element would
	// lead to overflow
	if (!temp)
  {
		cout << "\nHeap Overflow";
		exit(1);
	}

  //assign the value to temp
   temp->value=value;

 // give pointer of temp null value
   temp->LINK=NULL;

  if(front==NULL)
  {
    front=rear=temp;                 // if front is null i.e. queue is empty, we assign the value to both front and rear
  }

else                                // else we assign the value at the back of the queue using temp
 {

  //link the temp to the list(i.e. queue)...
  rear->LINK=temp;

  //make temp the rear side of the list(queue)...
  rear=temp;

  
 }


//release memory of the temp...
  free(temp);

}

void QUEUE::dequeue()
{

	// check for queue underflow
	if (isEmptyqueue()) {
		cout << "\nqueue is Empty" << endl;
	}
	else {

    QUEUE* temp;
		// assign front to temp
		temp = front;

		// assign NEXT node to front
		front = front->LINK;

    if(isEmptyqueue())
      rear=NULL;
    //link the temp node to NULL to disconnect it from the queue...
    temp->LINK==NULL;

    //display the element..
    cout<<"Front most element deleted:"<<temp->value<<endl;

		// release memory of the node...
		free(temp);
	}
}


void QUEUE::display_queue()
{
	QUEUE* temp;

	//checking for empty queue..
	if (isEmptyqueue()) {
		cout << "\nQueue is Empty";
	}
	else
  {
   //assign temp the front most value...
     temp = front;
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

QUEUE::FRONT_REAR_value()
{
 cout<<"FRONTvalue:"<<front->value;
 cout<<"REAR value"<<rear->value;
}

// illustrating and creating a queue in main ..

int main()
{
  QUEUE OB1; //creating an object of a queue class
    //likewise we can create multiple queues by creating multiple objects!!

	// performing enqueue function...
	OB1.enQueue(36);
	OB1.enQueue(72);
	OB1.enQueue(108);
	OB1.enQueue(144);

  //illustrating some more fuctions

	// displaying queue elements...
	OB1.display_queue();

	// delete  2 elements from front...
	OB1.deQueue();
	OB1.deQueue();

  OB1.enQueue(93);

 //displaying the front and rear values of the queue...
  OB1.FRONT_REAR_value();

	// displaying the queue after the above changes...
	OB1.display_queue();

	return 0;
}
