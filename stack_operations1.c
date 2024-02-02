#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push - Push an element onto the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;

    (void)line_number;

    if (value == 0)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    
    new_node->n = value;
    new_node->prev = NULL;
    if (*stack != NULL)
        (*stack)->prev = new_node;
    new_node->next = *stack;
    *stack = new_node;
}

/**
 * pop - Pop an element from the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(temp);
}

/**
 * pint - Print the value at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the instruction
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * pall - Print all the values on the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the instruction
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    (void)line_number;

    temp = *stack;
    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
