#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *START, *END;int n;

int main()
{
	int choice;
	crDCLL();
	printf("\nCreated Doubly CLL : \n");
	displayDCLL();
	
	printf("\n\n1 -- for Insertion\n");
	printf("\n2 -- for Deletion\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\nInsertion : \n");
			insNode();
			break;
		case 2:
			printf("\nDeletion : \n");
			delNode();
			break;
		default:
			printf("\nInvalid Choice.\n");
			break;
	}
	
	return 0;
}

void crDCLL()
{
	int i;
	struct node *first;
	START = (struct node*)malloc(sizeof(struct node));
	printf("Enter no. of nodes : ");scanf("%d",&n);
	if(n>=1)
	{
		START->prev = NULL;
		printf("Enter data for node 1 : ");scanf("%d",&START->data);
		START->next = NULL;
		
		END = START;
		for(i=2; i<=n; i++)
		{
			first = (struct node*)malloc(sizeof(struct node));
			printf("Enter data for node %d : ",i);scanf("%d",&first->data);
			first->prev = END;
			first->next =START;
			
			END->next = first;
			END = first;
		}
	}
	else
	{
		printf("\nInvalid no. of nodes.\n");
	}
}

void displayDCLL()
{
	struct node *temp;
	temp = START;
	while(temp->next != START)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("%d\nReverse : \n",temp->data);
	displayRevDCLL();
}

void displayRevDCLL()
{
	struct node *temp;
	temp = START;
	while(temp->next != START)
	{
		temp = temp->next;
	}
	while(temp != START)
	{
		printf("%d\t",temp->data);
		temp = temp->prev;
	}
	printf("%d",temp->data);
}

void insNode()
{
	int i, pos;
	struct node *temp, *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data for new node : ");scanf("%d",&newNode->data);newNode->prev=NULL;newNode->next=NULL;
	temp = START;
	if(START == NULL)
	{
		START = newNode;START->next = START;
	}
	else
	{
		printf("\nEnter position to insert node : ");scanf("%d",&pos);
		if(pos == 1)
		{
			while(temp->next != START)
			{
				temp = temp->next;
			}
			newNode->next = START;
			newNode->prev = temp;
			temp->next = newNode;
			START->prev = newNode;
			START = newNode;
			printf("\nFinal Doubly CLL : \n");
			displayDCLL();
		}
		else if(pos == n)
		{
			while(temp->next != START)
			{
				temp = temp->next;
			}
			newNode->next = START;
			newNode->prev = temp;
			temp->next = newNode;
			START->prev = newNode;
			printf("\nFinal Doubly CLL : \n");
			displayDCLL();
		}
		else if(pos>1 && pos<n)
		{
			for(i=1; i<pos-1; i++)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next = newNode;
			temp->next->next->prev = newNode;
			printf("\nFinal Doubly CLL : \n");
			displayDCLL();
		}
		else
		{
			printf("\n%d is invalid position\n",pos);
		}
	}
}

void delNode()
{
	int i, pos;
	struct node *temp;
	temp = START;
	if(START == NULL)
	{
		printf("\nEmpty List.\n");
	}
	else
	{
		printf("\nEnter position to delete node : ");scanf("%d",&pos);
		if(pos == 1)
		{
			while(temp->next != START)
			{
				temp = temp->next;
			}
			START = START->next;
			temp->next = START;
			printf("\nFinal Doubly CLL : \n");
			displayDCLL();
		}
		else if(pos == n)
		{
			while(temp->next->next != START)
			{
				temp = temp->next;
			}
			temp->next = START;
			START->prev = temp;
			printf("\nFinal Doubly CLL : \n");
			displayDCLL();
		}
		else if(pos>1 && pos<n)
		{
			for(i=1; i<pos-1; i++)
			{
				temp = temp->next;
			}
			temp->next->next->prev = temp;
			temp->next = temp->next->next;
			printf("\nFinal Doubly CLL : \n");
			displayDCLL();
		}
		else
		{
			printf("\n%d is invalid position\n",pos);
		}
	}
}
