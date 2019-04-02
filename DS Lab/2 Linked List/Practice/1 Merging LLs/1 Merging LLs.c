#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*START1, *START2, *MERGED;
int n1, n2;

int main()
{
	printf("Enter no. of nodes for List 1 : ");scanf("%d",&n1);
	printf("Enter no. of nodes for List 2 : ");scanf("%d",&n2);
	cr2SLLs();
	display2SLLs();
	mergeLLs();
	displayM();
	return 0;
}

void cr2SLLs()
{
	int i;
	struct node *temp1, *first1;
	struct node *temp2, *first2;
	if(n1>0)
	{
		START1 = (struct node*)malloc(sizeof(struct node));
		printf("Enter data for List 1 Node 1 : ");scanf("%d",&START1->data);
		START1->next = NULL;
		
		temp1 = START1;
		for(i=2; i<=n1; i++)
		{
			first1 = (struct node*)malloc(sizeof(struct node));
			printf("Enter data for List 1 Node %d : ",i);scanf("%d",&first1->data);
			first1->next = NULL;
			
			temp1->next = first1;
			temp1 = first1;
		}
		
	}
	if(n2>0)
	{
		START2 = (struct node*)malloc(sizeof(struct node));
		printf("Enter data for List 2 Node 1 : ");scanf("%d",&START2->data);
		START2->next = NULL;
		
		temp2 = START2;
		for(i=2; i<=n2; i++)
		{
			first2 = (struct node*)malloc(sizeof(struct node));
			printf("Enter data for List 2 Node %d : ",i);scanf("%d",&first2->data);
			first2->next = NULL;
			
			temp2->next = first2;
			temp2 = first2;
		}
		temp1->next = START2;		
	}
	else
		printf("\nInvalid no. of nodes");
}

void display2SLLs()
{
	struct node *temp1, *temp2;
	temp1 = START1; temp2 = START2;
	printf("\nCreated List 1 : \n");
	while(temp1 != NULL)
	{
		printf("%d\t",temp1->data);temp1 = temp1->next;
	}
	printf("\nCreated List 2 : \n");
	while(temp2 != NULL)
	{
		printf("%d\t",temp2->data);temp2 = temp2->next;
	}
}

void mergeLLs()
{
	int i;
	if((n1+n2)>0)
	{
		MERGED = START1;
	}
}

void displayM()
{
	struct node *temp;
	temp = MERGED;
	printf("\nMerged List : \n");
	while(temp != NULL)
	{
		printf("%d\t",temp->data);temp = temp->next;
	}
}
