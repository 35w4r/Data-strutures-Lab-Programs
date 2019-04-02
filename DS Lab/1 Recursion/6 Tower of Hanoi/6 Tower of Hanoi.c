#include<stdio.h>
int main()
{
	int n;
	printf("Enter no. of disks : ");
	scanf("%d",&n);
	toh(n, 1, 3, 2);
	return 0;
}
void toh(int n, int fromrod, int torod, int usingrod)
{
	if(n==1)
	{
		printf("%d to %d\n",fromrod,torod);
		return 1;
	}
	toh(n-1, fromrod, usingrod, torod);
	printf("%d to %d\n", fromrod, torod);
	toh(n-1, usingrod, torod, fromrod);
}
