#include "monty.h"


/**
 * f_pop - delete and print the top of stack
 *
 * @head: the head of stack
 * @counter: line number
 *
 * Return: None
*/
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *hd;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		cleanup_and_exit(head);
	}
	hd = *head;
	*head = hd->next;
	free(hd);
}


/**
 * f_swap - adds the top two elements of the stack.
 *
 * @head: the head of stack
 * @counter: line number
 *
 * Return: no return
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	int length = 0, AX;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		cleanup_and_exit(head);
	}
	hd = *head;
	AX = hd->n;
	hd->n = hd->next->n;
	hd->next->n = AX;
}