#include<stdio.h>
int main()
{
	int a,b,fixeda,fixedb;
	printf("Enter number 1 : ");
	scanf("%d",&a);
	printf("Enter number 2 : ");
	scanf("%d",&b);
	fixeda = a;
	fixedb = b;
	if(a==0 && b==0)
		printf("Undefined");
	else
		printf("Power = %d",power(a,b,fixeda,fixedb));
	return 0;
}
power(int a, int b, int fixa, int fixb)
{
	if(fixb==0)
		return 1;
	else if(b==1)
		return a;
	else
		power(a*fixa,b-1,fixa,fixb);
}
