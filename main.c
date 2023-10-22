#include "main.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: count
 * @argv: list
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	freeNodes();
	return (0);
}

/**
 * createNode - Creates a node.
 * @n: Number
 * Return: SOMETHING
 */
stack_t *createNode(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		err(4);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * freeNodes - Frees nodes in the stack.
 */
void freeNodes(void)
{
	stack_t *tmp;

	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * addToQueue - Adds a node to the queue
 * @newNode: Pointer
 * @ln: line number
 */

void addToQueue(stack_t **newNode, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (newNode == NULL || *newNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *newNode;
	(*newNode)->prev = tmp;
}
