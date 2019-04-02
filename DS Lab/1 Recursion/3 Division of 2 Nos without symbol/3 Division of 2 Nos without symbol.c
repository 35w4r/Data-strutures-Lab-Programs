#include<stdio.h>
int main()
{
	int a,b,diff;
	printf("Enter number 1 : ");
	scanf("%d",&a);
	printf("Enter number 2 : ");
	scanf("%d",&b);
	if(b == 0)
		printf("Undefined");
	else
	{
		printf("Quotient = %d",div(a,b,diff));
		printf("\nRemainder = %d",rem(a,b,diff));
	}
	return 0;
}
div(int a, int b, int dif)
{
	if((a==0 || a<b))
		return (dif);
	else
	{
		dif=dif+1;
		return div(a-b,b,dif);
	}
}
rem(int a, int b, int dif)
{
	if((a==0 || a<b))
		return (a);
	else
	{
		dif=dif+1;
		return rem(a-b,b,dif);
	}
}
