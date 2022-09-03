//To implement a static circular queue

#include <iostream>

using namespace std;

#define MAXSIZE 5

class queue                    //making an object queue
{
  int arr[MAXSIZE];
  int front = -1;              //initialising front
  int rear = -1;	       //initialising rear

public:

  void add (int x)             //adding an element to the queue
  {
    if (rear == -1)
      {
	front = 0;
	rear = 0;
      }

    else if (rear + 1 == front || (rear == MAXSIZE - 1 && front == 0))
      cout << endl << "Overflow" << endl;

    else if (rear == MAXSIZE - 1)
      rear = 0;

    else
      rear++;

    arr[rear] = x;
  }

  int rem ()                  //removing an element to the queue
  {
    int x = 0;

    if (front == -1)
      cout << endl << "Underflow" << endl;

    else if (front == rear)
      {
	x = arr[front];
	front = rear = -1;
      }

    else if (front == MAXSIZE - 1)
      {
	x = arr[front];
	front = 0;
      }

    else
      x = arr[front++];

    return x;
  }
};

queue q;

int main ()
{
  int x;

  do
    {
      cout << "1.Add\n2.Remove\n3.Exit\n";
      cin >> x;

      if (x == 1)
	{
	  int n;
	  cin >> n;
	  q.add (n);
	}

      if (x == 2)
	{
	  cout << endl << q.rem () << endl;
	}

    }
  while (x != 3);

  return 0;
}

