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
	if(0<LEN<MAX && balance()==1 && (exp[0]>='a' && exp[0]<='z') || (exp[0]>='A' && exp[0]<='Z'))
	{
		int i;
		for(i=0; i<LEN; i++)
		{
			if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z'))
			{
				int val;
				printf("\nEnter the value for %c : ",exp[i]);
				scanf("%d",&val);
				push(val);
			}
			else
			{
				int v1, v2, j, powval;
				v2 = pop();top--;
				v1 = pop();top--;
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
					case '^':
						if(v2 == 0)
						{
							push(1);
						}
						else
						{
							powval = v1;
							for(j=1; j<v2; j++)
							{
								v1 = v1*powval;
							}
							push(v1);
						}
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
		printf("Invalid expression");
	}
}
preEVAL()
{
	printf("\nEnter the prefix expression : ");scanf("%s",&exp);
	LEN = strlen(exp);
	strrev(exp);
	if(0<LEN<MAX && balance()==1 && (exp[0]>='a' && exp[0]<='z') || (exp[0]>='A' && exp[0]<='Z'))
	{
		int i;
		for(i=0; i<LEN; i++)
		{
			if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z'))
			{
				int val;
				printf("\nEnter the value for %c : ",exp[i]);
				scanf("%d",&val);
				push(val);
			}
			else
			{
				int v1, v2, j, powval;
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
					case '^':
						if(v2 == 0)
						{
							push(1);
						}
						else
						{
							powval = v1;
							for(j=1; j<v2; j++)
							{
								v1 = v1*powval;
							}
							push(v1);
						}
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
		printf("Invalid expression");
	}
}
int balance()
{
	int i=0,symCount=0,varCount=0;
	for(i=0; i<LEN; i++)
	{
		if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z'))
		{
			varCount++;
		}
		else if((exp[i] == '^') || (exp[i] == '*') || (exp[i] == '/') || (exp[i] == '%') || (exp[i] == '+') || (exp[i] == '-'))
		{
			symCount++;
		}
	}
	if(varCount == symCount+1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
