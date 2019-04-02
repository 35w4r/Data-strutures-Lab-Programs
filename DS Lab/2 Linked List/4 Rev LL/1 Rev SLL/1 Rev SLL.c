#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node* START;

int main()
{
	crNodes();
	
	printf("\nCreated SLL : \n");
	displayNodes();
	
	revNodesSLL();
	
	return 0;
}

void crNodes()
{
	int n;
	printf("Enter no. of nodes : ");
	scanf("%d",&n);
	if(n>0)
	{
		struct node* first;
		struct node* temp;
		int i;
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
			temp = temp->next;
		}
	}
	else
		printf("\nInvalid no. of nodes");
}

void displayNodes()
{
	struct node* temp;
	temp = START;
	
	if(START == NULL)
		printf("No Nodes\n");
	else
	{
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp = temp->next;
		}
	}
}

void revNodesSLL()
{
	struct node *prev, *curr;
	
	if(START!=NULL)
	{
		prev = START;
		
		curr = START->next;
		START = START->next;
		
		prev->next = NULL;
		
		while(START!=NULL)
		{
			START = START->next;
			curr->next = prev;
			
			prev = curr;
			curr = START;
		}
		
		START = prev;
	}
	printf("\nReversed SLL : \n");
	displayNodes();
}
