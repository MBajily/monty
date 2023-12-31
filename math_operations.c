#include "monty.h"


/**
 * f_add - add the top of stack
 *
 * @head: the head of stack
 * @counter: line number
 *
 * Return: None
*/
void f_add(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		cleanup_and_exit(head);
	}
	hd = *head;
	AX = hd->n + hd->next->n;
	hd->next->n = AX;
	*head = hd->next;
	free(hd);
}


/**
 * f_sub- subtracts the top element of the stack
 * from the second top element of the stack.
 * @head: stack head pointer
 * @counter: line number
*/
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	int sub_value, nodes_count;

	hd = *head;
	for (nodes_count = 0; hd != NULL; nodes_count++)
		hd = hd->next;
	if (nodes_count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		cleanup_and_exit(head);
	}
	hd = *head;
	sub_value = hd->next->n - hd->n;
	hd->next->n = sub_value;
	*head = hd->next;
	free(hd);
}


/**
 * f_div- divides the second top element of
 * the stack by the top element of the stack.
 * @head: stack head pointer
 * @counter: line number
*/
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	int nodes_count = 0, AX;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		nodes_count++;
	}

	if (nodes_count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		cleanup_and_exit(head);
	}

	hd = *head;
	if (hd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		cleanup_and_exit(head);
	}
	AX = hd->next->n / hd->n;
	hd->next->n = AX;
	*head = hd->next;
	free(hd);
}



/**
 * f_mul - multiplies the second top element of
 * the stack with the top element of the stack.
 * @head: stack head pointer
 * @counter: line number
*/
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	int nodes_count = 0, AX;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		nodes_count++;
	}
	if (nodes_count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		cleanup_and_exit(head);
	}
	hd = *head;
	AX = hd->next->n * hd->n;
	hd->next->n = AX;
	*head = hd->next;
	free(hd);
}


/**
 * f_mod - computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @head: stack head pointer
 * @counter: line number
*/
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	int len = 0, AX;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		cleanup_and_exit(head);
	}

	hd = *head;
	if (hd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		cleanup_and_exit(head);
	}

	AX = hd->next->n % hd->n;
	hd->next->n = AX;
	*head = hd->next;
	free(hd);
}


