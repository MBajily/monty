#include "monty.h"


/**
* free_stack - frees linked list
*
* @head: the head of stack
*/
void free_stack(stack_t *head)
{
	stack_t *AX;

	AX = head;
	while (head)
	{
		AX = head->next;
		free(head);
		head = AX;
	}
}
