#include "monty.h"


bus_t bus = {NULL, NULL, NULL, 0};


/**
* main - code interpreter
*
* @argv: file location
* @argc: arguments number
*
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *cont;
	FILE *f;
	size_t s = 0;
	ssize_t line_number = 1;
	stack_t *stack = NULL;
	unsigned int n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	bus.file = f;
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line_number > 0)
	{
		cont = NULL;
		line_number = getline(&cont, &s, f);
		bus.content = cont;
		n++;
		if (line_number > 0)
		{
			execute(cont, &stack, n, f);
		}
		free(cont);
	}
	free_stack(stack);
	fclose(f);

	return (0);
}