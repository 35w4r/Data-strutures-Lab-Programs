#include<stdio.h>
#define MAX 10
int Queue[MAX];
int r = -1,f = -1;
int main()
{
	int i,n,x,choice;
	printf("Enter the no. of elements in Queue : ");scanf("%d",&n);
	if(0<n<MAX)
	{
		for(i=0; i<n; i++)
		{
			printf("Enter the element %d : ",i+1);scanf("%d",&x);
			enQueue(x);
		}
		printf("\nCreated Queue : ");displayQueue();
		while(1)
		{
			printf("\n\n1 -- for EnQueue\n");
			printf("\n2 -- for DeQueue\n");
			printf("\nEnter your choice : ");scanf("%d",&choice);
			if(choice == 1)
			{
				printf("\nEnter the new element : ");scanf("%d",&x);
				enQueue(x);
				printf("\nQueue : ");displayQueue();
			}
			else if(choice == 2)
			{
				deQueue();
				printf("\nQueue : ");displayQueue();
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		printf("\nInvalid no. of elements\n");
	}
	return 0;
}
void enQueue(int x)
{
	if(r == MAX-1)
	{
		printf("\nSTACK OVERFLOW\n");
	}
	else if(r == -1)
	{
		Queue[++r] = x;
		f++;
	}
	else
	{
		Queue[++r] = x;
	}
}
void deQueue()
{
	if(f == -1 || f>r)
	{
		printf("\nSTACK UNDERFLOW\n");
	}
	else
	{
		printf("\nDeleted Element : %d\n",Queue[f]);
		f++;
	}
}
void displayQueue()
{
	int i;
	for(i=f; i<=r; i++)
	{
		printf("%d\t",Queue[i]);
	}
}
