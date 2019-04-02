#include<stdio.h>
int main()
{
	int a, b;
	printf("Enter number 1 : ");
	scanf("%d",&a);
	printf("Enter number 2 : ");
	scanf("%d",&b);
	printf("GCD = %d",gcd(a,b));
	return 0;
}
gcd(int a, int b)
{
	if(b%a==0)
		return a;
	else
		return gcd(b%a,a);
}
