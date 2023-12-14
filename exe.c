#include "monty.h"

/**
 * get_func - function takes the opcode and return
 * asocaited function
 * @opcode: the opcode
 * Return: the function pointer associated with opcode
*/
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	unsigned int n = 0;
	instruction_t opCodeList[] = {
				{"pop", f_pop},
				{"swap", f_swap},
				{"push", f_push},
				{"pall", f_pall},
				{"pint", f_pint},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{NULL, NULL}
				};

	while (opCodeList[n].opcode && opcode)
	{
		if (strcmp(opcode, opCodeList[n].opcode) == 0)
			return (opCodeList[n].f);
		n++;
	}
	return (NULL);
}


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
	void (*ptr_func)(stack_t **, unsigned int);
	char *operation;

	operation = strtok(content, " \n\t");
	if (operation && operation[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	ptr_func = get_func(operation);

	if (operation && ptr_func == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			counter, operation);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	ptr_func(stack, counter);
	return (1);
}
