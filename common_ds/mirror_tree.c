/* mirror a tree in C */
/* Author Angelo Poerio <angelo.poerio@gmail.com> */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node *left, *right;
};

struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

int max(int a, int b) {
	if(a > b)
		return a;
	return b;
}

int height(struct node *root) {
	if(root == NULL)
		return 0;
	
	return 1 + max(height(root->left), height(root->right));
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	return node;
}

void printLevel(struct node *root, int level) {
	if(root == NULL)
		return;

	if(level == 1) {
		printf("%d ", root->key);
	}

	else {
		printLevel(root->left, level - 1);
		printLevel(root->right, level - 1);
	}
}

void printTree(struct node *root) {
	int h = height(root), i;
	for(i = 1; i <= h;i++) {
		printLevel(root, i);
		printf("\n");
	}
}

struct node *mirror(struct node *root) {
	struct node *tmp;
	if(root == NULL)
		return root;

	tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	root->left = mirror(root->left);
	root->right = mirror(root->right);
	return root;

}

int main()
{
	struct node *root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);
	printf("Tree:\n");
	printTree(root);
	printf("Mirrored tree:\n");
	root = mirror(root);
	printTree(root);
	return 0;
}

