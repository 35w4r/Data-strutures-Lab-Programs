#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *Queue;
int main()
{
	int choice, choice2;
	crRESQ();
	printf("\nCreated Queue : \n");
	disp();
	printf("\n\n1 -- Input Restricted DQ\n");
	printf("\n2 -- Output Restricted DQ\n");
	printf("\nEnter your choice : ");scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\n\n1 -- for Insert\n");
			printf("\n2 -- for Deletion from FRONT\n");
			printf("\n3 -- for Deletion from REAR\n");
			printf("\nEnter your choice : ");scanf("%d",&choice2);
			switch(choice2)
			{
				case 1:
					insFRONT();
					break;
				case 2:
					delFRONT();
					break;
				case 3:
					delREAR();
					break;
			}
			break;
		case 2:
			printf("\n\n1 -- for Delete\n");
			printf("\n2 -- for Insertion from FRONT\n");
			printf("\n3 -- for Insertion from REAR\n");
			printf("\nEnter your choice : ");scanf("%d",&choice2);
			switch(choice2)
			{
				case 1:
					delREAR();
					break;
				case 2:
					insFRONT();
					break;
				case 3:
					insREAR();
					break;
			}
			break;
	}
	return 0;
}
void crRESQ()
{
	int n;
	struct node *temp, *first;
	printf("Enter the no. of elements : ");scanf("%d",&n);
	if(n>0)
	{
		Queue = (struct node*)malloc(sizeof(struct node));
		printf("Enter element 1 : ");scanf("%d",&Queue->data);
		Queue->next = NULL;
		temp = Queue;
		
		int i=2;
		for(i=2; i<=n; i++)
		{
			first = (struct node*)malloc(sizeof(struct node));
			printf("Enter element %d : ",i);scanf("%d",&first->data);
			first->next = NULL;
			
			temp->next = first;
			temp = first;
		}
	}
	else
		printf("Invalid no. of nodes");
}
void disp()
{
	struct node *temp;
	if(Queue == NULL)
	{
		printf("\nEmpty Queue\n");
	}
	else
	{
		temp = Queue;
		while(temp != NULL)
		{
			printf("%d\t",temp->data);
			temp = temp->next;
		}
	}
}
void insFRONT()
{
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	printf("Enter new element : ");scanf("%d",&newNode->data);
	newNode->next = NULL;
	if(Queue == NULL)
	{
		Queue = newNode;
	}
	else
	{
		newNode->next = Queue;
		Queue = newNode;
		printf("\nQueue : \n");disp();
	}
}
void insREAR()
{
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	printf("Enter new element : ");scanf("%d",&newNode->data);
	newNode->next = NULL;
	if(Queue == NULL)
	{
		Queue = newNode;
	}
	else
	{
		struct node *temp;
		temp = Queue;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		printf("\nQueue : \n");disp();
	}
}
void delFRONT()
{
	if(Queue == NULL)
	{
		printf("\nUNDERFLOW\n");
	}
	else
	{
		struct node *temp;
		temp = Queue;
		Queue = Queue->next;
		free(temp);
		printf("\nQueue : \n");disp();
	}
}
void delREAR()
{
	if(Queue == NULL)
	{
		printf("\nUNDERFLOW\n");
	}
	else
	{
		struct node *temp;
		temp = Queue;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = NULL;
		printf("\nQueue : \n");disp();
	}
}
