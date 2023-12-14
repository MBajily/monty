#include "monty.h"

#include "monty.h"
/**
 * f_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head pointer
 * @counter: line_number
 * Return: no return
*/
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *hd;

	hd = *head;
	if (!hd)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		cleanup_and_exit(head);
	}
	if (hd->n < 0 || hd->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		cleanup_and_exit(head);
	}
	printf("%c\n", hd->n);
}
