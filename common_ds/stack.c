// Stack ds based on a linked list 

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int value;
	struct Node *next;
};

typedef struct Node Node;

Node *push(Node *stack, int value) {
	Node *tmp = (Node *)malloc(sizeof(Node));
	if(stack != NULL) {
		tmp->value = value;
		tmp->next = stack;
		return tmp;
	}
	else {
		tmp->value = value;
		tmp->next = NULL;
		return tmp;
	}
}

Node *pop(Node *stack) {
	if(stack != NULL) {
		Node *tmp = stack->next;
		free(stack);
		return tmp;
	}
	else {
		return stack;
	}
}

void printStack(Node *stack) {
	printf("--------------\n");
	while(stack != NULL) {
		printf("%d\n",stack->value);
		stack = stack->next;
	}
	printf("--------------\n");
}

int main(int argc,char *argv[]) {
	Node *stack = push(NULL, 156);
	stack = push(stack,10);
	stack = push(stack, 7);
	printStack(stack);
	stack = pop(stack);
	printStack(stack);
	stack = pop(stack);
	stack = pop(stack);
	printStack(stack);
	stack = pop(stack);	
	stack = pop(stack);
	stack = push(stack, 678);
	printStack(stack);
}
