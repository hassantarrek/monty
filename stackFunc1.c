#include "main.h"

/**
 * addToStack - Adds a node to the stack
 * @newNode: Pointer
 * @ln: Interger representing the line number of of the opcode
 */

void addToStack(stack_t **newNode, __attribute__((unused))unsigned int ln)
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
	head = *newNode;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * printStack - Adds a node to the stack
 * @stack: Pointer to a pointer
 * @lineNumber: line number
 */
void printStack(stack_t **stack, unsigned int lineNumber)
{
	stack_t *tmp;

	(void) lineNumber;
	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * popTop - Adds a node to the stack
 * @stack: Pointer to a pointer
 * @lineNumber: Interger
 */

void popTop(stack_t **stack, unsigned int lineNumber)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		moreErr(7, lineNumber);
	}
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(tmp);
}

/**
 * printTop - Prints the top node of the stack
 * @stack: Pointer to a pointer
 * @lineNumber: Interger representing the line number
 */
void printTop(stack_t **stack, unsigned int lineNumber)
{
	if (stack == NULL || *stack == NULL)
		moreErr(6, lineNumber);
	printf("%d\n", (*stack)->n);
}
