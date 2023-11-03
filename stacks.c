#include <stdio.h>
//stack array


#include <stdlib.h>

#define MAX 100

struct lifo {

	int st[MAX]

	int top;
};

typedef struct lifo stack;


void create (stack* s){

	(*s).top = -1;

}

void push (stack* s, int element) {

	if((*s).top == (MAX-1)){

		printf("\nStack Overflow");
		exit(-1);

	}

	else {

		(*s).top++;

		s->((*s).top) = element;						//trail
	}
}

int pop (stack *s) {

	if ((*s).top == -1){

		printf ("\nStack underflow");

		exit(-1);
	}

	else {

		return ((*s).st[(*s).top--]);
	}
}

int ifempty(stack s) {

	if (s.to == -1) return 1;

	else return 0;

}

int isfull (stack s) {

	if(s.top == (MAX-1)) return 1;

	else return 0;
}
