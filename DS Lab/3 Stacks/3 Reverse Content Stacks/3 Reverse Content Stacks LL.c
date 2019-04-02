#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *TOP;

int main()
{
	int i,n,x,choice;
	printf("Enter no. of elements in STACK : ");scanf("%d",&n);
	if(n>0)
	{
		for(i=0; i<n; i++)
		{
			printf("Enter the data for element %d : ",i+1);scanf("%d",&x);
			push(x);
		}
		printf("\nCreated STACK : \n");
		displaySTACK();
		printf("\nReversed STACK : \n");
		revSTACK();
	}
	else
	{
		printf("\nInvalid no. of elements");
	}
	return 0;
}

void push(int x)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = TOP;
	TOP = temp;
}

void displaySTACK()
{
	struct node *temp;
	temp = TOP;
	if(TOP == NULL)
	{
		printf("\nSTACK UNDERFLOW\n");
	}
	else
	{
		while(temp != NULL)
		{
			printf("\n%d",temp->data);
			temp = temp->next;
		}
	}
}

void pop()
{
	printf("\nDeleted Element : %d\n",TOP->data);
	TOP = TOP->next;
}

void peek()
{
	printf("\nTop Element : %d\n",TOP->data);
}
void revSTACK()
{
	struct node *prev, *curr;
	
	if(TOP!=NULL)
	{
		prev = TOP;
		
		curr = TOP->next;
		TOP = TOP->next;
		
		prev->next = NULL;
		
		while(TOP!=NULL)
		{
			TOP = TOP->next;
			curr->next = prev;
			
			prev = curr;
			curr = TOP;
		}
		
		TOP = prev;
	}
	displaySTACK();
}
