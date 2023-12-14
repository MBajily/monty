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


/**
 * f_push - add new node to stack
 *
 * @head: head of stack
 * @counter: line number
 *
 * Return: None
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n, i = 0, f = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
			if (bus.arg[i] > '9' || bus.arg[i] < '0')
				f = 1;
		if (f == 1)
			fprintf(stderr, "L%d: usage: push integer\n", counter);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		cleanup_and_exit(head);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}


/**
 * f_pall - prints the current stack
 *
 * @head: the head of stack
 * @counter: null
 *
 * Return: none
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}


/**
 * f_pint - prints the top
 *
 * @head: the head of the stack
 * @counter: line number
 *
 * Return: none
 */
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		cleanup_and_exit(head);
	}
	printf("%d\n", (*head)->n);
}

