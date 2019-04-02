#include<stdio.h>
#include<stdlib.h>

struct node{
	int coef;
	int power;
	struct node *next;
};
struct node *pol1, *pol2, *polSR, *polDR;
int n1, n2;

int main()
{
	int choice;
	crSLLs();
	sortSLL(pol1, n1);
	sortSLL(pol2, n2);
	
	displaySLLs();
	printf("\n\nEnter 1 -- for Addition of Polynomials.\n");
	printf("\nEnter 2 -- for Subtraction of Polynomials.\n");
	printf("\nEnter 3 -- for both Addition and Subtraction of Polynomials.\n\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			displaySumPol();
			displaytempSR();
			break;
		case 2:
			displayDiffPol();
			displaytempDR();
			break;
		case 3:
			displaySumPol();
			displaytempSR();
			displayDiffPol();
			displaytempDR();
			break;
		default:
			printf("Invalid choice.");
	}
	return 0;
}

void crSLLs()
{
	int i, count1 = 0, count2 = 0;
	struct node *temp1, *temp2, *first1, *first2;
	pol1 = (struct node*)malloc(sizeof(struct node));
	pol2 = (struct node*)malloc(sizeof(struct node));
	printf("Enter no. of terms in polynomial 1 : ");
	scanf("%d",&n1);
	printf("Enter no. of terms in polynomial 2 : ");
	scanf("%d",&n2);
	if(n1>=1 && n2>=1)
	{
		printf("Enter the 1st co-efficient of polynomial 1 : ");
		scanf("%d",&pol1->coef);
		printf("Enter the 1st co-efficient power of polynomial 1 : ");
		scanf("%d",&pol1->power);
		int check1 = pol1->power;
		pol1->next = NULL;
		
		temp1 = pol1;
		for(i=2; i<=n1; i++)
		{
			count1++;
			first1 = (struct node*)malloc(sizeof(struct node));
			printf("Enter the %dst co-efficient of polynomial 1 : ",i);
			scanf("%d",&first1->coef);
			printf("Enter the %dst co-efficient power of polynomial 1 : ",i);
			scanf("%d",&first1->power);
			if(check1 == first1->power)
			{
				first1->coef = 0;
				first1->power = 0;
				n1 = count1;
				printf("\n\nSame exponents are assigning. Therefore, ending upto %d nodes.\n",count1);
				break;
			}
			else
			{
				check1 = first1->power;
			}
			first1->next = NULL;
			
			temp1->next = first1;
			temp1 = first1;
		}
		
		printf("Enter the 1st co-efficient of polynomial 2 : ");
		scanf("%d",&pol2->coef);
		printf("Enter the 1st co-efficient power of polynomial 2 : ");
		scanf("%d",&pol2->power);
		int check2 = pol2->power;
		pol2->next = NULL;
		
		temp2 = pol2;
		for(i=2; i<=n2; i++)
		{
			count2++;
			first2 = (struct node*)malloc(sizeof(struct node));
			printf("Enter the %dst co-efficient of polynomial 2 : ",i);
			scanf("%d",&first2->coef);
			printf("Enter the %dst co-efficient power of polynomial 2 : ",i);
			scanf("%d",&first2->power);
			if(check2 == first2->power)
			{
				first2->coef = 0;
				first2->power = 0;
				n2 = count2;
				printf("\n\nSame exponents are assigning. Therefore, ending upto %d nodes.\n",count2);
				break;
			}
			else
			{
				check2 = first2->power;
			}
			first2->next = NULL;
			
			temp2->next = first2;
			temp2 = first2;
		}
	}
	else
	{
		printf("Invalid Assigning");
	}
}

void displaySLLs()
{
	struct node *temp1, *temp2;
	temp1 = pol1;
	temp2 = pol2;
	printf("\n\nPolynomial 1 : \n\n\t");
	while(temp1 != NULL)
	{
		printf(" + %dx^%d",temp1->coef,temp1->power);
		temp1 = temp1->next;
	}
	printf("\n\nPolynomial 2 : \n\n\t");
	while(temp2 != NULL)
	{
		printf(" + %dx^%d",temp2->coef,temp2->power);
		temp2 = temp2->next;
	}
}

void sortSLL(struct node* start, int n)
{
	int tcp1, tcp2, i;
	struct node *t1, *t2;
	t1 = start;
	t2 = start;
	for(i=1; i<=n; i++)
	{
		t1 = t2;
		while(t1->next != NULL)
		{
			if(t1->power > t1->next->power)
			{
				tcp1 = t1->power;
				tcp2 = t1->coef;
				
				t1->power = t1->next->power;
				t1->coef = t1->next->coef;
				
				t1->next->power = tcp1;
				t1->next->coef = tcp2;
			}
			t1 = t1->next;
		}
	}
}

void displaySumPol()
{
	polSR = (struct node*)malloc(sizeof(struct node));
	polSR->coef = 0; polSR->power = 0; polSR->next = NULL;
	
	struct node *temp1, *temp2, *tempSR;
	temp1 = pol1; temp2 = pol2; tempSR = polSR;
	
	while(temp1 && temp2)
	{
		struct node *first;
		first = (struct node*)malloc(sizeof(struct node));
		if(temp1->power > temp2->power)
		{
			first->power = temp2->power;
			first->coef = temp2->coef;
			temp2 = temp2->next;
		}
		else if(temp1->power < temp2->power)
		{
			first->power = temp1->power;
			first->coef = temp1->coef;
			temp1 = temp1->next;
		}
		else
		{
			first->power = temp1->power;
			first->coef = (temp1->coef) + (temp2->coef);
			temp1 = temp1->next;temp2 = temp2->next;
		}
		first->next = NULL;
		tempSR->next = first;
		tempSR = first;
	}
	while(temp1 || temp2)
	{
		struct node *first2;
		first2 = (struct node*)malloc(sizeof(struct node));
		if(temp1 != NULL)
		{
			first2->power = temp1->power;
			first2->coef = temp1->coef;
			temp1 = temp1->next;
		}
		if(temp2 != NULL)
		{
			first2->power = temp2->power;
			first2->coef = temp2->coef;
			temp2 = temp2->next;
		}
		first2->next = NULL;
		tempSR->next = first2;
		tempSR = first2;
	}
}

void displaytempSR()
{
	struct node *temp;
	temp = polSR;
	temp = temp->next;
	printf("\n\nAddition of Polynomials : \n\n\t");
	while(temp != NULL)
	{
		printf(" + %dx^%d",temp->coef,temp->power);
		temp = temp->next;
	}
}

void displayDiffPol()
{
	polDR = (struct node*)malloc(sizeof(struct node));
	polDR->coef = 0; polDR->power = 0; polDR->next = NULL;
	
	struct node *temp1, *temp2, *tempDR;
	temp1 = pol1; temp2 = pol2; tempDR = polDR;
	
	while(temp1 && temp2)
	{
		struct node *first;
		first = (struct node*)malloc(sizeof(struct node));
		if(temp1->power > temp2->power)
		{
			first->power = temp2->power;
			first->coef = -(temp2->coef);
			temp2 = temp2->next;
		}
		else if(temp1->power < temp2->power)
		{
			first->power = temp1->power;
			first->coef = temp1->coef;
			temp1 = temp1->next;
		}
		else
		{
			first->power = temp1->power;
			first->coef = (temp1->coef) - (temp2->coef);
			temp1 = temp1->next;temp2 = temp2->next;
		}
		first->next = NULL;
		tempDR->next = first;
		tempDR = first;
	}
	while(temp1 || temp2)
	{
		struct node *first2;
		first2 = (struct node*)malloc(sizeof(struct node));
		if(temp1 != NULL)
		{
			first2->power = temp1->power;
			first2->coef = temp1->coef;
			temp1 = temp1->next;
		}
		if(temp2 != NULL)
		{
			first2->power = temp2->power;
			first2->coef = -(temp2->coef);
			temp2 = temp2->next;
		}
		first2->next = NULL;
		tempDR->next = first2;
		tempDR = first2;
	}
}

void displaytempDR()
{
	struct node *temp;
	temp = polDR;
	temp = temp->next;
	printf("\n\nSubtraction of Polynomials : \n\n\t");
	while(temp != NULL)
	{
		printf(" + %dx^%d",temp->coef,temp->power);
		temp = temp->next;
	}
}
