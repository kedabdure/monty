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
		fprintf(stderr, "L%u: can't pint, stack empty", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%u\n", (*head)->n);
}
