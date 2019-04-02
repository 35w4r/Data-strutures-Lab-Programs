#include<stdio.h>
#include<stdlib.h>

struct node{
	char name[25];
	int marks;
	struct node *next;
};
struct node *START;

int main()
{
	marksDetails();
	
	crSLL();
	printf("\nResults of Students : \n");
	displaySLL();
	
	ResultsStudents();
	return 0;
}

void crSLL()
{
	int i, n;
	printf("Enter the no. of students : ");
	scanf("%d",&n);
	struct node *temp, *first;
	START = (struct node*)malloc(sizeof(struct node));
	if(n>=1)
	{
		printf("Enter the name of the student : ");
		scanf("%s",&START->name);
		printf("Enter the marks of %s : ",START->name);
		scanf("%d",&START->marks);
		START->next = NULL;
		
		temp = START;
		for(i=2; i<=n; i++)
		{
			int marks;
			first = (struct node*)malloc(sizeof(struct node));
			printf("Enter the name of the student : ");
			scanf("%s",&first->name);
			while(1)
			{
				printf("Enter the marks of %s : ",first->name);
				scanf("%d",&marks);
				if(marks>=0 && marks<=100)
				{
					first->marks = marks;
					break;
				}
				else
				{
					printf("\nInvalid Marks\n");
				}
			}
			first->next = NULL;
			
			temp->next = first;
			temp = first;
		}
	}
	else
	{
		puts("Invalid no. of students");
	}
}

void displaySLL()
{
	struct node *temp;
	temp = START;
	while(temp != NULL)
	{
		printf("\nName : %s",temp->name);
		printf("\nMarks : %d\n",temp->marks);
		temp = temp->next;
	}
}

void marksDetails()
{
	printf("Above 90 --> First Class\n\n");
}

void ResultsStudents()
{
	printf("\nFirst Class Students : \n");
	struct node *temp;
	temp = START;
	while(temp != NULL)
	{
		if(temp->marks > 90)
		{
			printf("\nName : %s",temp->name);
			printf("\nMarks : %d\n",temp->marks);
		}
		temp = temp->next;
	}
}
