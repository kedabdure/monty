#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @head: Pointer to the head of the stack
 * @line_num: Line number where the operation occurs
 *
 * Return: void
 */
void push(stack_t **head, unsigned int line_num)
{
	stack_t *new;

	(void)(line_num);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = new;
	}
	*head = new;
}

/**
 * pall - Prints all elements in the stack
 * @head: Pointer to the head of the stack
 * @line_num: Line number where the operation occurs
 *
 * Return: void
 */
void pall(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	(void)(line_num);
	if (*head == NULL)
	{
		return;
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - Prints the value at the top of the stack
 * @head: Pointer to the head of the stack
 * @line_num: Line number where the operation occurs
 *
 * This function prints the integer value stored at the top of the stack.
 * If the stack is empty, it prints an error message and exits with failure.
 *
 * Return: void
 */
void pint(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * nop - Does nothing
 * @head: Pointer to the head of the stack
 * @line_num: Line number where the operation occurs
 *
 * Return: void
 */
void nop(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
    /* This function does nothing */
}

