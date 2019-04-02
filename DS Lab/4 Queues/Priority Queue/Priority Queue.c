#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int prior;
	struct node *next;
};
struct node *PrQueue;
int main()
{
	int i,n,d,pr, choice;
	printf("Enter no. of elements : ");scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		printf("\nEnter the data : ");scanf("%d",&d);
		printf("\nEnter priority : ");scanf("%d",&pr);
		insprQ(d,pr);
	}
	printf("\nCreated Priority Queue : ");
	disp();
	printf("\n\n1 -- Insertion\n");
	printf("\n2 -- Deletion\n");
	printf("\nEnter your choice : ");scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\nEnter the data : ");scanf("%d",&d);
			printf("\nEnter priority : ");scanf("%d",&pr);
			insprQ(d,pr);
			printf("\nQueue : ");disp();
			break;
		case 2:
			delprQ();
			printf("\nQueue : ");disp();
			break;
	}
	return 0;
}
void insprQ(int d, int pr)
{
	struct node *newNode, *temp, *temp2;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = d;newNode->prior = pr;
	if(PrQueue==NULL || pr < PrQueue->prior)
	{
		newNode->next = PrQueue;
		PrQueue = newNode;
	}
	else
	{
		temp2 = PrQueue;
		while(temp2->next != NULL && PrQueue->next->prior <= pr)
		{
			temp2 = temp2->next;
		}
		newNode->next = temp2->next;
		temp2->next = newNode;
	}
}
void disp()
{
	if(PrQueue == NULL)
	{
		printf("\nEmpty Queue\n");
	}
	else
	{
		struct node *temp;
		temp = PrQueue;
		while(temp != NULL)
		{
			printf("%d\t",temp->data);
			temp = temp->next;
		}
	}
}
void delprQ()
{
	if(PrQueue == NULL)
	{
		printf("\nUNDERFLOW\n");
	}
	else
	{
		struct node *temp;
		temp = PrQueue;
		PrQueue = PrQueue->next;
		free(temp);
	}
}
