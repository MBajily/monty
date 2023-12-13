#include "monty.h"


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
void zero_push(stack_t **head, unsigned int counter)
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
void zero_pall(stack_t **head, unsigned int counter)
{
    stack_t *h;
    (void)counter;

    h = *head;
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
void one_pint(stack_t **head, unsigned int counter)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
        cleanup_and_exit(head);
    }
    printf("%d\n", (*head)->n);
}