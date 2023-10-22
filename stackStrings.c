#include "main.h"

/**
 * printChar - Prints the Ascii value
 * @stack: Pointer to a pointer
 * @lineNumber: Interger represnt to you mr chalie puth
 */

void printChar(stack_t **stack, unsigned int lineNumber)
{
	int x;

	if (stack == NULL || *stack == NULL)
	{
		stringErr(11, lineNumber);
	}
	x = (*stack)->n;
	if (x < 0 || x > 127)
	{
		stringErr(10, lineNumber);
	}
	printf("%c\n", x);
}

/**
 * printStr - Prints a string
 * @stack: Pointer to a pointer pointing
 * @ln: Interger representing
 */

void printStr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int x;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		x = tmp->n;
		if (x <= 0 || x > 127)
		{
			break;
		}
		printf("%c", x);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the nodes
 * @stack: Pointer
 * @ln: Interger representing the line number
 */

void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - Rotates the nodes
 * @stack: Pointer to my broken heart
 * @ln: Interger representing rata tararata
 */

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
