#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*f,*r;
struct node *temp, *fCopy;
int main()
{
	crQueue();
	while(1)
	{
		int choice;
		printf("\n\n1 -- for Enqueue\n");
		printf("2 -- for Dequeue\n");
		printf("Enter your choice : ");scanf("%d",&choice);
		if(choice == 1)
		{
			int val;
			printf("Enter the data for the new element : ");scanf("%d",&val);
			enQueue(val);
		}
		else if(choice == 2)
			deQueue();
		else
			break;
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
void enQueue(int val)
{
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
		r = NULL;
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
