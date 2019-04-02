#include<stdio.h>
#include<string.h>
#define MAX 50
char exp[MAX];
char s[MAX];
char res[MAX];
int top = -1;
int LEN;
int main()
{
	printf("\nEnter the infix expression : ");scanf("%s",&exp);
	LEN = strlen(exp);
	if(0<LEN<MAX)
	{
		int choice=0, i=0;
		printf("\nEntered infix expression : ");puts(exp);
		printf("\n\n1 -- for Postfix\n");
		printf("\n2 -- for Prefix\n");
		printf("\n3 -- for both Postfix and Prefix\n\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				InfixToOtherfix();
				printf("\nPostfix expression : %s",res);
				break;
			case 2:
				strrev(exp);
				for(i=0; i<LEN; i++)
				{
					if(exp[i] == ')')
						exp[i] = '(';
					else if(exp[i] == '(')
						exp[i] = ')';
				}
				InfixToOtherfix();
				printf("\nPrefix expression : %s",strrev(res));
				break;
			case 3:
				InfixToOtherfix();
				printf("\nPostfix expression : %s",res);
				strrev(exp);
				for(i=0; i<LEN; i++)
				{
					if(exp[i] == ')')
						exp[i] = '(';
					else if(exp[i] == '(')
						exp[i] = ')';
				}
				InfixToOtherfix();
				printf("\n\nPrefix expression : %s",strrev(res));
				break;
			default:
				break;
		}
	}
	else
		printf("Invalid length string");
	return 0;
}

void push(char x)
{
	if(top == MAX)
	{
		printf("\nSTACK OVERFLOW");
	}
	else
	{
		s[++top] = x;
	}
}

void pop()
{
	if(top == -1)
	{
		printf("\nSTACK UNDERFLOW");
	}
	else
	{
		top = top-1;
	}
}

int prior(char x)
{
	if(x == '(')
		return 0;
	if(x == '-')
		return 1;
	if(x == '+')
		return 2;
	if(x == '%')
		return 3;
	if(x == '/')
		return 4;
	if(x == '*')
		return 5;
}

void InfixToOtherfix()
{
	int i, Ri=0;
	for(i=0; i<LEN; i++)
	{
		if(exp[i] == '(')
		{
			push(exp[i]);
		}
		else if(exp[i] == ')')
		{
			while(s[top] != '(')
			{
				if(s[top] == '(')
				{
					pop();
				}
				else
				{
					res[Ri] = s[top];Ri++;
					pop();
				}
			}
			pop();
		}
		else if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z'))
		{
			res[Ri] = exp[i];Ri++;
		}
		else
		{
			while(prior(s[top]) >= prior(exp[i]))
			{
				res[Ri] = s[top];Ri++;
				pop();
			}
			push(exp[i]);
		}
	}
}
