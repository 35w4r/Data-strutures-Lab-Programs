#include<stdio.h>
#define MAX 10
int arr[MAX], top = -1;

int main()
{
	int i,n,x;
	printf("Enter no. of elements in STACK (MAX 10) : ");scanf("%d",&n);
	if(n>=1 && n<=MAX)
	{
		for(i=0; i<n; i++)
		{
			printf("Enter data for element %d : ",i+1);scanf("%d",&x);
			push(x);
		}
		printf("\nCreated STACK : \n");
		displaySTACK();
		printf("\nModified STACK : \n");
		revSTACK();
	}
	else
	{
		printf("\nInvalid no. of nodes.");
	}
	return 0;
}

void push(int x)
{
	if(top == MAX)
	{
		printf("\nSTACK OVERFLOW\n");
	}
	else
	{
		arr[++top] = x;
	}
}

void displaySTACK()
{
	if(top == -1)
	{
		printf("\nEmpty STACK\n");
	}
	else
	{
		int i;
		for(i=top; i>=0; i--)
		{
			printf("%d\n",arr[i]);
		}
	}
}

void revSTACK()
{
	if(top == -1)
	{
		printf("\nEmpty STACK\n");
	}
	else
	{
		int i, j, temp;
		j = top;
		for(i=0; i<=j; i++)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			j--;
		}
		displaySTACK();
	}
}
