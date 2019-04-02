#include<stdio.h>
#define MAX 10
int TOP = -1;
int arr[MAX];

int main()
{
	int i,n,choice;
	printf("Enter no. of elements in STACK : ");scanf("%d",&n);
	if(n>=1)
	{
		for(i=0; i<n; i++)
		{
			int x;
			printf("Enter data for element %d : ",i+1);scanf("%d",&x);
			push(x);
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
				if(TOP == MAX)
				{
					printf("\nSTACK OVERFLOW\n");
				}
				else
				{
					int NewData;
					printf("Enter new data : ");scanf("%d",&NewData);
					push(NewData);
					printf("\nModified STACK : \n");
					displaySTACK();
				}
			}
			else if(choice == 2)
			{
				if(TOP == -1)
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
				if(TOP == -1)
				{
					printf("\nSTACK UNDERFLOW\n");
				}
				else
				{
					peek();
				}
			}
			else
			{
				printf("Closed");
				break;
			}
		}
	}
	else
	{
		printf("\nInvalid no. of elements");
	}
}

void push(int x)
{
	if(TOP == MAX)
	{
		printf("\nSTACK OVERFLOW");
	}
	else
	{
		arr[++TOP] = x;
	}
}

void displaySTACK()
{
	if(TOP == -1)
	{
		printf("\nSTACK UNDERFLOW");
	}
	else
	{
		int i = TOP;
		for(i=TOP; i>=0; i--)
		{
			//printf("\n|__%d__|",arr[i]);
			printf("%d\n",arr[i]);
		}
	}
}

void pop()
{
	printf("\n\nDeleted Element : %d\n",arr[TOP]);
	--TOP;
}

void peek()
{
	printf("\nTop Element : %d\n",arr[TOP]);
}
