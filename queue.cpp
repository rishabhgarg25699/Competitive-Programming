#include<bits/stdc++.h> 
#define SIZE 100 //default stack size


using namespace std;

//Queue implementation

class Queue {
	int *arr; //pointer to queue
	int front,rear,size,capacity;
public:
	Queue(int s = SIZE);
	~Queue();
	void enqueue(int x);
	int dequeue();
	int qsize();
	bool isEmpty();
	bool isFull();
};

//Constructor for class Queue initialized with size of queue
Queue::Queue(int s) {
	arr = new int[s];
	capacity = s;
	front = 0;
	rear = -1;
	size = 0;
}

//destructor for class Queue
Queue::~Queue() {
	delete arr;
}

//function to push element into queue
void Queue::enqueue(int x) {
	if(isFull()) {
		cout<<"Queue Overflow!!!"<<endl;
	}
	else {
		cout<<"Inserting "<<x<<" into the queue..."<<endl;
		size++;
		rear = (rear+1)%capacity;
		arr[rear]=x;
	}
}

//function to remove element from queue
int Queue::dequeue() {
	if(isEmpty()) {
		cout<<"Queue Empty!!!"<<endl;
	}
	else {
		cout<<"Removing "<<arr[front]<<" from the queue..."<<endl;
		int temp = arr[front];
		size--;
		front = (front+1)%capacity;
		return temp;
	}
}


//function to return size of queue
int Queue::qsize() {
	return size;
}

//function to check if queue is empty or not
bool Queue::isEmpty() {
	return(size==0);
}

//function to check if queue is full or not
bool Queue::isFull() {
	return(size==capacity);
}

int main() {

	return 0;
}

