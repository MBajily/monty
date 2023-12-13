#include "monty.h"


/**
 * cleanup_and_exit - Performs cleanup tasks and exits the program with a failure status.
 * @head: Pointer to the head of the stack.
 *
 * This function is responsible for performing necessary cleanup tasks before
 * exiting the program in case of an error. It closes the file, frees the memory
 * allocated for the content, and cleans up the stack by freeing all nodes.
 * It is intended to be called when an error occurs and the program needs to exit
 * gracefully.
 *
 * @head: Pointer to the head of the stack.
 */
void cleanup_and_exit(stack_t **head)
{
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
}


/**
 * f_push - add new node to stack
 * @head: head of stack
 * @counter: line number
 * Return: None
 */
void f_push(stack_t **head, unsigned int counter)
{
    int n, j = 0, flag = 0;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
            j++;
        for (; bus.arg[j] != '\0'; j++)
        {
            if (bus.arg[j] > '9' || bus.arg[j] < '0')
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            cleanup_and_exit(head);
        }
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
 * @head: the head of stack
 * @counter: null
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
 * @head: the head of the stack
 * @counter: line number
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