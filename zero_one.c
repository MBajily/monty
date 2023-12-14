#include "monty.h"


/**
 * add_queue - add new node to the tail of stack
 *
 * @n: new value
 * @head: the head of stack
 *
 * Return: None
*/
void add_queue(stack_t **head, int n)
{
	stack_t *newNode, *AX;

	AX = *head;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		printf("Error\n");
	newNode->n = n;
	newNode->next = NULL;
	if (AX)
		while (AX->next)
			AX = AX->next;
	if (!AX)
	{
		*head = newNode;
		newNode->prev = NULL;
	}
	else
	{
		AX->next = newNode;
		newNode->prev = AX;
	}
}


/**
 * add_node - add node to stack
 *
 * @head: the head of stack
 * @n: new value
 *
 * Return: None
*/
void add_node(stack_t **head, int n)
{

	stack_t *newNode, *AX;

	AX = *head;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (AX)
	{
		AX->prev = newNode;
	}
	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;
	*head = newNode;
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
