#include<stdio.h>
#define MAX 10
int DEQueue[MAX];
int r=-1, f=-1;
int main()
{
	int i, n, choice;
	printf("Enter the no. of elements in Double Ended Queue : ");scanf("%d",&n);
	if(n>0 && n<=MAX)
	{
		for(i=1; i<=n; i++)
		{
			int x;
			printf("Enter element %d : ",i);scanf("%d",&x);
			insREAR(x);
		}
		printf("\nCreated Double Ended Queue : ");
		displayDEQueue();
		while(1)
		{
			printf("\n\n1 -- for Inserting REAR\n");
			printf("\n2 -- for Inserting FRONT\n");
			printf("\n3 -- for Deleting REAR\n");
			printf("\n4 -- for Deleting FRONT\n");
			printf("Enter your choice : ");scanf("%d",&choice);
			if(choice == 1)
			{
				int x;
				printf("Enter the new element : ");scanf("%d",&x);
				insREAR(x);
				printf("\nDouble Ended Queue : ");
				displayDEQueue();
			}
			else if(choice == 2)
			{
				int x;
				printf("Enter the new element : ");scanf("%d",&x);
				insFRONT(x);
				printf("\nDouble Ended Queue : ");
				displayDEQueue();
			}
			else if(choice == 3)
			{
				delREAR();
				printf("\nDouble Ended Queue : ");
				displayDEQueue();
			}
			else if(choice == 4)
			{
				delFRONT();
				printf("\nDouble Ended Queue : ");
				displayDEQueue();
			}
			else
				break;
		}
	}
	else
		printf("\nInvalid no. of elements\n");
	return 0;
}
void insREAR(int x)
{
	if(r == MAX-1)
		printf("\nOVERFLOW\n");
	else
	{
		r++;
		DEQueue[r] = x;
		if(f == -1)
		{
			f=0;
		}
	}
}
void insFRONT(int x)
{
	if(f<0)
	{
		printf("\nNo more space\n");
	}
	else
	{
		DEQueue[--f] = x;
	}
}
void delREAR()
{
	if(r == -1)
		printf("\nUNDERFLOW\n");
	else
	{
		printf("\nDeleted Element : %d\n",DEQueue[r]);
		if(r == f)
			r = f = -1;
		else
			r--;
	}
}
void delFRONT()
{
	if(f == -1)
		printf("\nUNDERFLOW\n");
	else
	{
		printf("\nDeleted Element : %d\n",DEQueue[f]);
		if(f == r)
			r = f = -1;
		else
			f++;
	}
}
void displayDEQueue()
{
	printf("\n||%d||\n",f);
	if(f == -1)
		printf("\nUNDERFLOW\n");
	else
	{
		int i;
		for(i=f; i<=r; i++)
		{
			printf("%d\t",DEQueue[i]);
		}
	}
}
