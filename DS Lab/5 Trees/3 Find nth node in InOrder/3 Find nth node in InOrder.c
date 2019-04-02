#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int data;
	struct node *right;
};
struct node *ROOT;
int nthCount = 0;
int main()
{
	ROOT = insert(ROOT,2);
	insert(ROOT,1);
	insert(ROOT,4);
	insert(ROOT,3);
	insert(ROOT,5);
	InOrder(ROOT);
	int n;
	printf("\nEnter the nth node : ");scanf("%d",&n);
	if(1<=n<=5)
	{
		printf("\n%d node : %d",n,nthNode);
	}
	else
	{
		printf("\nInvalid value of n.");
	}
	return 0;
}
newNode(int x)
{
	struct node *t;
	t = (struct node*)malloc(sizeof(struct node));
	t->data = x;
	t->left = NULL;
	t->right = NULL;
	return t;
}
insert(struct node *root, int x)
{
	if(root == NULL)
	{
		return insert(root, x)
	}
	else
	{
		if(x < root->data)
		{
			root->left = insert(root->left,x);
			return root;
		}
		else if(x > root->data)
		{
			root->right = insert(root->right,x);
			return root;
		}
		else
		{
			return root;
		}
	}
}
nthInOrder(struct node *root, int n)
{
	if(root == NULL)
	{
		return root;
	}
	nthInOrder(root->left);
	nthCount++;
	if(n == nthCount)
	{
		printf("%d",);
	}
}
