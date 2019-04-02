#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int EleCount = -1;
struct node{
	int data;
	struct node *next;
};
struct node *TOP;

int main()
{
	int i,n,x,choice;
	printf("Enter no. of elements in STACK (MAX 10): ");scanf("%d",&n);
	if(n>=1 && n<=MAX)
	{
		for(i=0; i<n; i++)
		{
			printf("Enter the data for element %d : ",i+1);scanf("%d",&x);
			push(x);
			EleCount++;
		}
		printf("\nCreated STACK : \n");
		displaySTACK();
		
		while(1)
		{
			printf("\n\n1 -- for push\n");
			printf("\n2 -- for pop\n");
			printf("\n3 -- for peek\n");
			printf("Enter your choice : ");scanf("%d",&choice);
			if(choice == 1)
			{
				if(EleCount == MAX)
				{
					printf("\nSTACK OVERFLOW\n");
				}
				else
				{
					int newEle;
					printf("\nEnter data for new element : ");scanf("%d",&newEle);
					push(newEle);
					printf("\nModified STACK : \n");
					displaySTACK();
				}
			}
			else if(choice == 2)
			{
				if(EleCount == -1)
				{
					printf("\nSTACK UNDERFLOW\n");
				}
				else
				{
					pop();
					printf("\nModified STACK : \n");
					displaySTACK();
				}
			}
			else if(choice == 3)
			{
				if(EleCount == -1)
				{
					printf("\nSTACK UNDERFLOW\n");
				}
				else
				{
					peek();
				}
			}
		}
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
	temp->data = x;// temp->next = NULL;
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
	else if(EleCount == MAX)
	{
		printf("\nSTACK OVERFLOW\n");
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
	--EleCount;
}

void peek()
{
	printf("\nTop Element : %d\n",TOP->data);
}
