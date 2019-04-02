#include<stdio.h>
#define MAX 10
int Queue[MAX];
int f=-1, r=-1;
int main()
{
	int n;
	printf("Enter the no. of elements in Circular Queue : ");scanf("%d",&n);
	if(n>0 && N<=MAX)
	{
		int i, choice;
		for(i=0; i<n; i++)
		{
			int x;
			printf("Enter the element %d : ",i+1);scanf("%d",&x);
			enQueue(x);
		}
		printf("\nCreated Circular Queue : ");
		displayCirQueue();
		while(1)
		{
			printf("\n\n1 -- for enqueue\n");
			printf("\n2 -- for dequeue\n");
			printf("\nEnter your choice : ");scanf("%d",&choice);
			if(choice == 1)
			{
				int x;
				printf("\nEnter the new element : ");scanf("%d",&x);
				enQueue(x);
				printf("\nCircular Queue : ");
				displayCirQueue();
			}
			else if(choice == 2)
			{
				deQueue();
				printf("\nCircular Queue : ");
				displayCirQueue();
			}
			else
				break;
		}
	}
	else
		printf("\nInvalid no. of elements\n");
	return 0;
}
void enQueue(int x)
{
	if((f==0 && r==MAX-1) || r+1==f)
	{
		printf("\nOVERFLOW\n");
	}
	else
	{
		if(r==-1)
		{
			r=f=0;
			Queue[r] = x;
		}
		else if(r==MAX-1)
		{
			r=0;
		}
		else
		{
			Queue[++r] = x;
		}
	}
}
void deQueue()
{
	if(f == -1)
		printf("\nUNDERFLOW\n");
	else
	{
		printf("\nDeleted Element : %d\n",Queue[f]);
		if(f == r)
			f = r = -1;
		else if(f == MAX-1)
			f = 0;
		else
			++f;
	}
}
void displayCirQueue()
{
	if(r==-1 && f==-1)
		printf("\nUNDERFLOW\n");
	else
	{
		if(f>r)
		{
			int i,j;
			for(i=f; i<MAX-1; i++)
				printf("%d\t",Queue[i]);
			for(j=0; j<=r; j++)
				printf("%d\t",Queue[j]);
		}
		else if(f<r)
		{
			int i;
			for(i=f; i<=r; i++)
				printf("%d\t",Queue[i]);
		}
		else
			printf("%d\t",Queue[f]);
	}
}
