#include<stdio.h>
#include<string.h>
#define MAX 50
char exp[MAX];
int s[MAX];
int top = -1;
int LEN;
int main()
{
	int choice;
	printf("\n\nEnter the choice of expression : \n");
	printf("\n1 -- for Postfix Evaluation\n");
	printf("\n2 -- for Prefix Evaluation\n");
	printf("\nEnter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			postEVAL();
			break;
		case 2:
			preEVAL();
			break;
		default:
			printf("Invalid choice");
	}
	return 0;
}
void push(int x)
{
	if(top == MAX)
	{
		printf("STACK OVERFLOW");
	}
	else
	{
		s[++top] = x;
	}
}
int pop()
{
	if(top == -1)
	{
		printf("STACK UNDERFLOW");
	}
	else
	{
		return s[top];
	}
}
postEVAL()
{
	printf("\nEnter the postfix expression : ");scanf("%s",&exp);
	LEN = strlen(exp);
	if(0<LEN<MAX)
	{
		int i;
		for(i=0; i<LEN; i++)
		{
			if(isdigit(exp[i]))
			{
				push(exp[i]-'0');
			}
			else
			{
				int v1, v2;
				v1 = pop();top--;
				v2 = pop();top--;
				switch(exp[i])
				{
					case '+':
						push(v1+v2);
						break;
					case '-':
						push(v1-v2);
						break;
					case '*':
						push(v1*v2);
						break;
					case '/':
						push(v1/v2);
						break;
					case '%':
						push(v1%v2);
						break;
					default:
						printf("Invalid Character");
				}
			}
		}
		printf("Evaluated postfix expression : ");
		for(i=0; i<top+1; i++)
		{
			printf("%d",s[i]);
		}
	}
	else
	{
		printf("Invalid length string");
	}
}
preEVAL()
{
	printf("\nEnter the prefix expression : ");scanf("%s",&exp);
	LEN = strlen(exp);
	strrev(exp);
	if(0<LEN<MAX)
	{
		int i;
		for(i=0; i<LEN; i++)
		{
			if(isdigit(exp[i]))
			{
				push(exp[i]-'0');
			}
			else
			{
				int v1, v2;
				v1 = pop();top--;
				v2 = pop();top--;
				switch(exp[i])
				{
					case '+':
						push(v1+v2);
						break;
					case '-':
						push(v1-v2);
						break;
					case '*':
						push(v1*v2);
						break;
					case '/':
						push(v1/v2);
						break;
					case '%':
						push(v1%v2);
						break;
					default:
						printf("Invalid Character");
				}
			}
		}
		printf("Evaluated prefix expression : ");
		for(i=0; i<top+1; i++)
		{
			printf("%d",s[i]);
		}
	}
	else
	{
		printf("Invalid length string");
	}
}
