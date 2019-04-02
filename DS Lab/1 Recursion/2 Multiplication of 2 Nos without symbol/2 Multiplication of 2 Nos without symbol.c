#include<stdio.h>
int main()
{
	int a,b,fixed;
	printf("Enter number 1 : ");
	scanf("%d",&a);
	printf("Enter number 2 : ");
	scanf("%d",&b);
	fixed=a;
	printf("Multiplication = %d",mult(a,b,fixed));
	return 0;
}
mult(int a, int b, int fix)
{
	if(b==1)
		return (a);
	else if(b==0)
		return 0;
	else
		return mult(fix+a,b-1,fix);
}
