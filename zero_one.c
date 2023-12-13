#include "monty.h"


/**
 * addqueue - add new node to the tail of stack
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
	{
		printf("Error\n");
	}
	newNode->n = n;
	newNode->next = NULL;
	if (AX)
	{
		while (AX->next)
			AX = AX->next;
	}
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
 * addnode - add node to stack
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
 * f_push - add new node to stack
 *
 * @head: head of stack
 * @counter: line number
 *
 * Return: None
 */
void f_push(stack_t **head, unsigned int counter)
{
    int n, j = 0, flag = 0;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
        {
            j++;
        }
        for (; bus.arg[j] != '\0'; j++)
        {
            if (bus.arg[j] > '9' || bus.arg[j] < '0')
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);

            
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        cleanup_and_exit(head);
    }
    n = atoi(bus.arg);
    if (bus.lifi == 0)
    {
        add_node(head, n);
    }
    else
    {
        add_queue(head, n);
    }
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
    {
		return;
    }

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