#include "monty.h"
/**
 * pint - print top of the stack
 * @head: head ptr
 * @line_num: counter
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

	printf("%u\n", (*head)->n);
}
/**
 * pop - delete the top element of the stack
 * @head: head ptr
 * @line_num: counter
 *
 * Return: void
 */

void pop(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(temp);
}

/**
 * swap - swap top two elements
 * @head: head ptr
 * @line_num: counter
 *
 * Return: void
 */

void swap(stack_t **head, unsigned int line_num)
{
	stack_t *temp1, *temp2;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp1 = *head;
	temp2 = (*head)->next;
	temp1->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp1;

	temp1->prev = temp2;
	temp2->prev = NULL;
	temp2->next = temp1;
	(*head) = temp2;
}
