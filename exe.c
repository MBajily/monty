#include "monty.h"


/**
* execute - executes the operation code
*
* @stack: stack
* @counter: line number
* @file: poiner to the file
* @content: line content
*
* Return: None
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opCodeList[] = {
				{"push", f_push},
				{"pall", f_pall},
				{"pint", f_pint},
				{NULL, NULL}
				};
	unsigned int n = 0;
	char *operation;

	operation = strtok(content, " \n\t");
	if (operation && operation[0] == '#')
	{
		return (0);
	}
	bus.arg = strtok(NULL, " \n\t");
	while (opCodeList[n].opcode && operation)
	{
		if (strcmp(operation, opCodeList[n].opcode) == 0)
		{	opCodeList[n].f(stack, counter);
			return (0);
		}
		n++;
	}
	if (operation && opCodeList[n].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			counter, operation);
		cleanup_and_exit(head)
	}
	return (1);
}