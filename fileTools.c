#include "main.h"

/**
 * openFile - opens a file
 * @fileName: the file namepath
 * Return: void
 */

void openFile(char *fileName)
{
	FILE *fd = fopen(fileName, "r");

	if (fileName == NULL || fd == NULL)
		err(2, fileName);

	readFile(fd);
	fclose(fd);
}


/**
 * readFile - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void readFile(FILE *fd)
{
	int lineNumber, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (lineNumber = 1; getline(&buffer, &len, fd) != -1; lineNumber++)
	{
		format = parseLine(buffer, lineNumber, format);
	}
	free(buffer);
}


/**
 * parseLine - Separates each line into tokens
 * @buffer: line from the file
 * @lineNumber: line number
 * @format:  storage format
 * Return: Returns 0 OR 1
 */

int parseLine(char *buffer, int lineNumber, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
	{
		err(4);
	}
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
	{
		return (format);
	}
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
	{
		return (0);
	}
	if (strcmp(opcode, "queue") == 0)
	{
		return (1);
	}
	findFunc(opcode, value, lineNumber, format);
	return (format);
}

/**
 * findFunc - find the appropriate function
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format
 * @ln: line number
 * Return: void
 */

void findFunc(char *opcode, char *value, int ln, int format)
{
	int x;
	int flag;

	instruction_t func_list[] = {
		{"push", addToStack},
		{"pall", printStack},
		{"pint", printTop},
		{"pop", popTop},
		{"nop", nop},
		{"swap", swapNodes},
		{"add", addNodes},
		{"sub", subNodes},
		{"div", divNodes},
		{"mul", mulNodes},
		{"mod", modNodes},
		{"pchar", printChar},
		{"pstr", printStr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
	{
		return;
	}
	for (flag = 1, x = 0; func_list[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, func_list[x].opcode) == 0)
		{
			callFun(func_list[x].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}


/**
 * callFun - Calls the required function
 * @func: Pointer to the function
 * @op: string
 * @val: string
 * @ln: line numeber
 * @format: Format
 */
void callFun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int x;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (x = 0; val[x] != '\0'; x++)
		{
			if (isdigit(val[x]) == 0)
				err(5, ln);
		}
		node = createNode(atoi(val) * flag);
		if (format == 0)
		{
			func(&node, ln);
		}
		if (format == 1)
		{
			addToQueue(&node, ln);
		}
	}
	else
		func(&head, ln);
}
