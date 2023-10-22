#include "main.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer
 * @lineNumber: Interger representing the line number of of the opcode
 */

void nop(stack_t **stack, unsigned int lineNumber)
{
	(void)stack;
	(void)lineNumber;
}

/**
 * swapNodes - Swaps the top two elements
 * @stack: Pointer to a pointer
 * @lineNumber: Integer
 */

void swapNodes(stack_t **stack, unsigned int lineNumber)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		moreErr(8, lineNumber, "swap");
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
	{
		tmp->next->prev = *stack;
	}
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * addNodes - Adds the top two elements
 * @stack: Pointer to a pointer
 * @lineNumber: Integer
 */

void addNodes(stack_t **stack, unsigned int lineNumber)
{
	int x;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		moreErr(8, lineNumber, "add");
	}

	(*stack) = (*stack)->next;
	x = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = x;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * subNodes - Adds the top two elements
 * @stack: Pointerrrr
 * @lineNumber: Integerrrr
 */

void subNodes(stack_t **stack, unsigned int lineNumber)
{
	int x;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		moreErr(8, lineNumber, "sub");
	}
	(*stack) = (*stack)->next;
	x = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = x;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divNodes - Addsa thing
 * @stack: Pointer to a pointer
 * @lineNumber: Intergererererererer
 */

void divNodes(stack_t **stack, unsigned int lineNumber)
{
	int x;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		moreErr(8, lineNumber, "div");
	}
	if ((*stack)->n == 0)
	{
		moreErr(9, lineNumber);
	}
	(*stack) = (*stack)->next;
	x = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = x;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
