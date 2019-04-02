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
	
	sortDLL();
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

void sortDLL()
{
	int temp, count = 0, i = 1;
	struct node *t1, *t2;
	t1 = START;
	t2 = START;
	count = countNodeDLL();
	
	for(i=1; i<=count; i++)
	{
		t1 = t2;
		while(t1->next != NULL)
		{
			if(t1->data > t1->next->data)
			{
				temp = t1->data;
				t1->data = t1->next->data;
				t1->next->data = temp;
			}
			t1 = t1->next;
		}
	}
	displayDLL();
}
