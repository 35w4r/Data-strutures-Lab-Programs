#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*f,*r;
struct node *temp, *fCopy;
int main()
{
	int choice, val;
	crQueue();
	printf("\n\n1 -- for Enqueue\n");
	printf("2 -- for Dequeue\n");
	printf("Enter your choice : ");scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			enQueue();
			break;
		case 2:
			deQueue();
			break;
		default:
			printf("Invalid Choice");
	}
	return 0;
}
void crQueue()
{
	int i,n;
	printf("Enter the no. of elements in queue : ");scanf("%d",&n);
	if(n>0)
	{
		struct node *t1,*first;
		r = (struct node*)malloc(sizeof(struct node));
		printf("Enter the data for element 1 : ");scanf("%d",&r->data);
		r->next = NULL;
		t1 = r;
		f = r;
		for(i=2; i<=n; i++)
		{
			first = (struct node*)malloc(sizeof(struct node));
			printf("Enter the data for element %d : ",i);scanf("%d",&first->data);
			first->next = NULL;
			r->next = first;
			
			r = first;
		}
		displayQueue();
	}
	else
	{
		printf("Invalid no. of elements");
	}
}
void enQueue()
{
	int val;
	printf("Enter the data to enqueue : ");scanf("%d",&val);
	if(r == NULL)
	{
		r = (struct node*)malloc(sizeof(struct node));
		r->data = val;
		r->next = NULL;
		f = r;
		displayQueue();
	}
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = val;
		temp->next = NULL;
		r->next = temp;
		r = temp;
		displayQueue();
	}
}
void deQueue()
{
	fCopy = f;
	if(fCopy == NULL)
	{
		printf("Empty Queue\n");
	}
	else
	{
		printf("Deleted Element : %d",f->data);
		f = f->next;
		displayQueue();
	}
}
void displayQueue()
{
	struct node *trav;
	trav = f;
	printf("\nQueue : \n");
	while(trav != NULL)
	{
		printf("%d\t",trav->data);
		trav = trav->next;
	}
}
