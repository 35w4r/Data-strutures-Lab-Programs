#include<stdio.h>
int sum;
int main()
{
	int a;
	printf("Enter a number to check palindrome : ");
	scanf("%d",&a);
	palin(a);
	return 0;
}
palin(int a)
{
	if(revnum(a)==a)
		printf("%d is a palindrome.",a);
	else
		printf("%d is not a palindrome.",a);
}
revnum(int a)
{
	if(a != 0)
	{
		sum = (sum*10)+a%10;
		revnum(a/10);
	}
	return sum;
}
