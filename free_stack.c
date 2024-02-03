#include "monty.h"

/**
 * free_st - free the stack linked list
 * @head: pointer to first node
 *
 * Return: void
 */
void free_st(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
