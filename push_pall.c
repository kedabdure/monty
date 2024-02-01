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
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->next = *head;
	new->n = value;
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		(*head)->prev = new;
		*head = new;
	}
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
		fprintf(stderr, "Error: No elements to print at line %d", line_num);
	}
	else
	{
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}

