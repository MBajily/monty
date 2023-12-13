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