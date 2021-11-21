#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char stack[50];
int top=-1;

void push(char ch)
{
	stack[++top]=ch;
}

int pop(){
	return(stack[top--]);
}

int prior(char ch)
{
    int p;

	if(ch=='#' || ch=='(')
		p=1;
	if(ch=='+' || ch=='-')
		p=2;
	if(ch=='*' || ch=='/')
		p=3;
	if(ch=='$' || ch=='^')
		p=4;

	return p;
}

int main()
{
	char infix[100], postfix[100];
	int i=0,j=0;

	printf("Enter infix expression: ");
	scanf("%s",infix);

	push('#');

	for (int i = 0; i < strlen(infix); i++)
	{
		if(isalnum(infix[i]))
			postfix[j++]=infix[i];

		else if(infix[i] == '(')
			push(infix[i]);

		else if(infix[i]==')')
		{
			while(stack[top]!='(')
				postfix[j++] = pop();
			pop();
		}

		else
		{
			while(prior(stack[top])>=prior(infix[i]))
				postfix[j++]=pop();
			push(infix[i]);
		}
	}

	while(stack[top]!='#')
		postfix[j++]=pop();
	postfix[j]='\0';

	printf("Postfix expression: ");
	printf("%s\n",postfix);
	return 0;
}
