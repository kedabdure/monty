#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @stack: head of the stack
 */
void free_stack(stack_t *stack)
{
    stack_t *current = stack;
    stack_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
