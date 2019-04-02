#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int data;
	struct node *right;
};
struct node *ROOT;
int main()
{
	ROOT = insert(ROOT,2);
	insert(ROOT,1);
	insert(ROOT,4);
	insert(ROOT,3);
	insert(ROOT,5);
	InOrder(ROOT);
	printf("\nCount : ");
	printf("%d",nodeCount(ROOT));
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
		return newNode(x);
	}
	else if(x < root->data)
	{
		root->left = insert(root->left, x);
		return root;
	}
	else if(x > root->data)
	{
		root->right = insert(root->right, x);
		return root;
	}
	else
	{
		return root;
	}
}
InOrder(struct node *root)
{
	if(root == NULL)
	{
		return root;
	}
	InOrder(root->left);
	printf("%d\t",root->data);
	InOrder(root->right);
}
nodeCount(struct node *root)
{
	int nodeC = 1;
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		nodeC = nodeC + nodeCount(root->left);
		nodeC = nodeC + nodeCount(root->right);
		return nodeC;
	}
}
