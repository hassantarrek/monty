#include "main.h"

/**
 * err - Prints appropiate error messages
 * @errorCode: The error code
 */

void err(int errorCode, ...)
{
	va_list hsn;
	char *op;
	int lNum;

	va_start(hsn, errorCode);
	switch (errorCode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(hsn, char *));
			break;
		case 3:
			lNum = va_arg(hsn, int);
			op = va_arg(hsn, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lNum, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(hsn, int));
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * moreErr - handles errors
 * @errorCode: The error code
 */

void moreErr(int errorCode, ...)
{
	va_list hsn;
	char *op;
	int lNum;

	va_start(hsn, errorCode);
	switch (errorCode)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(hsn, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(hsn, int));
			break;
		case 8:
			lNum = va_arg(hsn, unsigned int);
			op = va_arg(hsn, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", lNum, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(hsn, unsigned int));
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * stringErr - handles errors.
 * @errorCode: The error code
 */

void stringErr(int errorCode, ...)
{
	va_list hsn;
	int lNum;

	va_start(hsn, errorCode);
	lNum = va_arg(hsn, int);
	switch (errorCode)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lNum);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lNum);
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}
