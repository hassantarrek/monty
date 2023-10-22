#include "main.h"

/**
 * mulNodes - Adds the top two elements
 * @stack: Pointer to a pointer
 * @lineNumber: Interger
 */

void mulNodes(stack_t **stack, unsigned int lineNumber)
{
	int x;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		moreErr(8, lineNumber, "mul");
	}
	(*stack) = (*stack)->next;
	x = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = x;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * modNodes - Adds the top two elements
 * @stack: Pointer to a pointer
 * @lineNumber: Interrr
 */

void modNodes(stack_t **stack, unsigned int lineNumber)
{
	int x;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		moreErr(8, lineNumber, "mod");
	}
	if ((*stack)->n == 0)
		moreErr(9, lineNumber);
	(*stack) = (*stack)->next;
	x = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = x;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
