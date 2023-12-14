#include "monty.h"

/**
 * f_rotl- The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one.
 * @head: stack head pointer
 * @counter: line number
*/
void f_rotl(stack_t **head, unsigned int counter)
{
	stack_t *current = *head, *AX;
	(void)counter;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	AX = (*head)->next;
	AX->prev = NULL;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = *head;
	(*head)->next = NULL;
	(*head)->prev = current;
	(*head) = AX;
}
