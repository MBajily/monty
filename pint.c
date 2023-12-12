#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;
void push(int value)
{
	if (top == STACK_SIZE - 1)
	{
		printf("Stack overflow\n");
		exit(EXIT_FAILURE);
	}
	top++;
	stack[top] = value;
}


void pall()
{
	int i;
	
	for (i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}

int main()
{
	FILE *file = fopen("input.txt", "r");
	char opcode[5];
	int argument;
	int line_number = 1;

	if (file == NULL)
	{
		printf("File not found\n");
		return (1);
	}
	while (fscanf(file, "%s %d", opcode, &argument) == 2)
	{
		if (strcmp(opcode, "push") == 0)
		{
			push(argument);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall();
		}
		else
		{
			printf("Unknown opcode at line %d\n", line_number);
			return (1);
		}
		line_number++;
	}
	fclose(file);
	return (0);
}
