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
	int choice;
	crSCLL();
	printf("\nCreated Single CLL : \n");
	displaySCLL();
	
	printf("\n\n1 -- for Insertion\n");
	printf("\n2 -- for Deletion\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\nInsertion : \n");
			insSCLL();
			break;
		case 2:
			printf("\nDeletion : \n");
			delSCLL();
			break;
		default:
			printf("\nInvalid Choice.\n");
			break;
	}
	
	return 0;
}
void crSCLL()
{
	int i;
	struct node *temp, *first;
	START = (struct node*)malloc(sizeof(struct node));
	printf("Enter no. of nodes : ");scanf("%d",&n);
	if(n >= 1)
	{
		printf("Enter data for node 1 : ");scanf("%d",&START->data);
		START->next = START;
		
		temp = START;
		for(i=2; i<=n; i++)
		{
			first = (struct node*)malloc(sizeof(struct node));
			printf("Enter data for node %d : ",i);
			scanf("%d",&first->data);
			first->next = START;
			
			temp->next = first;
			temp = first;
		}
	}
	else
	{
		printf("Invalid no. of nodes");
	}
}
void displaySCLL()
{
	struct node *temp;
	temp = START;
	while(temp->next != START)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("%d",temp->data);
}

void insSCLL()
{
	int i,pos;
	struct node *temp, *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data for new node : ");scanf("%d",&newNode->data);newNode->next=NULL;
	temp = START;
	if(START == NULL)
	{
		START=newNode;START->next=START;
	}
	else
	{
		printf("\nEnter postion to insert node : ");scanf("%d",&pos);
		if(pos == 1)
		{
			while(temp->next != START)
			{
				temp = temp->next;
			}
			newNode->next = START;
			temp->next = newNode;
			START = newNode;
			printf("\nFinal Single CLL : \n");
			displaySCLL();
		}
		else if(pos == n)
		{
			while(temp->next != START)
			{
				temp = temp->next;
			}
			newNode->next = START;
			temp->next = newNode;
			printf("\nFinal Single CLL : \n");
			displaySCLL();
		}
		else if(pos>1 && pos<n)
		{
			for(i=1; i<pos-1; i++)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
			printf("\nFinal Single CLL : \n");
			displaySCLL();
		}
		else
		{
			printf("\n%d is invalid position\n",pos);
		}
	}
}

void delSCLL()
{
	int i,pos = 0;
	struct node *temp;
	temp = START;
	if(START == NULL)
	{
		printf("\nEmpty List.\n");
	}
	else
	{
		printf("\nEnter postion to delete node : ");scanf("%d",&pos);
		if(pos == 1)
		{
			while(temp->next != START)
			{
				temp = temp->next;
			}
			START = START->next;
			temp->next = START;
			printf("\nFinal Single CLL : \n");
			displaySCLL();
		}
		else if(pos == n)
		{
			while(temp->next->next != START)
			{
				temp = temp->next;
			}
			temp->next = START;
			printf("\nFinal Single CLL : \n");
			displaySCLL();
		}
		else if(pos>1 && pos<n)
		{
			for(i=1; i<pos-1; i++)
			{
				temp = temp->next;
			}
			temp->next = temp->next->next;
			printf("\nFinal Single CLL : \n");
			displaySCLL();
		}
		else
		{
			printf("%d is invalid position",pos);
		}
	}
}
