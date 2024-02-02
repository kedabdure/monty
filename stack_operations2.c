#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
		stack_t *temp;

		if (*stack == NULL || (*stack)->next == NULL)
		{
				fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
				exit(EXIT_FAILURE);
		}

		temp = (*stack)->next;
		(*stack)->next = temp->next;
		if (temp->next != NULL)
				temp->next->prev = *stack;
		temp->prev = NULL;
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = temp;
}

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the instruction
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

		if (*stack == NULL || (*stack)->next == NULL)
		{
				fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
				exit(EXIT_FAILURE);
		}

		(*stack)->next->n += (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
		(*stack)->prev = NULL;
}

/**
 * nop - Doesn't do anything
 * @stack: Pointer to the stack
 * @line_number: Line number of the instruction
 */
void nop(stack_t **stack, unsigned int line_number)
{
		(void)stack;
		(void)line_number;
}
