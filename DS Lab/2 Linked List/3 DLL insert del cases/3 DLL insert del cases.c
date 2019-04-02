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
	crDLL();
	
	displayDLL();
	
	int choice;
	printf("\n\n1 -- for Inserting Node in a DLL\n");
	printf("\n2 -- for Deleting Node in a DLL\n");
	printf("\nEnter your choice : ");scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\nInserting Node : \n");
			insNode();
			break;
		case 2:
			printf("\nDeleting Node : \n");
			delNode();
			break;
		default:
			break;
	}
	return 0;
}

void crDLL()
{
	int i;
	struct node *first;
	START = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter the no. of nodes : ");
	scanf("%d",&n);
	if(n>0)
	{
		START->prev = NULL;
		printf("Enter data for node 1 : ");
		scanf("%d",&START->data);
		START->next = NULL;
		
		END = START;
		for(i=2; i<=n; i++)
		{
			first = (struct node*)malloc(sizeof(struct node));
			first->prev = END;
			printf("Enter data for node %d : ", i);
			scanf("%d",&first->data);
			first->next = NULL;
			
			END->next = first;
			END = first;
		}
	}
	else
	{
		printf("\nInvalid no. of nodes.\n");
	}
}

void displayDLL()
{
	struct node *temp, *temp2;
	temp = START;
	temp2 = END;
	
	printf("\nCreated DLL : \n");
	while(temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	
	printf("\nReverse DLL : \n");
	while(temp2 != NULL)
	{
		printf("%d\t", temp2->data);
		temp2 = temp2->prev;
	}
}

void insNode()
{
	int posi;
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->prev = NULL;
	printf("Enter data for new node : ");
	scanf("%d",&newNode->data);
	newNode->next = NULL;
	
	printf("Enter the position for inserting new node : ");
	scanf("%d",&posi);
	if(posi == 1)
	{
		newNode->next = START;
		newNode->prev = NULL;
		START->prev = newNode;
		START = newNode;
		displayDLL();
	}
	else if(posi == n)
	{
		END->next = newNode;
		newNode->prev = END;
		END = newNode;
		displayDLL();
	}
	else if(1<posi<n)
	{
		int i = 1;
		struct node *temp;
		temp = START;
		while(i<posi-1 && temp!=NULL)
		{
			temp = temp->next;
			i++;
		}
		newNode->prev = temp;
		newNode->next = temp->next;
		temp->next->prev = newNode;
		temp->next = newNode;
		displayDLL();
	}
	else
	{
		printf("\nInsertion not possible\n");
	}
}

void delNode()
{
	int posi;
	printf("Enter the position to delete node : ");
	scanf("%d",&posi);
	if(posi == 1)
	{
		START = START->next;
		START->prev = NULL;
		displayDLL();
	}
	else if(posi == n)
	{
		struct node *temp;
		temp = START;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		temp->next->prev = NULL;
		temp->next = NULL;
		END = temp;
		displayDLL();
	}
	else if(1<posi<n)
	{
		int i = 1;
		struct node *temp;
		temp = START;
		while(i<posi-1 && temp != NULL)
		{
			i++;
			temp = temp->next;
		}
		temp->next->next->prev = temp->next->prev;
		temp->next = temp->next->next;
		displayDLL();
	}
	else
	{
		printf("\nDeletion not possible\n");
	}
}
