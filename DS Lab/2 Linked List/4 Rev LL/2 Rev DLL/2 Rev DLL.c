#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *START, *END;

int main()
{
	crDLL();
	
	displayDLL();
	
	revDLL();
	return 0;
}

void crDLL()
{
	int i, n;
	struct node *first;
	START = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter the no. of nodes : ");
	scanf("%d",&n);
	START->prev = NULL;
	printf("Enter data for node 1 : ");
	scanf("%d",&START->data);
	START->next = NULL;
	
	END = START;
	for(i=2; i<=n; i++)
	{
		first = (struct node*)malloc(sizeof(struct node));
		first->prev = END;
		printf("Enter data for node %d : ", i);
		scanf("%d",&first->data);
		first->next = NULL;
		
		END->next = first;
		END = first;
	}
}

void displayDLL()
{
	struct node *temp, *temp2;
	temp = START;
	temp2 = END;
	
	printf("\nCreated DLL : \n");
	while(temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	
	printf("\nReverse DLL : \n");
	while(temp2 != NULL)
	{
		printf("%d\t", temp2->data);
		temp2 = temp2->prev;
	}
}

int countNodeDLL()
{
	int count = 0;
	struct node *temp;
	temp = START;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void revDLL()
{
	int temp, count = 0, i = 1, j = 1;
	struct node *t1, *t2;
	t1 = START;
	t2 = END;
	count = countNodeDLL();
	
	for(i=1; i<=count; i++)
	{
		for(j=1; j<=i; j++)
		{
			temp = t1->data;
			t1->data = t2->data;
			t2->data = temp;
		}
		if(count%2!=0 && i==count-1)
		{
			//displayDLL();
			t1 = t1;t2 = t2;
		}
		else
		{
			t1 = t1->next;
			t2 = t2->prev;
		}
	}
	displayDLL();
}
