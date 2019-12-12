#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node* left;
	struct node* right;
};
typedef struct node *NODE;

NODE insert(NODE, int);
NODE navigate(NODE);

int main()
{
	NODE first =NULL;              //This is the first node of the doubly linked list
	int page, ch;

	for (;;)
	{
		printf("\nPress 1:Insert Page 2:Navigate else Exit\n");
		scanf("%d",&ch);

		switch(ch){
			case 1: printf("Enter Page: ");     		 //Page number is entered
					scanf("%d",&page);
					first= insert(first, page);
					break;
			case 2: first = navigate(first);
					break;

			default: exit(0);
		}
	}
}


NODE insert(NODE first, int page){
	NODE newnode, pres;                                                      //Here 'pres' is the present node

	newnode = (NODE) malloc (sizeof(struct node));
	newnode -> info = page;
	newnode -> left = newnode -> right =NULL;

	if(first == NULL){
		first = newnode;
		return first;
	}

	pres = first;
	while(pres->right != NULL)
		pres = pres -> right;

	newnode -> left = pres;
	pres -> right = newnode;												//Node is inserted at the front position

	return first;

}

NODE navigate(NODE first){

	int ch;
	NODE pres = first;

	for (;;)
	{
		printf("\nNavigate::  1:Backward 2:Forward  else Main Menu\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: if(first==NULL)											//For Backward Navigation
					{
						printf("Navigation not possible.\n");
						return first;
					}
					else if(pres->left == NULL)
						printf("Backward Navigation not possible\n");
					else
					{
						printf("User is at %d page\t",pres->info);
						pres = pres -> left;
						printf("User moved to %d page\n",pres->info);
					}
					first = pres;
					break;

			case 2: if (first == NULL)										//for Forward Navigation
					{
						printf("Navigation not possible\n");
						return first;
					}
					else if (pres->right == NULL)
						printf("Forward Navigation is not possible\n");
					else
					{
						printf("User is at %d page\t",pres->info);
						pres=pres->right;
						printf("User moved to %d page\n",pres->info);
					}
					first = pres;
					break;

			default: return first;
		}
	}
}

