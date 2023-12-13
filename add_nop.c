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
  * f_nop- do nothing
  *
  * @head: the head of stack
  * @counter: line number
  *
  * Return: none
 */
void f_nop(stack_t **head, unsigned int counter)
{
	(void) head;
	(void) counter;
}