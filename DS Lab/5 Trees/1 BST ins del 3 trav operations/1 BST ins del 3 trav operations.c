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
	int n;
	printf("Enter no. of elements to be inserted in BST : ");scanf("%d",&n);
	if(n>1)
	{
		int x;
		printf("\nEnter element 1 : ");scanf("%d",&x);
		ROOT = insert(ROOT,x);
		int i;
		for(i=2; i<=n; i++)
		{
			printf("\nEnter element %d : ",i);scanf("%d",&x);
			insert(ROOT,x);
		}
		int choice;
		printf("\n\n1 -- for inserting new element\n");
		printf("\n2 -- for deleting an element\n");
		printf("\n3 -- for In-Order Traversal\n");
		printf("\n4 -- for Pre-Order Traversal\n");
		printf("\n5 -- for Post-Order Traversal\n");
		printf("\nEnter your choice : ");scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nInsertion : ");
				printf("\nEnter new element : ");scanf("%d",&x);
				insert(ROOT,x);
				INOrder(ROOT);
				break;
			case 2:
				printf("\nDeletion : ");
				printf("\nEnter element to be deleted : ");scanf("%d",&x);
				deleteElement(ROOT,x);
				INOrder(ROOT);
				break;
			case 3:
				printf("\nIn-Order : ");
				INOrder(ROOT);
				break;
			case 4:
				printf("\nPre-Order : ");
				PREOrder(ROOT);
				break;
			case 5:
				printf("\nPost-Order : ");
				POSTOrder(ROOT);
				break;
			default:
				printf("\nInvalid choice");
				break;
		}
	}
	else
	{
		printf("\nInvalid no. of elements\n");
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
insert(struct node* root, int data)
{
    if (root == NULL)
	{
		return newNode(data);
	}

    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);   
 
    return root;
}
deleteElement(struct node *root, int x)
{
	if(root == NULL)
		return root;
	else if(x < root->data)
	{
		root->left = deleteElement(root->left, x);
	}
	else if(x > root->data)
	{
		root->right = deleteElement(root->right, x);
	}
	else if(x == root->data)
	{
		if(root->left == NULL)
		{
			struct node *freeTemp = root;
			root = root->left;
			free(freeTemp);
			return root;
		}
		else if(root->right == NULL)
		{
			struct node *freeTemp = root;
			root = root->right;
			free(freeTemp);
			return root;
		}
		else
		{
			struct node *temp = leastValue(root->right);
			root->data = temp->data;
			root->right = deleteElement(root->right, temp->data);
			return root;
		}
	}
}
leastValue(struct node *root)
{
	struct node *least = root;
	while(least->left != NULL)
	{
		least = least->left;
	}
	return least;
}
INOrder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	INOrder(root->left);
	printf("%d\t",root->data);
	INOrder(root->right);
}
PREOrder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%d\t",root->data);
	PREOrder(root->left);
	PREOrder(root->right);
}
POSTOrder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	POSTOrder(root->left);
	POSTOrder(root->right);
	printf("%d\t",root->data);
}
