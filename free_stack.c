#include "monty.h"

/**
 * free_stack - Frees a doubly linked list
 * @stack: Head of the stack
 *
 * Description: Frees a doubly linked list.
 */
void free_stack(stack_t *stack)
{
	tabstack_t *current = stack;
	tabstack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
