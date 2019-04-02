#include<stdio.h>
#include<string.h>
#define MAX 10
char exp[MAX];
char s[MAX];
int top = -1, n;
int main()
{
	int i,checkLEN;
	printf("Enter the length of the expression : ");scanf("%d",&n);
	if(n>0 && n<MAX)
	{
		printf("\nEnter the expression for checking nesting of paranthesis : ");
		scanf("%s",exp);
		checkLEN = strlen(exp);
		if(n == strlen(exp))
		{
			printf("\nEntered expression : ");
			puts(exp);//printf("%s",exp);
			checkEquation();
		}
		else
			printf("Invalid length string");
	}
	else
	{
		printf("Invalid no. of elements");
	}	
}

checkEquation()
{
	int i;
	for(i=0; i<n; i++)
	{
		if(exp[i]=='{' || exp[i]=='(' || exp[i]=='[')
		{
			push(exp[i]);
		}
		else if(exp[i] == '}')
		{
			if(s[top] == '{')
			{
				pop();
			}
			else
			{
				puts("\nExpression is not balanced");
			}
		}
		else if(exp[i] == ')')
		{
			if(s[top] == '(')
			{
				pop();
			}
			else
			{
				puts("\nExpression is not balanced");
			}
		}
		else if(exp[i] == ']')
		{
			if(s[top] == '[')
			{
				pop();
			}
			else
			{
				puts("\nExpression is not balanced");
			}
		}
	}
	if(top == -1)
		puts("\nExpression is balanced");
	else
		puts("\nExpression is not balanced");
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
