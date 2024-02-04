#include "monty.h"

/**
 * nop - Doesn't do anything
 * @head: Pointer to the stack
 * @line_number: Line number of the instruction
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @head: Pointer to the head of the stack (doubly linked list).
 * @line_number: Line number of the instruction.
 */
void sub(stack_t **head, unsigned int line_number)
{
	int num1, num2, result;
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
			fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
			exit(EXIT_FAILURE);
	}

	num1 = (*head)->n;
	num2 = (*head)->next->n;

	result = num2 - num1;

	temp = *head;
	*head = (*head)->next;
	free(temp);
	if (*head != NULL)
		(*head)->prev = NULL;
	(*head)->n = result;
}
/**
 * _div - divide the top element of the stack from the second top element.
 * @head: Pointer to the head of the stack (doubly linked list).
 * @line_number: Line number of the instruction.
 */
void _div(stack_t **head, unsigned int line_num)
{
	stack_t *temp1, *temp2;
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp1 = *head;
	temp2 = (*head)->next;
	temp2->n = temp2->n / (*head)->n;
	if ((*head)->next != NULL)
		*head = (*head)->next;
	free(temp1);
}

