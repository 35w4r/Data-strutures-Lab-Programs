#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *START;
int n;

int main()
{
	crSLL();
	printf("\nCreated SLL : \n");
	displaySLL();
	sortSLL();
	return 0;
}

void crSLL()
{
	int i;
	printf("Enter no. of nodes : ");
	scanf("%d",&n);
	if(n>0)
	{
		struct node *temp, *first;
		START = (struct node*)malloc(sizeof(struct node));
		printf("Enter data for node 1 : ");
		scanf("%d",&START->data);
		START->next = NULL;
		
		temp = START;
		for(i=2; i<=n; i++)
		{
			first = (struct node*)malloc(sizeof(struct node));
			printf("Enter data for node %d : ",i);
			scanf("%d",&first->data);
			first->next = NULL;
	
			temp->next = first;
			temp = first;
		}
	}
	else
		printf("\nInvalid no. of nodes.\n");
}

void displaySLL()
{
	struct node *temp;
	temp = START;
	while(temp != NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
}

void sortSLL()
{
	int i, temp;
	struct node *t1, *t2;
	t1 = START;
	t2 = START;
	
	for(i=1; i<=n; i++)
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
	printf("\nSorted SLL : \n");
	displaySLL();
}
