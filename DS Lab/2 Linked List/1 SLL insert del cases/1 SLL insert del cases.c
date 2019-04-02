#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *START;
int n;

int main()
{
	crSLL();
	
	printf("\nCreated SLL : \n");
	displaySLL();
	
	int choice;
	while(1)
	{
		printf("\n\n1 -- for Inserting a node in an SLL\n");
		printf("\n2 -- for Deleting a node in an SLL\n");
		printf("\nEnter your choice : ");scanf("%d",&choice);
		if(choice == 1)
			insNode();
		else if(choice == 2)
			delNode();
		else
			break;
	}
	return 0;
}

void crSLL()
{
	int i;
	printf("Enter no. of nodes : ");
	scanf("%d",&n);
	if(n>0)
	{
		struct node *temp, *first;
		START = (struct node*)malloc(sizeof(struct node));
		printf("Enter data for node 1 : ");
		scanf("%d",&START->data);
		START->next = NULL;
		
		temp = START;
		for(i=2; i<=n; i++)
		{
			first = (struct node*)malloc(sizeof(struct node));
			printf("Enter data for node %d : ",i);
			scanf("%d",&first->data);
			first->next = NULL;
			
			temp->next = first;
			temp = first;
		}
	}
	else
		printf("\nInvalid no. of nodes");
}

void displaySLL()
{
	struct node *temp;
	temp = START;
	if(temp == NULL)
	{
		printf("\nEmpty List");
	}
	else
	{
		while(temp != NULL)
		{
			printf("%d\t",temp->data);
			temp = temp->next;
		}
	}
}

void insNode()
{
	int posi = 0;
	
	struct node *newNode;
	
	newNode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data for new node : ");
	scanf("%d",&newNode->data);
	newNode->next = NULL;
	
	printf("\nEnter position for inserting node : ");
	scanf("%d",&posi);
	
	if(posi == 1)
	{
		newNode->next = START;
		START = newNode;
		printf("\nFinal SLL : \n");
		displaySLL();
		n++;
	}
	else if(posi == n)
	{
		int i = 1;
		struct node *temp;
		temp = START;
		while(i<=n && temp->next != NULL)
		{
			i++;
			temp = temp->next;
		}
		temp->next = newNode;
		printf("\nFinal SLL : \n");
		displaySLL();
		n++;
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
		newNode->next = temp->next;
		temp->next = newNode;
		printf("\nFinal SLL : \n");
		displaySLL();n++;
	}
	else
	{
		printf("\nInvalid position\n");
		printf("\nFinal SLL : \n");
		displaySLL();
	}
}

void delNode()
{
	int posi = 0;
	
	struct node *temp;
	temp = START;
	
	printf("\nEnter position to delete node : ");
	scanf("%d",&posi);
	
	if(posi == 1)
	{
		START = START->next;
		printf("\nFinal SLL : \n");
		displaySLL();
		n--;
	}
	else if(posi == n)
	{
		struct node *temp;
		temp = START;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = NULL;
		printf("\nFinal SLL : \n");
		displaySLL();
		n--;
	}
	else if(1<posi<n)
	{
		int i = 1;
		struct node *temp;
		temp = START;
		
		while(i<posi-1 && temp != NULL)
		{
			temp = temp->next;
			i++;
		}
		temp->next = temp->next->next;
		printf("\nFinal SLL : \n");
		displaySLL();
		n--;
	}
	else
	{
		printf("\nInvalid position\n");
		printf("\nFinal SLL : \n");
		displaySLL();
	}
}
